#include <Servo.h>

Servo servo1;
Servo servo2;

const int pinServo1 = 9;
const int pinServo2 = 10;
const int pinLed1 = 2;
const int pinLed2 = 3;

void setup() {
  Serial.begin(9600);
  
  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
  
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
  
  servo1.write(90);
  servo2.write(90);
}

void loop() {
  if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();
    
    int divisor = comando.indexOf(':');
    if (divisor != -1) {
      int numServo = comando.substring(0, divisor).toInt();
      int angulo = comando.substring(divisor + 1).toInt();
      
      if (numServo == 1) {
        digitalWrite(pinLed1, HIGH);
        servo1.write(angulo);
        delay(300); // Mantém o LED aceso durante a movimentação
        digitalWrite(pinLed1, LOW);
      } else if (numServo == 2) {
        digitalWrite(pinLed2, HIGH);
        servo2.write(angulo);
        delay(300);
        digitalWrite(pinLed2, LOW);
      }
    }
  }
}