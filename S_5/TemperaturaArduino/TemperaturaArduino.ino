const int TEMP_SENSOR = 13;
const int LED_PIN = 32;


void setup() {
 Serial.begin(115200);
 pinMode(LED_PIN, OUTPUT);
}

void loop() {
  //Conversiones:
  // Serial.println(analogRead(TEMP_SENSOR));
  //Serial.println(analogRead(TEMP_SENSOR)*0.0008); //Volts
  //Serial.println(analogRead(TEMP_SENSOR)*0.8); //miliVolts
  //Serial.println(analogRead(TEMP_SENSOR)*0.8/10); //C°
  
  Serial.println(adc2celcius(analogRead(TEMP_SENSOR)));
  
  delay(10);
}

//función
float adc2celcius(float adc_value){
  return adc_value*0.08;
}
