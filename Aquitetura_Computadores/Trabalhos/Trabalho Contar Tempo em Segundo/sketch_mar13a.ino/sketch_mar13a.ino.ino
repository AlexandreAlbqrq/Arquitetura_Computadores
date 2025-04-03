unsigned long start_time=0, current_time=0;
void setup() {
  Serial.begin(115200);
  start_time=millis();
}

void loop() {
  current_time=millis();
  if(current_time-start_time>=1000){
    printf("Passou um segundo\n");
    start_time=start_time+1000;
  }
}