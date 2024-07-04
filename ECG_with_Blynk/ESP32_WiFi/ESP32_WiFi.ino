
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPLuFaui7-F"
#define BLYNK_TEMPLATE_NAME "Heart Monitoring"
#define BLYNK_AUTH_TOKEN "qRktuDVZK0Ugw2mfTuPWsARuAZRC0bWg"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "CUET-Students-N";
char pass[] = "1020304050";



BlynkTimer timer;
int a = 0;
// This function sends Arduino's up time every second to Virtual Pin (5).
int val = 15;
int input(){
  //val=15;
  if((digitalRead(15)==1)||(digitalRead(2)==1)){
    Serial.println(analogRead(4));
  }
  else{
    val = val*-1;
    Serial.println(val);
    
  }
 
  return val;
}

void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, input());//delay(10);
}

void setup()
{
  // Debug console

  Serial.begin(9600);
// pinMode(15, INPUT); // Setup for leads off detection LO +
//pinMode(2, INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(100L, myTimerEvent);
  
}

void loop()
{
  Blynk.run();
  timer.run();
 
}
