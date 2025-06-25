#include <SoftwareSerial.h>
#include <Stepper.h>

//Motor 28BYJ-48: 2048 passos por volta
const int passosPorVolta = 2048;
Stepper motor(passosPorVolta, 11, 9, 10, 8);

//Bluetooth
SoftwareSerial bluetooth(7, 6); //RX, TX
const int btStatePin = 4;

//Entradas
const int botaoPin = 12;
const int sensorChuvaPin = 13;

//Variáveis de controle
bool janelaAberta = false;        //Estado inicial: janela fechada
bool btConectado = false;

void setup() {
  pinMode(botaoPin, INPUT_PULLUP);
  pinMode(sensorChuvaPin, INPUT);
  pinMode(btStatePin, INPUT);

  Serial.begin(9600);
  bluetooth.begin(9600);

  motor.setSpeed(10); //Velocidade do motor
  Serial.println("Sistema iniciado. Janela está FECHADA.");
}

void loop() {
  //Checa conexão Bluetooth
  bool isBtConnected = digitalRead(btStatePin);
  if (isBtConnected && !btConectado) {
    Serial.println("Conectado");
    btConectado = true;
  } else if (!isBtConnected && btConectado) {
    Serial.println("Desconectado");
    btConectado = false;
  }

  //Checa chuva
  bool chovendo = digitalRead(sensorChuvaPin) == LOW;

  //Checa botão físico
  if (digitalRead(botaoPin) == LOW) {
    delay(200); //Debounce
    acionarJanelaManual(chovendo);
  }

  //Checa comando via Bluetooth
  if (bluetooth.available()) {
    char comando = bluetooth.read();
    //Debugg
    /* 
    Serial.print("Recebido via Bluetooth: ");
    Serial.println(comando);
    */
    if (comando == 'T') {
      acionarJanelaManual(chovendo);
    }
  }


  //Controle automático por chuva
  static bool estadoChuvaAnterior = false;
  if (chovendo && !estadoChuvaAnterior) {
    Serial.println("Chuva detectada! Fechando janela...");
    fecharJanela();
  } else if (!chovendo && estadoChuvaAnterior) {
    Serial.println("Chuva parou. Abrindo janela...");
    abrirJanela();
  }
  estadoChuvaAnterior = chovendo;
}

void acionarJanelaManual(bool chovendo) {
  if (chovendo) {
    Serial.println("Comando ignorado: está chovendo!");
    return;
  }

  if (janelaAberta) {
    Serial.println("Comando manual: fechando janela...");
    fecharJanela();
  } else {
    Serial.println("Comando manual: abrindo janela...");
    abrirJanela();
  }
}

void abrirJanela() {
  motor.step(passosPorVolta * 1); //sentido horário
  janelaAberta = true;
  Serial.println("Janela aberta.");
}

void fecharJanela() {
  motor.step(-passosPorVolta * 1); //sentido anti-horário
  janelaAberta = false;
  Serial.println("Janela fechada.");
}
