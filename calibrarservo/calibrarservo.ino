#include <Servo.h>
Servo miservo;
int pos;
int dato;
void setup() {
miservo.attach(3);
Serial.setTimeout(100);
Serial.begin(9600);  
}

void loop() {
if (Serial.available())
  {
    pos=Serial.readString().toInt();
    miservo.write(pos);
   
  }   
}

