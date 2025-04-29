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

  if (light > 750) { // if it is bright
    digitalWrite(LED_BUILTIN, LOW);   
  }
  else { // if it is dark
    digitalWrite(LED_BUILTIN, HIGH);  

    myservo.write(-180); // full speed counter clockwise
    delay(275);         // rotate for 0.5 seconds
    myservo.write(90);  // stop
    delay(1000);        // wait
    delay(15);             // small movement delay
  }

  delay(500); // wait before next light check
}


