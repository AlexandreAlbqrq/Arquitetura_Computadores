/////////////////////////////
//Trabalho Final Proposta 2//
/////////////////////////////

//Variáveis//
unsigned long startTime=0, currentTime=0;
bool bright=false;
long duration;
int distance=0, y=0, pins[8]={13,12,14,27,26,25,33,32};

//Define//
#define trigPin 2 // OUTPUT
#define echoPin 15 //INPUT

//Função Interrupt//
void distanceRead(){
  y=(0.08*distance)+0.6; // Formula para ligar leds proporcionalmente à distância
  printf("Nº de LEDs: %d\n", y);
  if(y>8){
    y=8;
  }
  for(int i=0; i<=y; i++){
    digitalWrite(pins[i], !bright);
    printf("////////////////////////////////////////////////\n");
  }
}

void setup(){
  Serial.begin(115200);
  for (int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  attachInterrupt(15, distanceRead, CHANGE);
  startTime=millis();
}

void loop(){
  digitalWrite(pins[0], bright);
  digitalWrite(pins[1], bright);
  digitalWrite(pins[2], bright);
  digitalWrite(pins[3], bright);
  digitalWrite(pins[4], bright);
  digitalWrite(pins[5], bright);
  digitalWrite(pins[6], bright);
  digitalWrite(pins[7], bright);
  
  currentTime=millis();
  digitalWrite(trigPin, LOW);
  if(currentTime-startTime>=0.002){ // Manter o trigger no LOW por 2 microsegundos para limpar ruidos ou valores anteriores
    digitalWrite(trigPin, HIGH);
    startTime+=0.002;
    if(currentTime-startTime>=0.01){ // Enviar um ultrasom por 10 microsegundos pois é o requerido para funcionar
      digitalWrite(trigPin, LOW); // Terminar o ultrasom
      duration = pulseIn(echoPin, HIGH);
      distance = duration * 0.034 / 2;
      printf("Distancia: %d\n", distance);
      startTime+=0.01;
    }
  }
}
