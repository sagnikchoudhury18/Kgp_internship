#include<Servo.h>

Servo s[17];

int i=0;

class Servo_Motor
{
  public:
  int deg,pos,dir=0;
  void move_Motor(int deg,int pos,int dir,int servo_obj,int motor_num);               //number contains which servo to move
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

  for(int k=2;k<14;k++)
  s[k].write(0);

  delay(200);

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
  m[0].move_Motor(60,m[0].pos,1,2,0);
  break;
  case 'B':
  m[1].move_Motor(60,m[1].pos,1,3,1);
  break;
/*  case 'C':
  m3_RA.move_Motor(60,m3_RA.pos,1);*/
  
  
  
  }

 delay(500);
 }


 void Servo_Motor::move_Motor(int deg,int pos,int dir,int servo_obj,int motor_num)       //servo_num contains the servo object

{Serial.println(dir);

  if(dir==1)                //rotate clockwise
  {
    Serial.println("Executing cond ");
    Serial.print("Val of pos  ");
    Serial.println(m[motor_num].pos);
    if(m[motor_num].pos<179)
      {
        int a=update_pos(m[motor_num].pos,deg);
        Serial.print("Val of a      :");
        Serial.println(a);
        for(i=m[motor_num].pos;   i<a;  i++){
          s[servo_obj].write(i);
          delay(10);
          }
       m[motor_num].pos=a;
        Serial.print("Val of pos                 :");
        Serial.println(m[motor_num].pos);
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

