/*
YF‐ S201 Water Flow Sensor
Water Flow Sensor output processed to read in litres/hour
Adaptation Courtesy: www.hobbytronics.co.uk
*/

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
   pinMode(flowsensor, INPUT);
   pinMode(13,OUTPUT);
   digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up
   Serial.begin(9600);
   attachInterrupt(0, flow, RISING); // Setup Interrupt
   sei(); // Enable interrupts
   currentTime = millis();
   cloopTime = currentTime;
}

void loop ()
{
   currentTime = millis();
   // Every second, calculate and print litres/hour
   float x = 1.0; 
   
   if(currentTime >= (cloopTime + 1000))
   {
      cloopTime = currentTime; // Updates cloopTime
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      l_hour = (flow_frequency / (7.5*60)); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      //flow_frequency = 0; // Reset Counter
      if(l_hour == x){
        digitalWrite(13,LOW);delay(5000);
      }
      else if(l_hour < x){
        digitalWrite(13,HIGH);
      }
      
      Serial.print(l_hour, DEC); // Print litres/hour
      Serial.println(" L/sec");
   }
}
