void setup() {
  Serial.begin(115200); // Iniciar a ligação a uma velociadade de 115.200bps
  pinMode(13, OUTPUT); // Pino para o LED vermelho
  pinMode(14, OUTPUT); // Pino para o LED Azul
  pinMode(12, INPUT_PULLUP); // Pino para o Switch
}

void loop() {
  digitalWrite(13, !digitalRead(12)); // Ligar LED vermelho
  digitalWrite(14, digitalRead(12)); // Ligar LED Azul
}