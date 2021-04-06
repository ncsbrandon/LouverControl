#include <Servo.h>

const int minA = 0;
const int maxA = 90;
const int stepDelay = 20;
const int midPoint = 512;
int posA = 0;
Servo myservo1;
Servo myservo2;

void setup() {
}

void loop() {
  if (midPoint > analogRead(A0))
    servosToMax();
  else
    servosToMin();
}

void servosToMax() {
  if (posA >= maxA) {
    return;
  }

  myservo1.attach(9);
  myservo2.attach(10);

  for (posA = minA; posA <= maxA; posA += 1) {
    myservo1.write(posA);
    myservo2.write(posA);
    delay(stepDelay);
  }

  myservo1.detach();
  myservo2.detach();
}

void servosToMin() {
  if (posA <= minA) {
    return;
  }

  myservo1.attach(9);
  myservo2.attach(10);
  
  for (posA = maxA; posA >= minA; posA -= 1) {
    myservo1.write(posA);
    myservo2.write(posA);
    delay(stepDelay);
  }

  myservo1.detach();
  myservo2.detach();
}
