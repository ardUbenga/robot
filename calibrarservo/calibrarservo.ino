#include <Servo.h>
Servo miservo;
int motoraa=4;
int motorab=5;
int motorba=6;
int motorbb=7;
int velocidad=255;
int velocidad1=150; 
int d; //Distancia
int pos;
int dato;
void setup() {
miservo.attach(3);
Serial.setTimeout(100);
Serial.begin(9600);
pinMode(motoraa,OUTPUT);
pinMode(motorab,OUTPUT);
pinMode(motorba,OUTPUT);
pinMode(motorbb,OUTPUT);   
}

void loop() {
if (Serial.available()>0)
  {
    parar();  
  //pos=Serial.readString().toInt();
    pos=Serial.read();
    if (pos=='0'){
      adelante();
    }
    if (pos=='1'){
      detras();
    }
    if (pos=='2'){
      izquierda();
    }
    if (pos=='3'){
      derecha();
    }
    if (pos=='6'){
      parar();
    }

/*  if (pos=="4"){
      
    }
    miservo.write(pos);
*/    
   
  }   
}

void adelante()
{
 Serial.println("Delante");
 analogWrite(motoraa,0);
 analogWrite(motorab,velocidad);
 analogWrite(motorba,0);
 analogWrite(motorbb,velocidad);
}

void detras()
{
 Serial.println("Detrás");
 analogWrite(motoraa,velocidad);
 analogWrite(motorab,0);
 analogWrite(motorba,velocidad);
 analogWrite(motorbb,0);
}

void izquierda()
{
 Serial.println("Giro Izquierda");
 analogWrite(motoraa,0);
 analogWrite(motorab,velocidad);
 analogWrite(motorba,0);
 analogWrite(motorbb,0);
}

void derecha()
{
 Serial.println("Giro Derecha");
 analogWrite(motoraa,0);
 analogWrite(motorab,0);
 analogWrite(motorba,0);
 analogWrite(motorbb,velocidad);
}

void parar()
{
 Serial.println("Parar");
 analogWrite(motoraa,0);
 analogWrite(motorab,0);
 analogWrite(motorba,0);
 analogWrite(motorbb,0);
}

