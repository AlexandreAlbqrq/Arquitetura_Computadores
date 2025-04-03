unsigned char PWM=0;
unsigned long current_time=0, start_time=0;
int sent=0;

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
    if(PWM==255){
      sent=1;
    }else if(PWM==0){
      sent=0;
    }
    if(sent==0){
      PWM++;
    }else{
      PWM--;
    }
    ledcWrite(pinLED, PWM);
    start_time+=transition_time;
  }
}