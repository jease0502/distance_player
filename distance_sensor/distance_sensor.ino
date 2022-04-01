//
int trigPin = 11;
int echoPin = 12;
int speakerpin = 7;
long duration, cm ;
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speakerpin, OUTPUT);
}
 
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;  

  Serial.println(cm);
   if (cm <= 5) {
    digitalWrite(speakerpin, HIGH);
    delay (20);
      }
  if (cm > 5 && cm <= 15) {
    digitalWrite(speakerpin, HIGH);
    delay (100);
    digitalWrite(speakerpin, LOW);
    delay (100);
   }
  if (cm > 15){
     digitalWrite(speakerpin, HIGH);
    delay (500);
    digitalWrite(speakerpin, LOW);
    delay (500);
      }
  delay(10); 
  }
