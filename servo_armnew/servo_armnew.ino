#include<Servo.h>

Servo servo1_RA;
Servo servo2_RA;
Servo servo3_RA;

Servo servo1_LA;
Servo servo2_LA;
Servo servo3_LA;

int servo1_RApin=2;
int servo2_RApin=3;
int servo3_RApin=4;

int servo1_LApin=5;
int servo2_LApin=6;
int servo3_LApin=7;


int i=0;

class Servo_Motor
{
  public:
  int deg=0,pos,dir=0;
  void move_Motor(int deg,int pos,int dir);
  int update_pos(int curr_pos,int final_pos);     //i will contain the pos of current passing object
}m1_RA,m2_RA,m3_RA,m1_LA,m2_LA,m3_LA;

void setup()
{
  Serial.begin(9600);
  m1_RA.pos=0,m2_RA.pos=0,m3_RA.pos=0,m1_LA.pos=0,m2_LA.pos=0,m3_LA.pos=0;
  servo1_RA.attach(servo1_RApin);
  servo2_RA.attach(servo2_RApin);
  servo3_RA.attach(servo3_RApin);

  servo1_LA.attach(servo1_LApin);
  servo2_LA.attach(servo2_LApin);
  servo3_LA.attach(servo1_LApin);


  servo1_RA.write(0);
  servo2_RA.write(0);
  servo3_RA.write(0);

  servo1_LA.write(0);
  servo2_LA.write(0);
  servo3_LA.write(0);
  
  
  }


void loop()
{
  char check=0;
  if(Serial.available())
  {
    check=Serial.read();
    Serial.println(check);
    }

switch(check)
{
  case 'A':
  m1_RA.move_Motor(60,m1_RA.pos,1);
  /*case 'B':
  m2_RA.move_Motor(60,m2_RA.pos,1);
  case 'C':
  m3_RA.move_Motor(60,m3_RA.pos,1);*/
  
  
  
  }

 delay(500);
 }


 void Servo_Motor::move_Motor(int deg,int pos,int dir)
{
  if(dir==1)                //rotate clockwise
  {
    Serial.println("Executing cond ");
    Serial.print("Val of pos  ");
    Serial.println(pos);
    if(m1_RA.pos<179)
      {
        int a=update_pos(pos,deg);
        for(i=m1_RA.pos;i<a;i++){
          servo1_RA.write(i);
          delay(10);
          }
        m1_RA.pos=a;
        Serial.print("Val of pos                 :");
        Serial.println(m1_RA.pos);
       }
    
    }
  
  
 }
 
  int Servo_Motor::update_pos(int curr_pos,int final_pos)
  {
    Serial.print("Current pos  :");
    Serial.println(curr_pos);
    Serial.print("final_pos");
    final_pos=curr_pos+final_pos;
    Serial.println(final_pos);
    return final_pos;
    
    
    }

