char pessoa=69;
int idade=21;
float money=12.60;
void setup() {
  Serial.begin(115200);
  Serial.printf("Pessoa = %d\n",pessoa);
  Serial.printf("Idade = %d\n", idade);
  Serial.printf("Money = %0.2f\n", money);
}

void loop() {
  // put your main code here, to run repeatedly:

}
