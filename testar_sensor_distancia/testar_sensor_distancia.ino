#include <Ultrasonic.h>

const int echoPin1 = 5; 
//const int echoPin2 = 2; 
const int trigPin = 6; 

Ultrasonic ultrasonic(trigPin, echoPin1); //INICIALIZANDO OS PINOS DO ARDUINO

//Ultrasonic ultrasonic2(trigPin, echoPin2);

float distancia; //VARIÁVEL DO TIPO INTEIRO
String result; //VARIÁVEL DO TIPO STRING

void setup(){
  //pinMode(echoPin1, INPUT); //DEFINE O PINO COMO ENTRADA (RECEBE)
  //pinMode(trigPin, OUTPUT); //DEFINE O PINO COMO SAIDA (ENVIA)
  Serial.begin(9600); //INICIALIZA A PORTA SERIAL
  }
void loop(){
  
  distancia = ultrasonic.read(); 
  Serial.print("Distance in CM: ");
  Serial.println(distancia);
  delay(200);
  
}

