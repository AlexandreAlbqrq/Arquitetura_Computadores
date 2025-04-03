unsigned long LDR=0 Range=0, Histerese=70;

void setup() {
  Serial.begin(115200);
  pinMode(36, INPUT);
  pinMode(26, OUTPUT);
  start_time=millis();
}

void loop() {
  current_time=millis();
  LDR=analogRead(36);
  Range=LDR/2;
  if(LDR<=Range-Histerese){
    digitalWrite(26, HIGH);
  }
  if(LDR>=Range+Histerese){
    digitalWrite(26, LOW);
  }
}
