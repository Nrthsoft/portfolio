/**
   @author Olli-Pekka
   @version 2.0 25.1.2020
*/
class Led
{
  private:
    int _pin;
    int _times[4];
    unsigned long timeIndex = 0;
    unsigned long latestTime = 10000;
    int ledState = LOW;

  public:
    Led(int pin, int times[4]);
    int Stop();
    int Start();
    int Check();
};

Led::Led(int pin, int times[4])
{
  for (int i = 0; i < 4; i++)
  {
    _times[i] = times[i];
  }
  _pin = pin;
  pinMode(pin, OUTPUT);
}

int Led::Stop()
{
  digitalWrite(_pin, LOW);
}

int Led::Start ()
{
  digitalWrite(_pin, HIGH);
}

int Led::Check()
{
  if (millis() - latestTime >= _times[timeIndex])
  {
    if ( timeIndex == 3)  timeIndex = 0; else  timeIndex += 1;
    if (ledState == HIGH ) ledState = LOW; else ledState = HIGH;
    latestTime = millis();
    digitalWrite(_pin, ledState);
  }
}

int doubleBlink[4] = {2000, 100 , 100, 100};
int singleBlink[4] = {2200, 100 , 0, 0};
Led strobe = Led(13, doubleBlink);
Led backlight = Led(12, singleBlink);
Led leftNav = Led(11, singleBlink);
Led leftStrobe = Led(10, singleBlink);
Led rightNav = Led(9, singleBlink);
Led rightStrobe = Led(8, singleBlink);

void setup()
{
  leftNav.Start();
  rightNav.Start();
  backlight.Start();
}

/**
   Kutsutaan ledejä ohjaavia ohjelmia
*/
void loop()
{
  strobe.Check();
  leftStrobe.Check();
  rightStrobe.Check();
}
