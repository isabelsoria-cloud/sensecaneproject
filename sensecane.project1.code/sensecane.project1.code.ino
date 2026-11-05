const int trigPin = 9;
const int echoPin = 10;

long duration;
int  distance;

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
}

void  loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,  HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration  = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance:  ");
  Serial.println(distance);


// Buzzer feedback
pinMode(8, OUTPUT);

if (duration == 0) {
  noTone(8);
  delay(100);
}

// Very close obstacle
else if (distance <= 20) {
  tone(8, 1000);
  delay(100);
}

// Medium distance
else if (distance <= 50) {
  tone(8, 1000);
  delay(150);
  noTone(8);
  delay(150);
}

// Far obstacle
else if (distance <= 100) {
  tone(8, 1000);
  delay(200);
  noTone(8);
  delay(600);
}

// No nearby obstacle
else {
  noTone(8);
  delay(100);
}
}


