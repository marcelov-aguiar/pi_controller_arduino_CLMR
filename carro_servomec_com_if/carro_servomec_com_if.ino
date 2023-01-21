

 #include <Ultrasonic.h>

//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 12;
int IN3 = 13;
int IN4 = 7;

int Enable1 = 10;
int Enable2 = 9;

// definicoes do sensor
const int echoPin1 = 5; 
const int echoPin2 = 0; 
const int trigPin = 6; 

Ultrasonic ultrasonic(trigPin, echoPin1); //INICIALIZANDO OS PINOS DO ARDUINO

int distancia;

//definicoes do controlador

float valor_ref = 15.0;
float faixa_erro, erro;
int KP = 3;
int KI = 2;
float last_time = 0;
float controleI=0;
int andar_frente;



void setup()
{
  //Define os pinos como saida da ponte H
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);

pinMode(Enable1, OUTPUT);
pinMode(Enable2, OUTPUT);

faixa_erro = valor_ref * 0.1; 
// definicoes dos pinos do sensor
//pinMode(echoPin1, INPUT); //DEFINE O PINO COMO ENTRADA (RECEBE)
//pinMode(trigPin, OUTPUT); //DEFINE O PINO COMO SAIDA (ENVIA)
Serial.begin(9600); //INICIALIZA A PORTA SERIAL

}
  
void loop()
{

  int controle;
  int distancia_medida;
  distancia_medida = ultrasonic.read();
  // 15 - 13
  erro = valor_ref - distancia_medida;
  if (abs(erro) > faixa_erro){
    if (erro < 0){
      andar_frente = 1;
      sentido(andar_frente);
    }else{
      andar_frente = 0;
      sentido(andar_frente);
    }
  }else{
    digitalWrite(Enable1, LOW);
    digitalWrite(Enable2, LOW);
  }

  delay(50);
}


void sentido(int andar_frente){
  if (andar_frente == 1){
    //Gira o Motor A no sentido horario
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    //Gira o Motor B no sentido horario
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    digitalWrite(Enable1, HIGH);
    digitalWrite(Enable2, HIGH);

  }else{
    //Gira o Motor A no sentido anti-horario
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    //Gira o Motor B no sentido anti-horario
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    digitalWrite(Enable1, HIGH);
    digitalWrite(Enable2, HIGH);
  }
}

//MÉTODO RESPONSÁVEL POR CALCULAR A DISTÂNCIA
int calc_distance(){
  int distance;
  distance = ultrasonic.read(); 
  return distancia;
 }