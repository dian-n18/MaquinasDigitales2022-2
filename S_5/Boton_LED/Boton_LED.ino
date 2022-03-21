#define digitalReadPin 35
#define digitalWritePin 32

bool pinStatus;
void setup() {
  Serial.begin(115200);
  pinMode(digitalReadPin, INPUT);
  pinMode(digitalWritePin, OUTPUT);
}

void loop() {
  Serial.println(digitalRead(digitalReadPin));
  pinStatus=digitalRead(digitalReadPin);

  if (pinStatus == HIGH){
    digitalWrite(digitalWritePin, HIGH);
  }else{ 
    digitalWrite(digitalWritePin, LOW);
  }
}
