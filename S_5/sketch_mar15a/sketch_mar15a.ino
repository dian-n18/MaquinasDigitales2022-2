const int digtialWritePin = 32;
const int digitalReadPin = 34;



void setup() {
  // put your setup code here, to run once:
  pinMode(digtialWritePin,  OUTPUT);
  pinMode(digitalReadPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(digtialWritePin, HIGH);
  Serial.println(digitalRead(digitalReadPin));
  delay(500);
  digitalWrite(digtialWritePin, LOW);
  Serial.println(digitalRead(digitalReadPin));
  delay(500);
}
