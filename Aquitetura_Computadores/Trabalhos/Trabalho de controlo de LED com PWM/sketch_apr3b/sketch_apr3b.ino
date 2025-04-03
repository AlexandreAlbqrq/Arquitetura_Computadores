unsigned char PWM=0;
unsigned long current_time=0, start_time=0;

#define freq 500
#define bits 8
#define transition_time 2048/256
#define pinLED 12

void setup() {
  Serial.begin(115200);
  ledcAttach(pinLED, freq, bits);
  start_time=millis();
}

void loop() {
  current_time=millis();
  if(current_time-start_time>=transition_time){
    ledcWrite(pinLED, PWM);
    PWM++;
    start_time+=transition_time;
  }
}
