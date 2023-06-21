//Dane Krall
//Christopher Luk
//Cara Buck
//Krishna Annambhotla
void setup() {
  pinMode(9, INPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  while(digitalRead(9) == HIGH){
    digitalWrite(8, HIGH);
    delay(75); // Not sure why, but a delay of 1000 gives me a delay of around 20ish seconds
    digitalWrite(8, LOW);
    delay(75); // Same as before
  }
}
