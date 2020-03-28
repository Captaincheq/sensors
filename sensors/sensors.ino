#define trigPin1 11
#define trigPin2 3
#define trigPin3 13
#define echoPin1 12
#define echoPin2 4
#define echoPin3 2

float duration1, distance1, duration2, distance2, duration3, distance3;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
}

void loop() {
  //write a pulse to the ...

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 / 2) * 0.0343;

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) * 0.0343;

  Serial.print("Distance = ");
  if (distance1 >= 400 || distance1<=2) {
    Serial.print("Out of range");
  }
  else {
    Serial.print(distance1);
    Serial.println(" cm");
    delay(500);
  }
  delay(500);
}
