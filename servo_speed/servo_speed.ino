#include<VarSpeedServo.h>
double time1;
double time2;
VarSpeedServo servo1;

const int servopin1=9;

void setup() {
  time1=0.0,time2=0.0;
  servo1.attach(servopin1);
  servo1.write(0,255,true);
  Serial.begin(9600);
  delay(3000);
}


void loop() {
char check=0;
//Serial.print(myservo.read());
if(Serial.available())
{
check=Serial.read();
Serial.println(check);
}

switch(check)
{
case 'A':
servo_left();
delay(200);
Serial.println("servo left");
break;

case 'B':
servo_right();
delay(200);
Serial.println("servo right");
break;
  
}

delay(500);
}


void servo_left()
{  
   time1=millis();
   servo1.write(90,50,true);
   time2=millis();
   Serial.print("Time taken : ");
   Serial.println((time2-time1)/1000);
}

void servo_right()
{
   time1=millis();
   servo1.write(30,50,true);
   time2=millis();
   Serial.print("Time taken : ");
   Serial.println((time2-time1)/1000);  
  
}


