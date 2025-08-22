/*
Monitor MQ2 sensing

HARDWARE:
Arduino UNO
QM2 smoke detector

*/

int gas_sensor = A0;
int sensorValue;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(gas_sensor);
  Serial.print("MQ2 Sensor Value: ");
  Serial.println(sensorValue);
  delay(1000);
}
