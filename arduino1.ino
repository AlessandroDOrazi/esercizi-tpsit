#define int1 4
#define int2 5

unsigned long tempora, tempin = 0;
const int digitalPin = 2;
int val, interruttore1, interruttore2;

void setup() 
{
  pinMode(int1, INPUT);
  pinMode(int2, INPUT);
  pinMode(digitalPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  tempora = millis();
  interruttore1 = digitalRead(int1);
  interruttore2 = digitalRead(int2);

  if (tempora - tempin >= 3000) 
  {
    if (interruttore1 == LOW && interruttore2 == HIGH) //Funziona solo il sensore digitale
    {
      if (digitalRead(digitalPin) == HIGH)
        Serial.println("qualcosa vicino");
      else
        Serial.println("niente nelle vicinanze");
    }

    else if (interruttore1 == HIGH && interruttore2 == LOW) //Funziona solo il sensore analogico
    {
      val = analogRead(1);
      Serial.println(val, DEC);
    }

    else if (interruttore1 == HIGH && interruttore2 == HIGH) //Entrambi non funzionanti (spenti)
    {
      Serial.println("usa un interruttore");
    }

    else if (interruttore1 == LOW && interruttore2 == LOW) //Entrambi non funzionanti (accesi)
    {
      Serial.println("accendere un sensore alla volta");
    }

    tempin = tempora;
  }
}