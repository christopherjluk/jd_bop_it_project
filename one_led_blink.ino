void setup() {
  pinMode(9, INPUT);
  pinMode(8, OUTPUT);
}

// Delay of 75 allows my circuit to work as normal
void loop() {
  while(digitalRead(9) == HIGH){
    digitalWrite(8, HIGH);
    delay(75); // Not sure why, but a delay of 1000 gives me a delay of around 20ish seconds
    digitalWrite(8, LOW);
    delay(75); // Same as before
  }
}
