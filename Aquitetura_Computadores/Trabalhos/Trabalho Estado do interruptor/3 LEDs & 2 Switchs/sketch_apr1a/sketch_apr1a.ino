void setup() {
  Serial.begin(115200);
  pinMode(12, OUTPUT);//azul
  pinMode(13, OUTPUT);//vermelho
  pinMode(14, OUTPUT);//verde
  pinMode(27, INPUT_PULLUP);//Rosa
  pinMode(26, INPUT_PULLUP);//Laranja
}

void loop() {
  /*
  Operação AND -- LED Vermelho
  Operação OR  -- LED Azul
  Operação XOR -- LED Verde
  */
  if((digitalRead(26)==HIGH & digitalRead(27)==LOW) | (digitalRead(26)==LOW & digitalRead(27)==HIGH)){
    digitalWrite(12, !digitalRead(27));
    digitalWrite(14, !digitalRead(27));
    printf("LED Azul Ligado\n");
    printf("LED Verde Ligado\n");
  }else if(digitalRead(26)==LOW & digitalRead(27)==LOW){
    digitalWrite(13, !digitalRead(26));
    digitalWrite(13, !digitalRead(26));
    printf("LED Vermelho Ligado\n");
    printf("LED Azul Ligado\n");
  }else if(digitalRead(26)==HIGH & digitalRead(27)==HIGH){
    digitalWrite(12, !digitalRead(26));
    digitalWrite(13, !digitalRead(26));
    digitalWrite(14, !digitalRead(26));
  }
}