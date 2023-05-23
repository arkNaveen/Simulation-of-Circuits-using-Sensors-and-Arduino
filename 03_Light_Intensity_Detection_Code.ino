// C++ code
//
int thresh=200;
int lightIntensity;
int slideswitch=2;
float amb_light_sensor;
float calibrator;
void setup()
{
  pinMode(slideswitch, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  lightIntensity=analogRead(A0);
  calibrator=analogRead(A3);
  amb_light_sensor=calibrator*1.876;   //calibration of the ambient light sensor
  if(digitalRead(slideswitch)==HIGH){
    if(lightIntensity<thresh){
      digitalWrite(LED_BUILTIN,HIGH);
    }
    else{
     digitalWrite(LED_BUILTIN,LOW);
    }
    Serial.print("Photoresistor Light intensity :");
    Serial.print(lightIntensity);
    Serial.print("\n");
    delay(1000);
  }
  else{
    if(amb_light_sensor<thresh)
      digitalWrite(LED_BUILTIN,HIGH);
   	else
      digitalWrite(LED_BUILTIN,LOW);
    Serial.print("Ambient Light Sensor Reading :");
    Serial.print(amb_light_sensor);
    Serial.print("\n");
    delay(1000);
  }
}