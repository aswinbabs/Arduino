

int LED1 = 13;
int buzzer = 10;
int smokeA0 = A5;
int sensorThreshold = 400;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThreshold)
  {
    digitalWrite(LED1, HIGH);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(LED1, LOW);
    noTone(buzzer);
  }
  delay(100);
}