int roomTemp = 30; 
float celsius = 0;
float fahrenheit = 0;
int moistureValue; 
float moisture_percentage;
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  moistureValue = analogRead (A1); 
  moisture_percentage = ((moistureValue/539.00)*100); 
  Serial.print ("\nMoisture Value: "); 
  Serial.print (moisture_percentage); 
  Serial.print ("\n");
  
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
   fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print ("Temperature Value: "); 
  Serial.print(celsius);
  Serial.print(" C, ");
  
   if (celsius < roomTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }
  if (celsius >= roomTemp && celsius < roomTemp + 10) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  if (celsius >= roomTemp + 20) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  delay(1000); 
}