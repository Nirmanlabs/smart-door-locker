#include <Servo.h>

Servo doorServo;

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;

long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  doorServo.attach(servoPin);

  doorServo.write(0);
  Serial.begin(9600);
 
}
void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);
  distance = duration * 0.034/2;

  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= 20)
  {
    Serial.println("Door Opening");
    doorServo.write(90);
    delay(5000);

    Serial.println("Door Closing");

  
    doorServo.write(0);
    delay(1000);
  }

}