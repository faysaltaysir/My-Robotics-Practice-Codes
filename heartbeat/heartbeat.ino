#include <Wire.h>
#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.  

const int pumpPin = 12;  // Pin connected to the pump control

const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED = LED_BUILTIN;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 
                               
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"



volatile int flow_frequency; // Measures flow sensor pulses
float l_hour; // Calculated litres/hour
unsigned char flowsensor = 2; // Sensor Input
unsigned long currentTime;
unsigned long cloopTime;



void flow () // Interrupt function
{
   flow_frequency++;
}


void setup()
{
   Serial.begin(9600);
   pinMode(pumpPin, OUTPUT);
   pinMode(flowsensor, INPUT);
   digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up
   attachInterrupt(0, flow, RISING); // Setup Interrupt
   sei(); // Enable interrupts
   currentTime = millis();
   cloopTime = currentTime;

   // Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);   

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }
}


void loop()
{
    if (pulseSensor.sawStartOfBeat()) { // Constantly test to see if "a beat happened".
        int myBPM = pulseSensor.getBeatsPerMinute(); // Declare and assign value to myBPM here
        Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
        Serial.print("BPM: "); // Print phrase "BPM: "
        Serial.println(myBPM); // Print the value inside of myBPM.

        // Additional code based on myBPM goes here or within this scope
        int salineQuantity = mapOxygenToSaline(myBPM);
        deliverSaline(salineQuantity);
       // delay(5000); // Delay here or after this block depending on your logic
    }

    // Other code for non-heartbeat related functionality goes here
}

int mapOxygenToSaline(int oxygenLevel)
{
    // Map simulated oxygen level to saline quantity based on the provided ranges
    if (oxygenLevel >= 90 && oxygenLevel <= 94)
    {
        return random(500, 1001);
    }
    else if (oxygenLevel >= 85 && oxygenLevel <= 89)
    {
        return random(1001, 2001);
    }
    else if (oxygenLevel >= 80 && oxygenLevel <= 84)
    {
        return random(2001, 3001);
    }
    else if (oxygenLevel >= 75 && oxygenLevel <= 79)
    {
        return random(3001, 4001);
    }
    else if (oxygenLevel < 75)
    {
        return random(4001, 5001);
    }
 else if (oxygenLevel > 200)
    {
        return random(4001, 5001);
    }


    // Default value if oxygen level is out of specified ranges
    return 0;
}

void deliverSaline(int quantity)
{
    //digitalWrite(pumpPin, HIGH); // Start the pump
    Serial.print("Delivering ");
    Serial.print(quantity);
    Serial.println(" milliliters of Saline...");

    currentTime = millis();
   // Every second, calculate and print litres/hour
   //float x = 1.0; 
   
   if(currentTime >= (cloopTime + 1000))
   {
      cloopTime = currentTime; // Updates cloopTime
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      l_hour = ((flow_frequency *1000) / (7.5*60)); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      //flow_frequency = 0; // Reset Counter
      
      if(l_hour >= quantity){
        digitalWrite(pumpPin,LOW);//delay(5000);
      }
      else if(l_hour < quantity){
        digitalWrite(pumpPin,HIGH);
      }
      
      Serial.print(l_hour, DEC); // Print litres/hour
      Serial.println(" L/sec");


    

    // Simulate delivering the correct amount of saline (simplified example)
    delay(quantity * 100);

    digitalWrite(pumpPin, LOW); // Stop the pump
    Serial.println("Saline Delivered!");
    Serial.println(quantity);

  }
}
