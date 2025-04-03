unsigned long start_time12=0, current_time12=0, start_time13=0, current_time13=0;
bool bright12=true, bright13=true;
#define freq12 1
#define freq13 10
#define transition_time12 500/freq12
#define transition_time13 500/freq13

void setup() {
  Serial.begin(115200);
  start_time12=millis();
  start_time13=millis();
  pinMode(12, OUTPUT);// AMARELO
  pinMode(13, OUTPUT);// VERMELHO
  //pinMode(14, OUTPUT);// VERDE
}

void loop() {
  current_time12=millis();
  if(current_time12-start_time12>=transition_time12){
    digitalWrite(12, bright12);
    bright12=!bright12;
    if(bright12 == true){
      printf("Pino 12 ON\n");
    }else{
      printf("Pino 12 OFF\n");
    }
    start_time12+=transition_time12;
  }
  current_time13=millis();
  if(current_time13-start_time13>=transition_time13){
    digitalWrite(13, bright13);
    bright13=!bright13;
    if(bright13 == true){
      printf("Pino 13 ON\n");
    }else{
      printf("Pino 13 OFF\n");
    }
    start_time13+=transition_time13;
  }
}