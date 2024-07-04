#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

const int PulseWire = 0;
const int LED = 12;
const int LED2 = 13;
int Threshold = 550;


const int flowSensorPin = 2; // Connect the flow sensor to digital pin 2
volatile int pulseCount = 0; // Measure the number of pulses

float flowRate = 0.0; // Flow rate in liters per minute
unsigned int flowMilliLitres = 0; // Total accumulated flow in milliliters
unsigned long totalMilliLitres = 0; // Total accumulated flow in milliliters over time
unsigned long oldTime = 0; // Previous time


PulseSensorPlayground pulseSensor;

void setup() {
  Serial.begin(9600);
  pinMode(flowSensorPin, INPUT);
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(flowSensorPin), pulseCounter, FALLING);
  pulseSensor.analogInput(PulseWire);
  pulseSensor.blinkOnPulse(LED2);
  pulseSensor.setThreshold(Threshold);

  if (pulseSensor.begin()) {
    Serial.println("PulseSensor Object created!");
  }
}

void loop() {
  int heartRate;
  while (pulseSensor.sawStartOfBeat()) {
    heartRate = pulseSensor.getBeatsPerMinute();
    Serial.println("♥ A HeartBeat Happened!");
    Serial.print("Heart Rate: ");
    Serial.println(heartRate);
    float salineNeeded = map(heartRate, 30, 120, 100, 500); // Map heart rate to saline needed (60-120 BPM to 100-500 ml)
    
   
      Serial.print("Saline Needed: ");
      Serial.println(salineNeeded);
      waterFlow(salineNeeded);
   
    // Example: Linear relationship between heart rate and saline needed
    // This is a fictional and simplistic example. Consult with a medical professional for accurate information.
  
  }
  
  delay(20);
}





void waterFlow(int value) {
  totalMilliLitres=0;pulseCount=0;
  delay(5000);
  Serial.println("starting pump");
  
  while(1){
  unsigned long currentTime = millis();

  if (currentTime - oldTime > 1000) { // Update every 1 second
   //totalMilliLitres=0;
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
  if(totalMilliLitres<value){
    digitalWrite(LED,1);
    Serial.println(" doing");
  }
  else{
    digitalWrite(LED,0);
    Serial.print("Flow rate: ");
  Serial.print(flowRate);
  Serial.print(" L/min\t");
  Serial.print("Total flow: ");
  Serial.print(totalMilliLitres);
  Serial.println(" mL");
    Serial.println(" done");
    delay(2000);
    totalMilliLitres=0;
    break;
  }
  }
}

void pulseCounter() {
  pulseCount++;
}
