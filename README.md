

# Controle de posicionamento de servo motor através de sinal PWM

Este repositório contém o projeto de controle de posição de um servo motor através de sinal PWM, controlando o ciclo ativo, e determinando uma rotina de animação.

## Componentes
- Microcontrolador Raspberry Pi Pico W.
- Servo Motor

## Funcionamento

- O projeto em questão visa ajustar a posição do servo motor inicialmente para um ângulo de 0 graus, e a cada 5 segundos mudar a posição, primeiramente para 90 graus, e depois por último em 180 graus.
- Após essa mudança de posição, o servo motor de forma contínua e suave se moverá de 0 a 180 graus repetidamente utilizando o sinal PWM.
- O projeto é completamente observado pelo usário, não havendo interações com o mesmo.
  
## Instruções de uso

### Requisitos
- Ambiente de desenvolvimento **VS Code**.
- **Simulador Wokwi** para simulação do hardware.
- Kit de desenvolvimento **Pico SDK**.

### Passos para Execução
1. Clone este repositório:
   ```bash
   git clone https://github.com/andrelimatecnologias/tarefa_pwm.git
   ```
2. Instale as dependências necessárias para o Pico SDK.
3. Importe o projeto no **VS Code** e configure o simulador Wokwi.
4. Compile o código
5. Inicialize a simulação com o auxílio do WOKWI

### Observação
A prática pode ser realizada apenas em simulação, mas alternando o pino GPIO utilizado para o valor 12 é possível observar o comportamente pwm gerado em um LED RGB

## Vídeo de teste
Um vídeo mostrando o teste desta atividade pode ser acessado no link: (https://youtu.be/5FXdelHOFyE)

## Autor do projeto:
André Souza Lima
