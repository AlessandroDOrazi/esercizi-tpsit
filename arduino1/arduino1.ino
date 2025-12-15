#define INT1 4
#define INT2 5
#define PIN_DIG 2  //Assegnazione delle costanti

unsigned long tempora1, tempin1 = 0, tempora2, tempin2 = 0;
int val, interruttore1, interruttore2;

void setup() 
{
  pinMode(INT1, INPUT);
  pinMode(INT2, INPUT);
  pinMode(PIN_DIG, INPUT);
  Serial.begin(9600);
}

void loop()
{
  tempora1 = millis();
  interruttore1 = digitalRead(INT1);
  interruttore2 = digitalRead(INT2);

  if (tempora1 - tempin1 >= 3000) 
  {
    if interruttore2 == HIGH) //Funziona solo il sensore digitale
    {
      if (digitalRead(PIN_DIG) == HIGH)
        Serial.println("qualcosa vicino");
      else
        Serial.println("niente nelle vicinanze");
    }
    if (interruttore1 == HIGH) //Funziona solo il sensore analogico
    {
      val = analogRead(1);
      Serial.println(val, DEC);
    }
    tempin1 = tempora1;
  }
}