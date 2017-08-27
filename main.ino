const int PIN = A0;
int i = 0;
int sum = 0;

void setup() {
  pinMode(PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(PIN);

  i++;
  sum += reading;

  if (i == 10) {
    String t = String(sum / 10);
    Serial.println(t);
    Particle.publish("new_reading", t);
    i = 0;
    sum = 0;
  }

  delay(1000 * 60);
}
