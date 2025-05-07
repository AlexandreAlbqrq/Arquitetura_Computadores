///////////////////////////// 
//Trabalho Final Proposta 2// 
///////////////////////////// 
 
//Variáveis// 
unsigned long startTime=0, currentTime=0;
bool bright=false;
long duration;
int distance=0, pins[8]={13,12,14,27,26,25,33,32};
volatile int numLEDs=0;

//Define//
#define trigPin 2 // OUTPUT
#define echoPin 15 //INPUT

//Função Interrupt// 
void distanceRead(){
  numLEDs=(0.08*distance)+0.6; // Formula para ligar leds proporcionalmente à distância
  if(numLEDs==0){
    for(int i=0;i<8;i++){
      digitalWrite(pins[i], bright);
    }
  }else if(numLEDs>=8){
    numLEDs=8;
    for(int i=0;i<numLEDs;i++){
      digitalWrite(pins[i], !bright);
    }
  }else{
    for(int i=0;i<numLEDs;i++){
      digitalWrite(pins[i], !bright); //acender e apagar sem piscar
    }
    for(int i=7; i>=numLEDs; i--){
      digitalWrite(pins[i], bright);
    }
  }
}

void setup(){
  Serial.begin(115200);
  for (int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], bright);
  }
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  attachInterrupt(echoPin, distanceRead, FALLING); // NÃO RISING -- 0...1 -- echo só tem valores quando -- 1...0 -- FALLING
  startTime=millis();
}

void loop(){
  currentTime=millis();
  if(currentTime-startTime>=50){
    digitalWrite(trigPin, LOW);
    if(currentTime-startTime>=0.002){ // Manter o trigger no LOW por 2 microsegundos -- 0.002 millis para limpar ruidos ou valores anteriores
      digitalWrite(trigPin, HIGH);
      startTime+=0.002;
      if(currentTime-startTime>=0.01){ // Enviar um ultrasom por 10 microsegundos -- 0.01 millis pois é o requerido para funcionar
        digitalWrite(trigPin, LOW); // Terminar o ultrasom
        duration = pulseIn(echoPin, HIGH);
        distance = duration * 0.034 / 2; //distance = (traveltime/2) x speed of sound = 340 𝑚/s = 0.034cm/us
        startTime+=0.01;
        printf("%d - %d\n", distance, numLEDs);
      }
    }
    startTime+=50;
  }
}