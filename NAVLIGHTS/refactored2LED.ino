

/**
 * @author Olli-Pekka 
 * @version 2.0 25.1.2020
 */
const int pin1 = 11;
const int pin2 = 10;

int blinkLEDState1 = LOW;
int blinkLEDState2 = LOW;


long times2[] = {2000, 100, 2000, 100};
long times1[] = {2000, 70, 70, 70};
long  ledTime1 = 0;
long ledTime2 = 0;

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;


/**
 * Asetetaan ledit ulostuloiksi
 */
void setup()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}


/**
 * Kutsutaan ledejä ohjaavia ohjelmia
 */
void loop()
{
  Led1();
  Led2();
}


/**
 * Led1 vilkkumisen ohjaava ohjelma
 */
void Led1() {

  unsigned long mainTime = millis();
  if (mainTime - previousMillis1 >= times1[ ledTime1])
  {
    if ( ledTime1 == 3)  ledTime1 = 0; else  ledTime1 += 1;
    if (blinkLEDState1 == HIGH ) blinkLEDState1 = LOW; else blinkLEDState1 = HIGH;
    previousMillis1 = mainTime;
    digitalWrite(pin1, blinkLEDState1);
  }
}


/**
 * Led2 vilkkumisen ohjaava ohjelma
 */
void Led2() {
  unsigned long mainTime = millis();
  if (mainTime - previousMillis2 >= times2[ ledTime2])
  {
    if ( ledTime2 == 3)  ledTime2 = 0; else  ledTime2 += 1;
    if (blinkLEDState2 == HIGH ) blinkLEDState2 = LOW; else blinkLEDState2 = HIGH;
    previousMillis2 = mainTime;
    digitalWrite(pin2, blinkLEDState2);
  }
}
