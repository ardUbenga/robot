int Trig=8;
int Echo=10;
 
//Variable en la que se va a almacenar el valor correspondiente a la distancia
int Dist; 
void setup() {
 
pinMode (Trig, OUTPUT);
pinMode (Echo, INPUT);
Serial.begin(9600); 
}
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
 
void loop() {
int centimetros=ultrasonido ();
//Serial.print("Distancia: ");
Serial.println(centimetros);
//Serial.println(" Cm");
if(centimetros <= 10)
  {
     Serial.println("Que se choca");
  }
 
delay (300);
}
