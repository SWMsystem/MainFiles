
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
int ledBlue=4;
int trigPin=9;
int echoPin=10;
float pingTime;
float distance;
float v=34600;
void setup() 
{
  Serial.begin(9600);  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(ledBlue,OUTPUT);
  mySerial.begin(9600);
  delay(100);
}
void loop() 
{
  digitalWrite(trigPin,LOW);
  delay(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin,LOW);

  pingTime=pulseIn(echoPin,HIGH);
  pingTime=pingTime/1000000.0;


  distance=v*pingTime;
  distance=distance/2.0;
  Serial.println("Distance to the target is:");
  Serial.println(distance);
  

  if(distance>5)
  {
   
    digitalWrite(ledBlue,LOW);
   
  }
  else
  {
   
    if(mySerial.available()>0)
    Serial.write(mySerial.read());  
    
    digitalWrite(ledBlue,HIGH);
  }

}

