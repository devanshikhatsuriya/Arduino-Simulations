const int LEDpin = 13;
const int button = 2;
int buttonState = LOW;
int LEDstate = LOW;

void setup()
{
  pinMode(button, INPUT);
  pinMode(LEDpin, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(button);
  if (buttonState == HIGH){//if button pressed, switch LEDstate
  	if (LEDstate == LOW) LEDstate = HIGH;
    else LEDstate = LOW;
  }
  digitalWrite(LEDpin, LEDstate);//write output to the LED
  delay(10);//to improve performance
}