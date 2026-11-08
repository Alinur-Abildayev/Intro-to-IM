const int trig = 3;
const int echo = 4;
const int switchPin = 2;
const int led = 9;

int brightness = 0;
int fadeAmount = 5;

void setup() {
  Serial.begin(9600);

  pinMode(led, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(switchPin, INPUT);
}

void loop() {

  int switchState = digitalRead(switchPin);

  if (switchState == HIGH) {
  
    //For this part with ultrasonic sensor, I used Gemini AI to help me figure out how to set it up
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long sensorValue = pulseIn(echo, HIGH);

    if (sensorValue > 0 && sensorValue < 1200) {
      analogWrite(led, brightness);

      brightness = brightness + fadeAmount;

      if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
      }
      
      delay(5); 

    } else {
      analogWrite(led, 0);
      brightness = 0;
      delay(50);
    }

  } else {
    analogWrite(led, 0);
    brightness = 0;
    delay(100); 
  }
}
