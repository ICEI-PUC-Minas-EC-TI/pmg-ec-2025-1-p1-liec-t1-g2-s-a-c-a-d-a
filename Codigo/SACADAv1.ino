#include <Servo.h>

const int sensor = 13;
const int botao = 12;
const int motor = 11;

Servo servoMotor;

bool estadoChuvaAnterior = false;
int ultimaDirecao = 1; //1 = sentido horário, 2 = sentido anti-horário

void setup() {
  pinMode(sensor, INPUT);
  pinMode(botao, INPUT_PULLUP);
  
  servoMotor.attach(motor);
  servoMotor.write(90); // posição neutra
  
  Serial.begin(9600);
}

void loop() {
  bool estaChovendo = digitalRead(sensor) == LOW;
  bool botaoPressionado = digitalRead(botao) == LOW;

  static bool estadoAnteriorSensor = false;

  // Se começou a chover
  if (estaChovendo && !estadoAnteriorSensor) {
    Serial.println("Chuva detectada. Girando servo 3x para direção 1.");
    girarServoVariasVezes(1, 3);
    ultimaDirecao = 1;
  }

  // Se parou de chover
  if (!estaChovendo && estadoAnteriorSensor) {
    Serial.println("Chuva parou. Girando servo 3x para direção 2.");
    girarServoVariasVezes(2, 3);
    ultimaDirecao = 2;
  }

  estadoAnteriorSensor = estaChovendo;

  // Botão pressionado
  if (botaoPressionado) {
    delay(200); // debounce

    if (ultimaDirecao == 1) {
      Serial.println("Botão pressionado. Girando 3x para direção 2.");
      girarServoVariasVezes(2, 3);
      ultimaDirecao = 2;
    } else if (ultimaDirecao == 2) {
      Serial.println("Botão pressionado. Girando 3x para direção 1.");
      girarServoVariasVezes(1, 3);
      ultimaDirecao = 1;
    } else {
      Serial.println("Sem direção anterior registrada.");
    }

    // Espera o botão ser solto
    while (digitalRead(botao) == LOW) {
      delay(10);
    }
  }
}

void girarServoVariasVezes(int direcao, int vezes) {
  int angulo = (direcao == 1) ? 0 : 180;

  for (int i = 0; i < vezes; i++) {
    servoMotor.write(angulo);
    delay(1000); // tempo em cada posição
    servoMotor.write(90); // centro
    delay(1000);
  }
}
