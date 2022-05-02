/*                     HAZİRAN 2021 TALPAY
                           USELESSBOX
**********
  BAĞLANTI PİNLERİ:
  1 NOLU TOGGLE ANAHTAR 2 NOLU DİGİTAL PİNE
  2 NOLU TOGGLE ANAHTAR 3 NOLU DİGİTAL PİNE
  3 NOLU TOGGLE ANAHTAR 4 NOLU DİGİTAL PİNE
  4 NOLU TOGGLE ANAHTAR 5 NOLU DİGİTAL PİNE

  1 NOLU SERVO 9 NOLU DİGİTAL PİNE
  2 NOLU SERVO 10 NOLU DİGİTAL PİNE
  3 NOLU SERVO 11 NOLU DİGİTAL PİNE
  4 NOLU SERVO 12 NOLU DİGİTAL PİNE
**********
*/

#include <Servo.h>

const int  buttonPin1 = 2;
const int  buttonPin2 = 3;
const int  buttonPin3 = 4;
const int  buttonPin4 = 5;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

int durum = 0;

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

int pos;
int derece_open = 150;
int derece_close = 5;
unsigned long eskizaman = 0;
unsigned long simdiki_zaman;

void setup()
{
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

  myservo1.attach(9);
  myservo2.attach(10);
  myservo3.attach(11);
  myservo4.attach(12);

  myservo1.write(100);
  myservo2.write(100);
  myservo3.write(100);
  myservo4.write(100);
}

void loop()
{
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  unsigned long simdiki_zaman = millis();
  if (simdiki_zaman - eskizaman >= 10) {
    if (buttonState1 == HIGH) {
      myservo1.write(derece_close);
      delay(15);
    }

    if (buttonState1 == LOW) {
      myservo1.write(derece_open);
      delay(15);
    }

    if (buttonState2 == HIGH) {
      myservo2.write(derece_close);
      delay(15);
    }

    if (buttonState2 == LOW) {
      myservo2.write(derece_open);
      delay(15);
    }


    if (buttonState3 == HIGH) {
      myservo3.write(derece_close);
      delay(15);

    }

    if (buttonState3 == LOW) {
      myservo3.write(derece_open);
      delay(15);

    }

    if (buttonState4 == HIGH) {
      myservo4.write(derece_close);
      delay(15);
    }

    if (buttonState4 == LOW) {
      myservo4.write(derece_open);
      delay(15);
    }
    eskizaman = millis();
  }
}
