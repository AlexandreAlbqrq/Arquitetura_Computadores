unsigned long start_time=0, current_time=0, start_time1=0, current_time1=0;
bool bright=false;
#define freq 3
#define transition_time 500*freq

void setup() {
  Serial.begin(115200);
  start_time=millis();
  pinMode(13, OUTPUT);// VERMELHO
  pinMode(12, OUTPUT);// AMARELO
  //pinMode(14, OUTPUT);// VERDE
}

void loop() {
  current_time=millis();
  if(current_time-start_time>=transition_time){
    /*
    if(bright == true){
      printf("%d\n",bright);
    }else{
      printf("%d\n",bright);
    }
    */
    /*
    if(bright == true){
      printf("ON\n");
    }else{
      printf("OFF\n");
    }
    */
    start_time+=transition_time;
  }

  if(current_time1-start_time1>=transition_time){
    /*
    if(bright == true){
      printf("%d\n",bright);
    }else{
      printf("%d\n",bright);
    }
    */
    /*
    if(bright == true){
      printf("ON\n");
    }else{
      printf("OFF\n");
    }
    */
    start_time+=transition_time;
  }
}