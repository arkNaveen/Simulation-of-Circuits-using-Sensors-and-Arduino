int echo = 6;
int trig = 7;
int buzz = 13; 
int time;
int distance; 
int ir_pin=2;
void setup() 
{
  Serial.begin (9600); 
  pinMode (trig, OUTPUT); 
  pinMode (echo, INPUT);
  pinMode (buzz, OUTPUT);
  pinMode (ir_pin, INPUT);
}
void loop() 
{
    digitalWrite (trig, HIGH);
    delay(1);
    digitalWrite (trig, LOW);
    time = pulseIn (echo, HIGH);
    distance = (time * 0.034) / 2;

  if (distance <= 25) 
        {
        Serial.print (" Distance= ");              
        Serial.println (distance);        
        digitalWrite (buzz, HIGH);
    	if(digitalRead(2)==LOW)
          Serial.print("Motion detected by IR sensor");  // if the object is too close proximity sensor gets activated 
        delay (500);
        }
  else {
        Serial.print (" Distance= ");              
        Serial.println (distance);        
        digitalWrite (buzz, LOW);
        delay (500);        
       } 
}
