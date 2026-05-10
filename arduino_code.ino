// Motion Detection Alarm System

int pirsensor = 0;   // Variable to store PIR sensor value

void setup()
{
  pinMode(A0, INPUT);      // PIR sensor input pin
  Serial.begin(9600);      // Start serial monitor

  pinMode(7, OUTPUT);      // Green LED
  pinMode(6, OUTPUT);      // Red LED
  pinMode(10, OUTPUT);     // Buzzer
}

void loop()
{
  // Read PIR sensor value
  pirsensor = analogRead(A0);

  // Print sensor value
  Serial.println(pirsensor);

  // No motion detected
  if (pirsensor < 100) {

    digitalWrite(7, HIGH);   // Green LED ON
    digitalWrite(6, LOW);    // Red LED OFF
  }

  // Motion detected
  else {

    digitalWrite(6, HIGH);   // Red LED ON
    digitalWrite(7, LOW);    // Green LED OFF

    tone(10, 92, 100);       // Buzzer sound
  }

  delay(10);   // Small delay
}