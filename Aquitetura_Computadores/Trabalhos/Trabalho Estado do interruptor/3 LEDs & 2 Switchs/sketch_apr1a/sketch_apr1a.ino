void setup() {
  Serial.begin(115200);
  pinMode(12, OUTPUT);//azul
  pinMode(13, OUTPUT);//vermelho
  pinMode(14, OUTPUT);//verde
  pinMode(27, INPUT_PULLUP);//Rosa
  pinMode(26, INPUT_PULLUP);//Laranja
}

void loop() {
  //Operação AND -- LED Vermelho
  digitalWrite(13, !digitalRead(26) & !digitalRead(27));
  //Operação OR  -- LED Azul
  digitalWrite(12, !digitalRead(26) | !digitalRead(27));
  //Operação XOR -- LED Verde
  digitalWrite(14, !digitalRead(26) ^ !digitalRead(27));
}