const int analogReadPin = 33;
const int ledPin = 32;


void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  Serial.println(analogRead(analogReadPin));
  delay(10);
}
