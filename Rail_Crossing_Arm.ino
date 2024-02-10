#include <Servo.h>
#define ledStop 7
#define ledGo 8
#define gateClose 2
#define gateOpen 3
Servo myservo;


void setup() {
  myservo.attach(9);
  pinMode(gateClose, INPUT_PULLUP);
  pinMode(gateOpen, INPUT_PULLUP);
  pinMode(ledStop, OUTPUT);
  pinMode(ledGo, OUTPUT);
  myservo.write(0);
}

void loop() {
  if(digitalRead(gateClose) == LOW) {
    digitalWrite(ledStop, HIGH);
    for(int i = 0; i <= 90; i++) {
      myservo.write(i);
      delay(30);
    }
    delay(100);
    digitalWrite(ledStop, LOW);
  }
  else if(digitalRead(gateOpen) == LOW) {
    digitalWrite(ledGo, HIGH);
    for(int i = 90; i >= 0; i--) {
      myservo.write(i);
      delay(30);
    }
    delay(100);
    digitalWrite(ledGo, LOW);
  }
}
