volatile unsigned long counter=0;
unsigned long current_time=0;
int aux=0;

void IRAM_ATTR contar() {
  counter++;
}

void setup() {
  Serial.begin(115200);
  pinMode(12, INPUT_PULLUP);
  attachInterrupt(12, contar, FALLING);

}

void loop() {
  if(aux != counter){
    aux=counter;
    printf("%d\n", aux);
  }
}