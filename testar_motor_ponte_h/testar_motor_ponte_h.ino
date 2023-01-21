//Programa : Controle 2 motores DC usando Ponte H L298N
//Autor : FILIPEFLOP
 
//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 12;
int IN3 = 13;
int IN4 = 7;

int Enable1 = 10;
int Enable2 = 9;
  
void setup()
{
  //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);

pinMode(Enable1, OUTPUT);
pinMode(Enable2, OUTPUT);
digitalWrite(Enable1, HIGH); //Coloca nível alto em ENABLE para girar motor
digitalWrite(Enable2, HIGH);
}
  
void loop()
{
 //Gira o Motor A no sentido horario
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);

//Gira o Motor B no sentido horario
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 delay(1000);
 //Para o motor A
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);

 //Para o motor B
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, HIGH);
delay(1000);
 
 //Gira o Motor A no sentido anti-horario
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);

//Gira o Motor B no sentido anti-horario
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);

 delay(1000);
 //Para o motor A
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);

 //Para o motor B
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, HIGH);
 delay(1000);
}