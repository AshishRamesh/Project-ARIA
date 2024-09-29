const int pin1 = PC7;
const int pin2 = PD2;
const int pin3 = PD3;
const int pin4 = PD4;

const int out_pin1 = PC1;
const int out_pin2 = PC2;
const int out_pin3 = PC3;
const int out_pin4 = PC4;

void pinconfig(){
  pinMode(pin1, INPUT_PULLDOWN);
  pinMode(pin2, INPUT_PULLDOWN);
  pinMode(pin3, INPUT_PULLDOWN);
  pinMode(pin4, INPUT_PULLDOWN);

  pinMode(out_pin1, OUTPUT);
  pinMode(out_pin2, OUTPUT);
  pinMode(out_pin3, OUTPUT);
  pinMode(out_pin4, OUTPUT);
}

void setup() {
  Serial.begin(9600);
  pinconfig();
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
  
  Serial.print("Pin 2: ");
  Serial.println(state1);
  Serial.print("Pin 3: ");
  Serial.println(state2);
  Serial.print("Pin 4: ");
  Serial.println(state3);
  Serial.print("Pin 5: ");
  Serial.println(state4);
}
