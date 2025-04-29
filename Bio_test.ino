#include <Servo.h>
Servo myservo;

int pos = 0;      // current servo position
int light = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  light = analogRead(A5);
  Serial.println(light);  

  if (light > 300) { // if it is bright
    digitalWrite(LED_BUILTIN, LOW);   
  }
  else { // if it is dark
    digitalWrite(LED_BUILTIN, HIGH);  

    // Move servo slightly forward
    pos += 30;              // Move 5 degrees more each time
    if (pos > 180) {
      pos = 0;             // Reset back to 0 if we reach the end
    }
    myservo.write(pos);    // Move servo to new position
    delay(15);             // small movement delay
  }

  delay(500); // wait before next light check
}
