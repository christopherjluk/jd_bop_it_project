// Test Code

int randNumber = 0;
int score_counter = 0;
long initial_time = 0;
long running_timer = 0;
bool timer_up = false;
bool runner = false;
bool inputSelected = false;
bool inputCorrect = false;
long analog_slide = 0;
int analog_rotary = 0;

void setup() {
  pinMode(A4, INPUT); //Button
  pinMode(A0, INPUT); //Slider
  pinMode(A5, INPUT); //Rotary
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
  if(runner == false){ // If statement for starting a new game
    hex_output(0);
    initial_time = 5000;
    runner = true;
  }
  while(runner == true){
    randNumber = random(1, 4);
    delay(1000);
    analog_slide = analogRead(0);
    analog_rotary = analogRead(5);
    if(randNumber == 1){
      inputSelected = false;
      running_timer = initial_time;
      timer_up = false;
      tone(9, 2000);
      digitalWrite(8, HIGH); // For testing purposes
      delay(2000);
      noTone(9);
      while(!timer_up && !inputSelected){
        delay(40);
        if(analogRead(4) > 200){
          inputSelected = true;
          inputCorrect = true;
        }
        else if(abs(analog_slide - analogRead(0)) > 50){
          inputSelected = true;
          inputCorrect = false;
        }
        else if(abs(analog_rotary - analogRead(5)) > 50){
          inputSelected = true;
          inputCorrect = false;
        }
        else{
          running_timer -= 40;
          if(running_timer == 0)
            timer_up = true;
        }
      }
      digitalWrite(8, LOW); // For testing purposes
      if(inputSelected and inputCorrect)
        correct_input();
      else
        wrong_input();
    }
    else if(randNumber == 2){
      inputSelected = false;
      running_timer = initial_time;
      tone(9, 1000);
      digitalWrite(8, HIGH); // For testing purposes
      delay(2000);
      noTone(9);
      while(!timer_up && !inputSelected){
        delay(40);
        if(abs(analog_slide - analogRead(0)) > 50){
          inputSelected = true;
          inputCorrect = true;
        }
        else if(analogRead(4) > 200){
          inputSelected = true;
          inputCorrect = false;
        }
        else if(abs(analog_rotary - analogRead(5)) > 50){
          inputSelected = true;
          inputCorrect = false;
        }
        else{
          running_timer -= 40;
          if(running_timer == 0)
            timer_up = true;
        }
      }
      digitalWrite(8, LOW); // For testing purposes
      if(inputSelected and inputCorrect)
        correct_input();
      else
        wrong_input();
    }
    else if(randNumber == 3){
      inputSelected = false;
      running_timer = initial_time;
      timer_up = false;
      tone(9, 500);
      digitalWrite(8, HIGH); // For testing purposes
      delay(2000);
      noTone(9);
      while(!timer_up && !inputSelected){
        delay(40);
        if(abs(analog_rotary - analogRead(5)) > 50){
          inputSelected = true;
          inputCorrect = true;
        }
        else if(analogRead(4) > 200){
          inputSelected = true;
          inputCorrect = false;
        }
        else if(abs(analog_slide - analogRead(0)) > 50){
          inputSelected = true;
          inputCorrect = false;
        }
        else{
          running_timer -= 40;
          if(running_timer == 0)
            timer_up = true;
        }
      }
      digitalWrite(8, LOW); // For testing purposes
      if(inputSelected and inputCorrect)
        correct_input();
      else
        wrong_input();
    }
  }
}

void correct_input() {
  ++score_counter;
  hex_output(score_counter);
  delay(3000); // For testing purposes
  // Make LED green
  if(score_counter == 99){
    // Announce game over (and possibly delay)
    game_end();
  }
  else
    initial_time -= 40;
}

void wrong_input() {
  // Announce game over (and possibly delay)
  // Make LED red
  game_end();
}

void game_end() {
  while(true){}
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
