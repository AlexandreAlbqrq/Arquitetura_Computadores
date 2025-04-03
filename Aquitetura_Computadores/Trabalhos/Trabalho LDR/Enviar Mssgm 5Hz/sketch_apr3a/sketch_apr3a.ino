unsigned long start_time=0, current_time=0, LDR=0;

void setup() {
  Serial.begin(115200);
  pinMode(36, INPUT);
  start_time=millis();
}

void loop() {
  current_time=millis();
  LDR=alongRead(36);
  if(current_time-start_time>=200){
    printf("%d\n", LDR);
  }
}
