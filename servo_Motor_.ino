#include <Servo.h>
Servo servo;
int trigPin = 10;
int echoPin = 8;
int servoPin = 7;
long distance;
long duration,dist,average;
int aver[3];
void setup() 
{
servo.attach(servoPin); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);// put your setup code here, to run once:
}
 
void loop() { 
  for (int i=0;i<=2;i++) {   //average distance
    ultra();               
   aver[i]=dist;            
    delay(50);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2])/3;    //average distance by 3 measurements

if ( dist<20 ) {
 //if hand on the distance 10...30 cm
 servo.attach(servoPin);
  delay(0);
 servo.write(90);  
 delay(800);       //wait 5 seconds
 servo.write(0);    
 delay(3000);
 servo.detach();      
}
}
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  dist = duration*0.04/2;
  }
