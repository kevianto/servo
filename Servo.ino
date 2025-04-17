#include <Servo.h>

// Pin definitions
const int trigPin = 10;
const int echoPin = 11;
const int servoPin = 9;

// Distance threshold (object detection range)
const int threshold = 100; // in cm

Servo myServo;

void setup() {
  // Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0); // Start at 0 degrees
}

void loop() {
  long duration;
  int distance;

  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo duration
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance in cm
  distance = duration * 0.034 / 2;

  // Only respond if distance is within reasonable range
  if (distance > 0 && distance <= threshold) {
    myServo.write(90); // Rotate to 90 degrees
  } else {
    myServo.write(0);  // Return to 0 degrees
  }

  delay(700); // Small delay for stability
}
