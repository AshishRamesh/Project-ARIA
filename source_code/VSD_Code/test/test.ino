const int pin1 = PD1;
const int pin2 = PD2;
const int pin3 = PD3;
const int pin4 = PD4;

const int out_pin1 = PD7;
const int out_pin2 = PA1;
const int out_pin3 = PA2;
const int out_pin4 = PD0;

const int PIN_RED   = PC0; 
const int PIN_GREEN = PC3; 
const int PIN_BLUE  = PC4; 
  
int red             = 254;
int green           = 1;
int blue            = 127;
int red_direction   = -1;
int green_direction = 1;
int blue_direction  = -1;

int count = 0;

void pinconfig(){
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);

  pinMode(out_pin1, OUTPUT);
  pinMode(out_pin2, OUTPUT);
  pinMode(out_pin3, OUTPUT);
  pinMode(out_pin4, OUTPUT);

  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
}

void setColor(int R, int G, int B) {
  analogWrite(PIN_RED,   R);
  analogWrite(PIN_GREEN, G);
  analogWrite(PIN_BLUE,  B);
}

void led_blink(int R, int G,int B){
  setColor(R, G, B);
  delay(250);
  setColor(0, 0, 0);
  delay(250);
  setColor(R, G, B);
  delay(250);
  setColor(0, 0, 0);
  delay(250);
}

void start_seq(){
for(int i =0; i<=400; i++){
  red = red + red_direction;   
  green = green + green_direction;
  blue = blue + blue_direction;
 
  //now change direction for each color if it reaches 255
  if (red >= 255 || red <= 0)
  {
    red_direction = red_direction * -1;
  }
  if (green >= 255 || green <= 0)
  {
    green_direction = green_direction * -1;
  }
  if (blue >= 255 || blue <= 0)
  {
    blue_direction = blue_direction * -1;
  }
  setColor(red, green, blue);
  delay(5); 
  }
  led_blink(0,255,0);
}

void led_off(int a, int b, int c, int d){
  if (a && b && c && d == 0){
    count++;
  }
  else if (count == 5000){
    led_blink(255,255,255);
  }
  else {
    count = 0;
  }
  
}

void set_bot_stat(int a, int b, int c, int d){
  if (a || b || c || d == 1){
    setColor(0, 255, 0);
  }
  else if (a || b || c || d == 0){
    setColor(255, 0, 0);
  }
}

void setup() {
  Serial.begin(9600);
  pinconfig();
  start_seq();
}

void loop() {
  int state1 = digitalRead(pin1);
  int state2 = digitalRead(pin2);
  int state3 = digitalRead(pin3);
  int state4 = digitalRead(pin4);

  digitalWrite(out_pin1,state1);
  digitalWrite(out_pin2,state2);
  digitalWrite(out_pin3,state3);
  digitalWrite(out_pin4,state4);
  
  set_bot_stat(state1, state2, state3, state4);
  led_off(state1, state2, state3, state4);
  Serial.print("Pin 2: ");
  Serial.println(state1);
  Serial.print("Pin 3: ");
  Serial.println(state2);
  Serial.print("Pin 4: ");
  Serial.println(state3);
  Serial.print("Pin 5: ");
  Serial.println(state4);
}
