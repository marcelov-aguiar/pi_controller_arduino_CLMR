

 #include <Ultrasonic.h>

//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 12;
int IN3 = 13;
int IN4 = 7;

int Enable1 = 10;
int Enable2 = 9;

// definicoes do sensor
const int echoPin1 = 2; 
const int echoPin2 = 0; 
const int trigPin = 3; 

Ultrasonic ultrasonic(trigPin, echoPin1); //INICIALIZANDO OS PINOS DO ARDUINO

int distancia;

//definicoes do controlador

int valor_ref = 15;
int KP = 4;
int KI = 0.5;
float last_time = 0;
float controleI=0;

void setup()
{
  //Define os pinos como saida da ponte H
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);

pinMode(Enable1, OUTPUT);
pinMode(Enable2, OUTPUT);

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
 controle = ControlerPI(valor_ref, distancia_medida, KP, KI);

 sentido(valor_ref, distancia_medida);

 analogWrite(Enable1, controle);
 analogWrite(Enable2, controle);

 delay(100);
}

int ControlerPI(float valor_ref, float valor_in, float kp, float ki){
  float erro, controleP = 0, sinalControle;
  float dt;
  int pwm;

  //dt = millis();
  erro = valor_ref - valor_in;
  controleP= erro * kp;// Controle proporcional
  dt = millis() - last_time; // calcula delta t
  controleI = controleI + erro * ki * dt * 1/1000;// Controle integral
  sinalControle = controleP + controleI;
  sinalControle = abs(sinalControle);
  last_time = millis();

  // Limita o sinal de controle entre 0 e 5
  if (sinalControle > 5){
    sinalControle = 5;
  }
  if (sinalControle < 0){
    sinalControle = 0;
  }

  //converter o sinal de controle para 0 255
  pwm = map(sinalControle, 0, 5, 0, 255);
  return pwm;
}

void sentido(float valor_ref, float valor_in){
  if (valor_ref < valor_in){
    //Gira o Motor A no sentido horario
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    //Gira o Motor B no sentido horario
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }else{
    //Gira o Motor A no sentido anti-horario
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    //Gira o Motor B no sentido anti-horario
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
}

//MÉTODO RESPONSÁVEL POR CALCULAR A DISTÂNCIA
int calc_distance(){
  int distance;
  distance = ultrasonic.read(); 
  return distancia;
 }