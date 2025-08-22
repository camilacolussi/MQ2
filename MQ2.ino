/*
QM2 Smoke detector + LED

HARDWARE:
Arduino UNO
QM2 smoke detector
LED
220 ohms resistor

*/

#define ledPin 6
#define sensorPin A0

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); //LED starts off
}

void loop() {
  Serial.print("Analog output: ");
  Serial.println(readSensor()); //print sensor signal on every loop
  delay(500);
}

int readSensor() {
  unsigned int sensorValue = analogRead(sensorPin);  // Read the sensor signal
  unsigned int outputValue = map(sensorValue, 0, 1023, 0, 255); // map the 10-bit data (analog) to 8-bit data (digital)

  if (outputValue > 65)
    analogWrite(ledPin, outputValue); // dim LED based on sensor signal, where 65 means a gass is detected, and 255 is high gas signal. 
  else
    digitalWrite(ledPin, LOW); //LED off
  return outputValue;             // Return analog moisture value
}
