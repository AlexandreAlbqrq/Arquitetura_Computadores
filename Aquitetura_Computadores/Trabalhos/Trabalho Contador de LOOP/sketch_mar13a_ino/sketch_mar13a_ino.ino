unsigned long start_time=0, current_time=0;
int contador=0;
void setup() {
  Serial.begin(115200);
  start_time=millis();
}

void loop() {
  current_time=millis();
  contador++;
  if(current_time-start_time>=1000){
    Serial.printf("Passou um segundo.\n");
    Serial.printf("A função LOOP foi percurrida %d vezes.\n", contador);
    start_time=start_time+1000;
    contador=0;
  }
}