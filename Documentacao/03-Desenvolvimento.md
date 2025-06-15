
# Materiais

Os materiais utilizados no projeto foram:
- Arduino.
- Sensor de umidade.
- Ponte H.
- Motor com caixa de redução.
- Botão.
- Papelão.

# Desenvolvimento

1. Desenvolvimento do Aplicativo
A equipe criou um aplicativo simples e funcional, permitindo ao usuário:
- Verificar o status da janela (aberta ou fechada).
- Fechar a janela remotamente com um botão no app.
- O app foi desenvolvido no MIT AppInventor, utilizando comunicação com o ESP32 via bluetooth.

2. Desenvolvimento do Sistema Embarcado
Paralelamente, foi feita a programação do ESP32 utilizando a Arduino IDE. Foram integrados:
- Sensor de chuva: para detectar automaticamente a presença de água.
- Motor de passo: para realizar o movimento de abrir ou fechar a janela.
- Conexão Wi-Fi: para receber comandos do aplicativo.

3. Integração entre Hardware e Aplicativo
Após o desenvolvimento individual dos componentes, foi realizada a integração:
- O aplicativo envia comandos ao ESP32 via bluetooth.
- O ESP32 interpreta o comando e aciona o motor, ou responde automaticamente ao sensor de chuva.

4. Testes e Ajustes
Foram feitos testes em bancada para validar:
- A resposta do motor ao comando do app.
- A atuação do sensor de chuva em diferentes níveis de umidade.
- A estabilidade da conexão Wi-Fi.

7. Documentação e Conclusão
Por fim, foram registradas todas as etapas do projeto, incluindo:
- Diagramas do circuito eletrônico.
- Códigos-fonte comentados.
- Prints do aplicativo.
- Resultados dos testes.

## Desenvolvimento do Aplicativo

### Interface

O desenvolvimento da interface foi feito utilizando o MIT AppInventor, uma plataforma de programação por blocos voltada para aplicativos Android. A proposta da interface foi manter um layout simples, intuitivo e funcional. As telas desenvolvidas foram:

Tela Principal:
- Botão "Fechar Janela": envia um comando para acionar o motor, simulando o fechamento da janela.
- Botão "Abrir Janela": envia um comando para acionar o motor, simulando a abertura da janela.
- Indicador de status: exibe o estado atual da janela (aberta ou fechada).
- Botão para salvar preferências.
O foco foi garantir acessibilidade e resposta rápida, com botões grandes e visual limpo para facilitar o uso em qualquer dispositivo móvel.

### Código

O código do aplicativo foi desenvolvido no MIT AppInventor, utilizando blocos de programação visual. O objetivo foi permitir que o usuário controlasse a janela por meio de botões, enviando comandos via Bluetooth para o Arduino Uno com um módulo Bluetooth (como o HC-05).
Durante o desenvolvimento, foram criadas funções específicas para:
Conectar ao dispositivo Bluetooth:
Um botão permite que o usuário selecione e conecte o celular ao módulo Bluetooth do Arduino.
Enviar comandos ao Arduino:
Foram programados dois botões no app — “Abrir Janela” e “Fechar Janela” — que enviam os comandos de texto "ABRIR" e "FECHAR" respectivamente para o Arduino. Esses comandos são enviados através do componente BluetoothClient.
Receber e exibir respostas:
O app também foi configurado para receber mensagens do Arduino, como "Aberta" ou "Fechada", informando o estado atual da janela. Essa resposta é lida automaticamente e exibida em um campo de status.
Todo o código foi construído com blocos simples, organizados de forma clara, garantindo a comunicação entre o aplicativo e o Arduino de maneira eficiente e funcional.

## Desenvolvimento do Hardware

### Montagem

Montagem
A montagem do projeto foi realizada em bancada, utilizando o Arduino Uno como microcontrolador principal. Para detectar chuva, foi utilizado um sensor de chuva capacitivo, e o controle do movimento da janela foi feito com um motor de passo conectado a um driver ULN2003. A comunicação com o aplicativo foi viabilizada por um módulo Bluetooth HC-05, conectado às portas digitais do Arduino.
O processo de montagem envolveu:
- Conexão do sensor de chuva à entrada analógica do Arduino para monitorar a presença de água;
- Ligação do motor de passo ao driver ULN2003, com alimentação separada para garantir corrente suficiente;
- Integração do módulo Bluetooth HC-05 às portas digitais (via SoftwareSerial), com alimentação de 5V e GND;
- Utilização de uma fonte externa (bateria ou fonte de bancada) para alimentar o motor com estabilidade;
- Montagem dos componentes em uma protoboard para facilitar os testes e ajustes.

### Desenvolvimento do Código

O código foi escrito na IDE do Arduino, e sua lógica foi dividida em três partes principais:
Leitura do Sensor de Chuva

O Arduino lê periodicamente os valores do sensor. Se o valor indicar presença de água, o sistema aciona o motor para fechar a janela automaticamente.

Controle Manual via App

O Arduino também monitora comandos recebidos por Bluetooth. Se o usuário enviar "ABRIR" ou "FECHAR", o Arduino executa o movimento correspondente, independentemente da leitura do sensor.

Feedback ao Aplicativo

Após executar a ação, o Arduino envia de volta uma resposta textual ("Aberta", "Fechada" ou "Chuva detectada") para que o app exiba ao usuário o status atualizado.

## Comunicação entre App e Hardware

Descreva como foi o processo de comunicação entre App e arduino/ESP.
