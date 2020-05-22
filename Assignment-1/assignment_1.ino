int LEDpin = 9;
unsigned long previous_time = 0;//unsigned long because it has 
                               //to be operated with this type
int LEDstate = HIGH;//variable that will store the state of LED
                   //to be written

void setup()
{
  pinMode(LEDpin, OUTPUT);//configures LEDpin numbered pin to 
                         //output 
}

void loop()
{
  unsigned long current_time = millis();//because return type of
                                       //millis() is unsigned long
  
  if (current_time - previous_time >= 1000){//to check if 1000 ms
    //(or more) have passed.(because time passed may not exactly 
    // be 1000ms)
    // if yes, then
    previous_time = current_time;//update previous_time
    if (LEDstate == HIGH) LEDstate = LOW;//switch the state
    else LEDstate = HIGH;  
  }
    
  digitalWrite(LEDpin, LEDstate);//run the LED
}