// Test Code

int randNumber = 0;
int score_counter = 0;
long timer_delay = 0;
bool runner = false;
long analog_button = 0;
long analog_slide = 0;
int analog_rotary = 0;

void setup() {
  pinMode(A4, INPUT); //Button
  pinMode(A0, INPUT); //Slider
  pinMode(5, INPUT); //Rotary
  pinMode(0, OUTPUT); //O1
  pinMode(1, OUTPUT); //O2
  pinMode(2, OUTPUT); //O3
  pinMode(3, OUTPUT); //O4
  pinMode(4, OUTPUT); //T1
  pinMode(5, OUTPUT); //T2
  pinMode(6, OUTPUT); //T3
  pinMode(7, OUTPUT); //T4
  pinMode(9, OUTPUT); // Speaker
  // Digital output pin for LED
  // ""
  // ""
  // Pin for SD card
  runner = false;
}

void loop() {
  if(runner == false){
    hex_output(0);
    delay(1000);
    runner = true;
  }
  while(runner == true){
    hex_output(2);
    analog_rotary = analogRead(5);
    analog_rotary = map(analog_rotary, 0, 1023, 0, 255);
    delay(5000);
    if(abs(map(analogRead(5), 0, 1023, 0, 255) - analog_rotary) > 50){
      hex_output(5);
      delay(1000);
    }
    else{
      hex_output(3);
      delay(1000);
    }
  }
}

void slide_toggler() {
  tone(9, 500);
  score_counter = score_counter + 1;
  hex_output(score_counter);
}

void rotary_toggler() {
  tone(9, 1000);
  score_counter = score_counter + 1;
  hex_output(score_counter);
}

void correct_input() {
  ++score_counter;
  hex_output(score_counter);
  // Make LED green
  if(score_counter == 99){
    // Announce game over
    // Delay for 10 seconds
  }
  else{
    // Decrement timer
  }
}

void wrong_input() {
  runner = false;
  // Make LED red
  // Delay for 10 seconds
}

void hex_output(int score) {
  int score_tens = score / 10;
  int score_ones = score % 10;
  if(score_tens % 2 == 1) {
    digitalWrite(4, HIGH);
  }
  else {
    digitalWrite(4, LOW);
  }
  if(score_tens % 4 >= 2) {
    digitalWrite(5, HIGH);
  }
  else {
    digitalWrite(5, LOW);
  }
  if(score_tens % 8 >= 4) {
    digitalWrite(6, HIGH);
  }
  else {
    digitalWrite(6, LOW);
  }
  if(score_tens % 16 >= 8) {
    digitalWrite(7, HIGH);
  }
  else {
    digitalWrite(7, LOW);
  }
  if(score_ones % 2 == 1) {
    digitalWrite(0, HIGH);
  }
  else {
    digitalWrite(0, LOW);
  }
  if(score_ones % 4 >= 2) {
    digitalWrite(1, HIGH);
  }
  else {
    digitalWrite(1, LOW);
  }
  if(score_ones % 8 >= 4) {
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(2, LOW);
  }
  if(score_ones % 16 >= 8) {
    digitalWrite(3, HIGH);
  }
  else {
    digitalWrite(3, LOW);
  }
}