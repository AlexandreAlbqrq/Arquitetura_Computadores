unsigned long start_time=0, current_time=0;
char pinos [8]={13,12,14,27,26,25,33,32};
int pos=0, sent=0;

void setup() {
  Serial.begin(115200);
  start_time=millis();
  for(int i=0;i<8;i++){
    pinMode(pinos[i], OUTPUT);
  }
  digitalWrite(pinos[0],HIGH);
}

void loop() {
  current_time=millis();
  if(current_time-start_time>=250){
    digitalWrite(pinos[pos], LOW);
    if(pos==7){
      pos=0;
    }else{
      pos++;
    }
    digitalWrite(pinos[pos], HIGH);
    start_time+=250;
  }
}