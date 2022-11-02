const int echo_pin = 13;
const int trig_pin = 12;
void setup() {
  Serial.begin(9600);
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);

}

void loop() {
  double period, distance;
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  period = pulseIn(echo_pin, HIGH);
  distance = (period / 2) / 29.1;
  distance = distance / 100; //to convert cm to m
  delay(500);
  Serial.println(distance);

}
