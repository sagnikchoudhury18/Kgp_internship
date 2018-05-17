#include <Servo.h>
Servo servo1;
int ang=0;
void setup() {
  // put your setup code here, to run once:
  servo1.attach(50);

}

void loop() {
  // put your main code here, to run repeatedly:

  for(ang=0;ang<180;ang+=1)
  {
  servo1.write(ang);
  delay(15);  
  }
  delay(1000);
  for(ang=180;ang>=1;ang-=5)
  {
  servo1.write(ang);
  delay(5);
  }
  delay(1000);
}
