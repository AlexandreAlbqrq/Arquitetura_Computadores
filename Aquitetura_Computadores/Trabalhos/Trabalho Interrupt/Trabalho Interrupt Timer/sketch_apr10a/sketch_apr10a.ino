#define ledRed 12
#define ledGreen 13
#define ledYellow 14
#define frequency 1000000 // 1MHz

hw_timer_t * timer_1=NULL;
hw_timer_t * timer_2=NULL;
hw_timer_t * timer_3=NULL;

void IRAM_ATTR timer1(){
  static bool state=false; 
  state=!state;
  digitalWrite(ledRed, state);
}

void IRAM_ATTR timer2(){
  static bool state=false; 
  state=!state;
  digitalWrite(ledGreen, state);
}

void IRAM_ATTR timer3(){
  static bool state=false;
  state=!state;
  digitalWrite(ledYellow, state);
}

void setup() {
  Serial.begin(115200);
  
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);

  timer_1=timerBegin(frequency);
  timerAttachInterrupt(timer_1, timer1);
  timerAlarm(timer_1, 500000, true, 0);
  
  timer_2=timerBegin(frequency);
  timerAttachInterrupt(timer_2, timer2);
  timerAlarm(timer_2, 250000, true, 0);
  
  timer_3=timerBegin(frequency);
  timerAttachInterrupt(timer_3, timer3);
  timerAlarm(timer_3, 125000, true, 0);
}

void loop() {
}
