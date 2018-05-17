#include<Servo.h>
Servo myservo;
int pos;
double timeA_1,timeA_2;
double timeB_1,timeB_2;
int servo_pin=9;
int servo_state=0;
void servo_right();
void servo_left();

void setup() {
  timeA_1=0,timeB_1=0,timeA_2=0,timeB_2=0;
  Serial.begin(9600);
  myservo.attach(servo_pin);
  myservo.write(0);
  
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
    
    myservo.attach(servo_pin);
    //Serial.println(pos);
    if(pos==0)
    {
    timeA_1=millis();
    for (pos = 0; pos < 90; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(2);  
     //Serial.println(" rot left");
     //Serial.println(myservo.read());
    }
    timeA_2=millis();
    /*Serial.print("timeA_1  ");
    Serial.println(timeA_1/1000);
    Serial.println("timeA_2  ");
    Serial.println(timeA_2/1000);*/
    Serial.print("Cal time  ");
    Serial.println((timeA_2-timeA_1)/1000);
    }
    myservo.detach();
}

  
void servo_right()
{ 
    
    myservo.attach(servo_pin);
    //Serial.println(pos);
    if(pos==90)
    {
    timeB_1=millis();
    //for (pos = 90; pos > 0; pos -= 1) 
    for (pos = 90; pos <270; pos += 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(2);   
      //Serial.println("rot right");
      //Serial.println(myservo.read());
    }
    timeB_2=millis();
    /*Serial.print("timeB_1  ");
    Serial.println(timeB_1/1000);
    Serial.println("timeB_2  ");
    Serial.println(timeB_2/1000);*/
    Serial.print("Cal time  ");
    Serial.println((timeB_2-timeB_1)/1000);
    }
    myservo.detach();
}

