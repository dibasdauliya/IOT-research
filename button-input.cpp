int buttonPin = 15;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  int state = digitalRead(buttonPin);
  if (state == LOW) {
    Serial.println("Button Pressed!");
  }
  delay(200);
}
