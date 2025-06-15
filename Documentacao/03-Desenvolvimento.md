
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

Descreva o desenvolvimento das telas do aplicativo.

### Código

Descreva o desenvolvimento do código do aplicativo.

## Desenvolvimento do Hardware

### Montagem

Descreva como foi o processo da montagem do projeto.

### Desenvolvimento do Código

Descreva como foi o desenvolvimento do código do arduino/ESP.

## Comunicação entre App e Hardware

Descreva como foi o processo de comunicação entre App e arduino/ESP.
