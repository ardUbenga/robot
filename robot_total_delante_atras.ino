#include <Servo.h>
Servo myservo;  // crear objeto para controlar el servo
#define trig 8
#define echo 9
int motoraa=3;
int motorab=5;
int motorba=6;
int motorbb=7;
int velocidad=255;
int velocidad1=150;
int i; 
int d;
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
    parar();
    myservo.write(0);
    unsigned int i=calcularDistancia(trig, echo, true); 
    delay(500);
    Serial.print("Izquierda= ");
    Serial.println(i);
    myservo.write(180);
    unsigned int d=calcularDistancia(trig, echo, true);
    delay(500); 
    Serial.print("Derecha= ");
    Serial.println(d);
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
 analogWrite(motoraa,0);
 analogWrite(motorab,velocidad1);
 analogWrite(motorba,0);
 analogWrite(motorbb,velocidad1);
}

void detras()
{
 Serial.println("Detrás");
 analogWrite(motoraa,velocidad1);
 analogWrite(motorab,0);
 analogWrite(motorba,velocidad1);
 analogWrite(motorbb,0);
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
 analogWrite(motoraa,0);
 analogWrite(motorab,velocidad1);
 analogWrite(motorba,0);
 analogWrite(motorbb,0);
}

void derecha()
{
 Serial.println("Giro Derecha");
 analogWrite(motoraa,0);
 analogWrite(motorab,0);
 analogWrite(motorba,0);
 analogWrite(motorbb,velocidad1);
}


//////////FUNCION QUE DECIDE QUE HACER/////////////////
void decide()
{
  if(i>d)
    {
      Serial.println("Giro Izquierda");
      delay(2000);
      parar();
      detras();
      izquierda();
    }else{
      Serial.println("Giro Derecha");
      delay(2000);
      parar();
      detras();
      derecha();
    }
  //Si i<d,parar,atrás,parar,girar a la derecha,para,delante. 
}  
