#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_SERVO 22

// Estas variáveis serão utilizadas com esses valores para fim de produzir uma frequência pwm de 50Hz manipulando o valor das variáveis de divisão e Wrap
const float PWM_DIV = 250.0; 
const uint16_t WRAP = 10000;



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
  
    stdio_init_all();


    configuracoes_iniciais();


    while (true) {
       
    }
}
