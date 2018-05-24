#include<Servo.h>

Servo s[17];

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
  void move_Motor(int deg,int pos,int dir,int servo_obj);               //number contains which servo to move
  int update_pos(int curr_pos,int final_pos);     //curr_pos  will contain the pos of current passing object
}m[12];

void setup()
{
  Serial.begin(9600);
  int l=2;                            //pins
  m[0].pos=0,m[1].pos=0,m[2].pos=0,m[3].pos=0;
  for(int k=2;k<14;k++)             //Servo objects
  {
  s[k].attach(l);
  l++;
  }

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
  m[0].move_Motor(60,m[0].pos,1,2);
  case 'B':
  m[1].move_Motor(60,m[1].pos,1,3);
/*  case 'C':
  m3_RA.move_Motor(60,m3_RA.pos,1);*/
  
  
  
  }

 delay(500);
 }


 void Servo_Motor::move_Motor(int deg,int pos,int dir,int servo_obj)       //servo_num contains the servo object

{Serial.println(dir);

  if(dir==1)                //rotate clockwise
  {
    Serial.println("Executing cond ");
    Serial.print("Val of pos  ");
    Serial.println(pos);
    if(pos<179)
      {
        int a=update_pos(pos,deg);
        for(i=pos;   i<a;  i++){
          s[servo_obj].write(i);
          delay(10);
          }
        pos=a;
        Serial.print("Val of pos                 :");
        Serial.println(pos);
       }
       i=0;
    
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

