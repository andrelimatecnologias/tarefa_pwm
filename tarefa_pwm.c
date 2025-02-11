#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_SERVO 22

// Estas variáveis serão utilizadas com esses valores para fim de produzir uma frequência pwm de 50Hz manipulando o valor das variáveis de divisão e Wrap
const float PWM_DIV = 250.0; 
const uint16_t WRAP = 10000;

#define ROTACAO_0_GRAU 0.12 // valor que representa um ciclo ativo de 2400us
#define ROTACAO_90_GRAU 0.0735 // valor que representa um ciclo ativo de 1470us
#define ROTACAO_180_GRAU 0.025 // valor que representa um ciclo ativo de 500us

// Variável que define o tamanho do passo correspondente a um ciclo ativo de 5us
const float PASSO_ROTACAO = 0.00025;

float angulo_atual = ROTACAO_180_GRAU;

// Função que converte um valor percentual (Duty Cycle) no valor inteiro correspondente a ser utilizado na função pwm_set_gpio_level para se obter o efeito esperado
uint16_t getDutyCycle(float percentual){
    return (uint16_t) (percentual*(float) WRAP);
}

// Função que realiza as configurações necessárias para que o pino GPIO escolhido funcione com o PWM numa frequência de 50Hz
void configuracoes_iniciais(){
    gpio_set_function(PWM_SERVO, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(PWM_SERVO);
    pwm_set_clkdiv(slice, PWM_DIV);
    pwm_set_wrap(slice,WRAP);
    pwm_set_enabled(slice,true);

}

int main()
{
  
    // Essa variável será utilizada para o controle continuo e suave de rotação do servo motor. onde quando este alcançar os ângulos máximos, seu valor irá mudar, para garantir que ele continuará se movendo, em outra direção, repetindo o ciclo
    int8_t direcao = -1;

    stdio_init_all();


    configuracoes_iniciais();

    // As variáveis a seguir controlarão a posição do servo motor nas posições indicadas
    uint16_t rot_0_graus = getDutyCycle(ROTACAO_0_GRAU); // Calcula o valor necessário para obter um duty cycle de 12%, que corresponde a um valor de 2400us para o ciclo ativo
    uint16_t rot_90_graus = getDutyCycle(ROTACAO_90_GRAU); // Calcula o valor necessário para obter um duty cycle de 7,35%, que corresponde a um valor de 1470us para o ciclo ativo
    uint16_t rot_180_graus = getDutyCycle(ROTACAO_180_GRAU); // Calcula o valor necessário para obter um duty cycle de 2,5%, que corresponde a um valor de 500us para o ciclo ativo

    // Acionamento do servo em uma posição diferente a cada 5 segundos, variando entre 0, 90 e 180 graus
    pwm_set_gpio_level(PWM_SERVO,rot_0_graus);
    sleep_ms(5000);
    pwm_set_gpio_level(PWM_SERVO,rot_90_graus);
    sleep_ms(5000);
    pwm_set_gpio_level(PWM_SERVO,rot_180_graus);
    sleep_ms(5000);

    while (true) {
        uint16_t duty_cycle_atual = getDutyCycle(angulo_atual);
        if(duty_cycle_atual<rot_180_graus){
            direcao = 1;
        }else if(duty_cycle_atual>rot_0_graus){
            direcao = -1;
        }
        angulo_atual += PASSO_ROTACAO*direcao;
        pwm_set_gpio_level(PWM_SERVO,getDutyCycle(angulo_atual));
        sleep_ms(10);
    }
}
