
const int potPin = A2;
const int greenButton = 2;
const int redButton = 3;
const int yellowButton = 4;
const int buzzerPin = 8;

void setup() {
  pinMode(greenButton, INPUT_PULLUP);
  pinMode(redButton, INPUT_PULLUP);
  pinMode(yellowButton, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);
  int pitch;

  if (digitalRead(greenButton) == LOW) {
    pitch = map(potValue, 0, 1023, 100, 2400);
  }

  else if (digitalRead(redButton) == LOW) {
    pitch = map(potValue, 0, 1023, 400, 3100);
  }

  else if (digitalRead(yellowButton) == LOW) {
    pitch = map(potValue, 0, 1023, 800, 4100);
  }

  else {
    pitch = map(potValue, 0, 1023, 200, 3400);
  }

  tone(buzzerPin, pitch);
  delay(20);
}
