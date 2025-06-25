# Testes do Projeto

Os testes do projeto da janela inteligente foram realizados em bancada, com o sistema completo: aplicativo no celular, Arduino Uno com o código final, sensor de chuva, motor de passo e módulo Bluetooth HC-05.
Foram feitos testes em três principais frentes:
- Teste da Comunicação Bluetooth
- Verificação do emparelhamento entre o celular e o módulo HC-05.
- Testes de envio de comandos (“ABRIR” e “FECHAR”) pelo app.
- Confirmação do recebimento e execução correta dos comandos no Arduino.
- Teste do Sensor de Chuva.
- Simulação de chuva com gotas de água no sensor.
- Verificação do acionamento automático do motor para fechar a janela.
- Testes de leitura em ambiente seco para garantir que a janela não feche indevidamente.
- Testes de leitura em ambiente molhado para garantir que a janela não abra indevidamente.
- Teste do Motor de Passo.
- Avaliação do tempo e força de giro necessário para abrir e fechar a janela simulada.
- Ajustes no tempo de acionamento para garantir movimento completo sem travamentos.

Resultados Obtidos
- A comunicação Bluetooth funcionou de forma estável, com reconhecimento imediato dos comandos enviados.
- O motor de passo foi capaz de realizar o movimento necessário para abertura/fechamento da janela, de forma confiável, quando alimentado com fonte estável.
- A detecção de água faz a janela fechar, e travar para que no aplicativo a janela não seja aberta.
- O aplicativo abre e fecha a janela de acordo com a condição anterior.

Limitações Identificadas
- Alcance do Bluetooth: limitado a cerca de 5 a 10 metros, o que pode restringir o uso em ambientes maiores ou com obstáculos físicos.
- Resposta do sensor de chuva: em ambientes muito úmidos, pequenas gotículas ou névoa podem acionar o sensor indevidamente.
- Precisão do motor: sem sensores de fim de curso, o sistema não reconhece automaticamente se a janela já está totalmente aberta ou fechada, o que pode causar esforço desnecessário do motor.
- Fonte de alimentação: motores exigem uma fonte externa estável; em testes com alimentação fraca, o movimento ficou inconsistente.
- O sensor de água MHRD pode ser substituído por um sensor mais preciso.
- O aplicativo do AppInventor tem limitações que impede o monitoramento dos status da janela.
- Por ser um projeto protótipo, deve-se utilizar um contra peso para travar o trilho no motor.

Conclusão
- Os testes mostraram que o sistema é funcional, responsivo e cumpre seu objetivo principal: abrir e fechar a janela automaticamente ou sob comando do usuário. Com melhorias no sensor de chuva e no aplicativo, o projeto pode evoluir para um uso prático mais seguro e confiável.
