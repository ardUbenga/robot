///version 23/08/2016
#include <Servo.h>
Servo myservo;  // crear objeto para controlar el servo
int Trig=8;
int Echo=10;
int motoraa=4;
int motorab=5;
int motorba=6;
int motorbb=7;
int velocidad=255;
int velocidad1=150; 
int d; //Distancia
int Dist; 
void setup() {
myservo.attach(3);  // asigna el pin 3 al objeto servo 
pinMode (Trig, OUTPUT);
pinMode (Echo, INPUT);
Serial.begin(9600);
pinMode(motoraa,OUTPUT);
pinMode(motorab,OUTPUT);
pinMode(motorba,OUTPUT);
pinMode(motorbb,OUTPUT); 
}

 
 
void loop() {
  myservo.write(90);
  delay(1000);
//llamamos la funcion calcularDistancia() y guardamos su
//retorno en una variable
  delante();
int centimetros=ultrasonido ();
Serial.println(centimetros);
if(centimetros < 20)
  {
     Serial.println("Que se choca");
     parar();    
  }
  delay(1000);  
}

/////////FUNCIONES DEL ROBOT/////////////////////////////////////

/////////FUNCIÓN CALCULAR DISTANCIA////////////////////////

//Este módulo calcula y devuelve la distancia en cm.
/*
Puedes poner el código del módulo directamente en el loop o utilizar el módulo
para reducir el número de líneas de código del loop o reutilizar el código
*/
int ultrasonido (){
 
//Para estabilizar el valor del pin Trig se establece a LOW
digitalWrite (Trig, LOW);
delay(10);
 
//Se lanzan los 8 pulsos
digitalWrite (Trig, HIGH);
delay(1);
digitalWrite (Trig, LOW);
 
/*
Se mide el tiempo que tarda la señal en regresar y se calcula la distancia.
 
Observa que al realizar pulseIn el valor que se obtiene es tiempo, no distancia
 
Se está reutilizando la variable Distancia.
*/
 
unsigned long distancia= pulseIn (Echo, HIGH);
distancia=distancia/58;
return distancia;
 
delay(100);  
}



////FUNCIONES DE ADELANTE, DETRÁS Y PARADA.
void delante()
{
 Serial.println("Delante");
 analogWrite(motoraa,velocidad);
 analogWrite(motorab,0);
 analogWrite(motorba,velocidad);
 analogWrite(motorbb,0);
}

void detras()
{
 Serial.println("Detrás");
 analogWrite(motoraa,0);
 analogWrite(motorab,velocidad);
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

void izquierda()
{
 Serial.println("Giro Izquierda");
 analogWrite(motoraa,velocidad);
 analogWrite(motorab,0);
 analogWrite(motorba,0);
 analogWrite(motorbb,0);
}

void derecha()
{
 Serial.println("Giro Derecha");
 analogWrite(motoraa,0);
 analogWrite(motorab,0);
 analogWrite(motorba,velocidad);
 analogWrite(motorbb,0);
}


//////////FUNCION QUE DECIDE QUE HACER/////////////////
void decide()
{
  
      Serial.println("para");
      delay(2000);
      parar();
      delay(3000);
      detras();
      delay(3000);
      parar();
      delay(3000);
      izquierda();
      delay(2000);
      parar();
      delay(3000);
}
 
  
