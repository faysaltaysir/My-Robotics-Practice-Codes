const int flowSensorPin = 2; // Digital pin to which the flow sensor is connected
volatile int pulseCount = 0; // Measure the number of pulses

void setup() {
  Serial.begin(9600);
  pinMode(flowSensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(flowSensorPin), pulseCounter, FALLING);
}

void loop() {
  // Your main code here

  // Read and print the raw pulse count
  int rawPulseCount = pulseCount;
  Serial.print("Raw Pulse Count: ");
  Serial.println(rawPulseCount);

  // Reset the pulse count after reading
  pulseCount = 0;

  delay(1000); // Adjust the delay based on your application
}

void pulseCounter() {
  pulseCount++;
}
