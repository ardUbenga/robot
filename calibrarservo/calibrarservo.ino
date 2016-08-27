#include <Servo.h>
Servo miservo;
int pos;
void setup() {
miservo.attach(3);
Serial.begin(9600);  
}

void loop() {
if (Serial.available())
  {
    while (Serial.available ()>0)
    {
      pos=Serial.read();
      if (pos=='0')
      {
        miservo.write(0); 
      }

      else if(pos=='1')
      {
        miservo.write(90);
      }

      else if(pos=='2')
      {
         miservo.write(180);
      }
    }
  }   
}

