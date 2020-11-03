void langsam(void)
{

  if (millis() > verzh + myTimer ) {
    myTimer = millis();

    if (power < 80)
    {
      power++;
    }
  }
}


void mittel(void)
{
  if (millis() > verzh + myTimer ) {
    myTimer = millis();

    if (power < 95)
    {
      power++;
    }
  }
}


void schnell(void)
{
  if (millis() > verzh + myTimer ) {
    myTimer = millis();

    if (power < 130)
    {
      power++;
    }
  }
}

void herunterfahren(void)
{
  if (millis() > verzr + myTimer ) {
    myTimer = millis();

    if (power > 30)
    {
      power--;
    }
  }
}



void Spurservo_fahren(void) {

  if (u == 1 && o == 0) {

    static int i = 20;

    if (millis() > (3000 / power) + myTimer2 ) {
      myTimer2 = millis();

      Spur.write(i);
      if (power > 30) {
        i++;
      }
      Serial.println(i);

      if (i == 160) {
        o = 1;
        u = 0;
        i = 20;
      }

    }
  }



  if (u == 0 && o == 1) {

    static int s = 160;

    if (millis() > (3000 / power) + myTimer2 ) {
      myTimer2 = millis();

      Spur.write(s);

      if (power > 30) {
        s--;
      }
      Serial.println(s);

      if (s == 20) {
        o = 0;
        u = 1;
        s = 160;
      }

    }
  }
}
