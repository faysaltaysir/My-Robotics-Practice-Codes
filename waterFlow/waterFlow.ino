// Water Flow Monitoring System

const int flowSensorPin = 2; // Connect the flow sensor to digital pin 2
volatile int pulseCount = 0; // Measure the number of pulses

float flowRate = 0.0; // Flow rate in liters per minute
unsigned int flowMilliLitres = 0; // Total accumulated flow in milliliters
unsigned long totalMilliLitres = 0; // Total accumulated flow in milliliters over time
unsigned long oldTime = 0; // Previous time

void setup() {
  Serial.begin(9600);
  pinMode(flowSensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(flowSensorPin), pulseCounter, FALLING);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - oldTime > 1000) { // Update every 1 second
    detachInterrupt(digitalPinToInterrupt(flowSensorPin)); // Disable interrupts while calculating flow rate
    flowRate = pulseCount / 7.5; // Convert pulses to flow rate in liters per minute (assuming 7.5 pulses per liter)
    flowMilliLitres = (flowRate / 60) * 1000; // Convert flow rate to milliliters per second
    totalMilliLitres += flowMilliLitres; // Accumulate total flow
    oldTime = currentTime; // Update old time
    pulseCount = 0; // Reset pulse count
    attachInterrupt(digitalPinToInterrupt(flowSensorPin), pulseCounter, FALLING); // Re-enable interrupts
  }

  // Your code here: Perform actions based on the water flow data
  // Example: Print flow rate and total flow to Serial Monitor
  Serial.print("Flow rate: ");
  Serial.print(flowRate);
  Serial.print(" L/min\t");
  Serial.print("Total flow: ");
  Serial.print(totalMilliLitres);
  Serial.println(" mL");
}

void pulseCounter() {
  pulseCount++;
}
