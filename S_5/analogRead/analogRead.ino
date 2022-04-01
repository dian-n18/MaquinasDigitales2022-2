const int analogReadPin = 33;
const int ledPin = 32;
const int THRESHOLD = 1000;
float luz;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
// Serial.println(analogRead(analogReadPin));
//1. Encienda el LED si la lecura pasa un umbral THRESHOLD

luz = analogRead(analogReadPin);
//  Serial.println(luz);
//  if(luz>=THRESHOLD){
//     digitalWrite(ledPin,HIGH);
//  } 
//  else{
//     digitalWrite(ledPin, LOW);
//  }

//Invoco la función en el loop
ledSwitch(luz);
  
  delay(10);
} 

// 2. Convertir la actividad anterior en una función llamada "ledSwitch"
void ledSwitch(float value){

    Serial.println(value);
    if (value<=THRESHOLD){
      digitalWrite(ledPin,HIGH);
    }
    else{
      digitalWrite(ledPin,LOW);
    }
}
