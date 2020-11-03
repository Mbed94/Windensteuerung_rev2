// Je nachdem, welcher Drehregeler-Eingang (4,7,8) auf LOW gezogen wird, bestimmt den Gang
// Fußschalter (2) startet den Schleppvorgang


#include <Servo.h>

#define verzh 4
#define verzr 4
#define FUEHRGESCHW 1000 // Je kleiner, desto schneller bewegt sich der Führ-Arm der Trommel
Servo Regler;
Servo Spur;

float power=30;
int fusstaster, u, o;
unsigned long long int myTimer = 0, myTimer2 = 0;


void setup()
{
  pinMode(2, INPUT); // Fußtaster
  pinMode(4, INPUT); // Drehschalterpos. "Langsam"
  pinMode(7, INPUT); // Drehschalterpos. "Mittel"
  pinMode(8, INPUT); // Drehschalterpos. "Schnell"

  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);


  Regler.attach(9);
  Spur.attach(10);

  Regler.write(30);
  Spur.write(0);

  u = 1;
  o = 0;
  Serial.begin(115200);
  delay(3000); // Zeit für Regler-Initialisierung
}


void loop()
{

  fusstaster = digitalRead(2);

  if (fusstaster == LOW)
  {
    if (digitalRead(4) == LOW)
    {
      langsam();
    }

    if (digitalRead(7) == LOW)
    {
      mittel();
    }

    if (digitalRead(8) == LOW)
    {
      schnell();
    }
  }

  if (fusstaster == HIGH)
  {
    herunterfahren();
  }

  //Serial.println(power);
  Regler.write(power);

  Spurservo_fahren();
  


}
