int ledPin = 2; // GPIO with an external LED

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH); // on
  delay(500);
  digitalWrite(ledPin, LOW); // off
  delay(500);
}
