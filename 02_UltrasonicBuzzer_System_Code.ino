int echo = 6;
int trig = 7;
int buzz = 13; 
int time;
int distance; 
void setup() 
{
  Serial.begin (9600); 
  pinMode (trig, OUTPUT); 
  pinMode (echo, INPUT);
  pinMode (buzz, OUTPUT);
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
        delay (500);
        }
  else {
        Serial.print (" Distance= ");              
        Serial.println (distance);        
        digitalWrite (buzz, LOW);
        delay (500);        
       } 
}