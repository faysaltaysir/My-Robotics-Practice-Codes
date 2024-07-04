int ldrPin = A1;
int rainPin = A0;
int rainLed = 2;      // select the pin for the LED rain
int ldrLed = 12;      // ldr
int rainThres = 500;
int ldrThres = 50;
int ldrValue ;  // variable to store the value coming from the sensor
int rainValue;  // variable to store the value coming from the sensor
void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(rainLed, OUTPUT);
  pinMode(ldrLed, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(rainPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  ldrValue = analogRead(ldrPin);
  rainValue = analogRead(rainPin);
  // turn the ledPin on
  Serial.println("ldrValue: ");Serial.println(ldrValue);
  Serial.println("rainValue");Serial.println(rainValue);
  //delay(100);
  if(rainValue>rainThres){          //rain
    digitalWrite(rainLed, HIGH);
  }
  if(ldrValue<ldrThres){            //LDR
    digitalWrite(ldrLed, HIGH);
    }
  if(rainValue<rainThres) {         //rain
   digitalWrite(rainLed, LOW);
  }if(ldrValue>ldrThres) {                       
   digitalWrite(ldrLed, LOW);      // LDR
  }
}
