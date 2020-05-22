#include<Servo.h>

const int trigPin = 10;
const int echoPin = 11;

long duration;
int distance;

const int button = 2;
int buttonState = LOW;
int LongPress = LOW;

const int LEDpin = 13;

Servo servo;
int pos = 0;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(button, INPUT);
  
  pinMode(LEDpin, OUTPUT);
  
  servo.attach(9);
}

void loop()
{
  servo.write(0);
  
  digitalWrite(trigPin, LOW);//clears the trigPin
  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);//giving out pulse
  delayMicroseconds(10);
  
  digitalWrite(trigPin,LOW);
  
  duration = pulseIn(echoPin, HIGH);//reads in travel time in µs
                       
  distance = duration *0.034/2;//stores distance in cm
  
  buttonState = digitalRead(button);
  
  if (buttonState == HIGH){//checking if pressed
    LongPress = HIGH;//checking if long pressed
    for(int time=0; time<=3000; time+=5){
      delay(5);
      int current = digitalRead(button);
      if (current == LOW){
        LongPress = LOW;
        break;
      }
    }  
  }
  
  if(distance>=30 && distance<=100){//if person is inside
    
    if (buttonState==HIGH){//if button is pressed
      
      digitalWrite(LEDpin, HIGH);//turn on LED
      
      for(int osc = 0; osc<5; ++osc){//5 osc of servo motor
        for(pos = 0; pos<=180; ++pos){
          servo.write(pos);
          delay(15);        
        }
        for(pos = 180; pos>=0; --pos){
          servo.write(pos);
          delay(15);        
        }  
      }
      
      digitalWrite(LEDpin, LOW);//turn off LED    
    }
    
  }else{//if person is outside
    
    if (buttonState==HIGH && LongPress==LOW){//if button is 
                                //pressed but not long pressed
      
      digitalWrite(LEDpin, HIGH);//turn on LED
      
      for(pos = 0; pos<=180; ++pos){//1 osc of servo motor
        servo.write(pos);
        delay(15);        
      }
      for(pos = 180; pos>=0; --pos){
        servo.write(pos);
        delay(15);        
      } 
      
      digitalWrite(LEDpin, LOW);//turn off LED    
    }
    
    if (buttonState==HIGH && LongPress==HIGH){//if button is
                                              //long pressed
      
      digitalWrite(LEDpin, HIGH);//turn on LED
      
      for(int osc = 0; osc<5; ++osc){//5 osc of servo motor
        for(pos = 0; pos<=180; ++pos){
          servo.write(pos);
          delay(15);        
        }
        for(pos = 180; pos>=0; --pos){
          servo.write(pos);
          delay(15);        
        }  
      }
      
      digitalWrite(LEDpin, LOW);//turn off LED    
    
    }  
  }  
}