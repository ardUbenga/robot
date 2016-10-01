///version 23/08/2016
#include <Servo.h>
Servo myservo;  // crear objeto para controlar el servo
#define trig 8
#define echo 9
int motoraa=4;
int motorab=5;
int motorba=6;
int motorbb=7;
int velocidad=255;
int velocidad1=150; 
int d; //Distancia
void setup() {
myservo.attach(3);  // asigna el pin 3 al objeto servo 
pinMode (trig, OUTPUT);
pinMode (echo, INPUT);
Serial.begin(9600);
pinMode(motoraa,OUTPUT);
pinMode(motorab,OUTPUT);
pinMode(motorba,OUTPUT);
pinMode(motorbb,OUTPUT); 
}

 
 
void loop() {
  myservo.write(90);
  delay(5000);
//llamamos la funcion calcularDistancia() y guardamos su
//retorno en una variable
  delante();
  unsigned int distancia = calcularDistancia(trig, echo, true);
  Serial.println(distancia);
//  delay(200);
  if(distancia < 60){
    decide();
    }
    else{
    loop();
    }
}

/////////FUNCIONES DEL ROBOT////////////////////////////////

/////////FUNCIÓN CALCULAR DISTANCIA////////////////////////
int calcularDistancia(int trigPin, int echoPin, bool metric)
{
//Devuelve la distancia detectada por el sensor en centimetros o
//en pulgadas
 
int duracion;
int medida;
 
//En la documentacion establece que para iniciar una medicion
//hay que suministrar un pulso de 10 microsegundos
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
//Calcula el tiempo que tarda en recibir el eco
duracion = pulseIn(echoPin, HIGH);
 
//Si metric es cierto, devuelve la distancia en centimetros.
//Si no, devuelve la distancia en pulgadas.
//Aplicamos las formulas que aparecen en la documentacion
 
if(metric) medida = duracion/58;
else medida = duracion/148;
 
return medida;
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
 
  
