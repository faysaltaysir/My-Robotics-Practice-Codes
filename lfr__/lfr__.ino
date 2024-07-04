unsigned int sensor[10];/*sensor readings are saved here*/
unsigned int sensorWhileLEDoff[10]; /* sensor reading while LED is off*/
boolean firstData[10];/*to eliminate effect of noise*/
byte sensorPin[10] = {9,8,7,6,5,19,18,17,16,15};/*arduino pins to read
sensors*/
byte NumOfSensor = 10;
byte i; /*just to run for loop!!*/
unsigned int MaxWaitTime = 4000; /*equivalent to 12 bit ADC*/

void setup()
{
Serial.begin(9600);
pinMode(12,OUTPUT);
}

void loop()
{
digitalWrite(12, LOW); // turn ON IR LEDs
delay(20); // give some time to turn ON
readSensor(); // read line sensors while IR LEDs are OFF
// store current sensor data to sensorWhileLEDoff
for (i = 0; i <= 9; i++) sensorWhileLEDoff[i] = MaxWaitTime - sensor[i];
digitalWrite(12, HIGH); // turn ON IR LEDs
delay(20); // give some time to turn ON
readSensor(); // read line sensors while IR LEDs are ON
// calculate external light compensated readings
for (i = 0; i <= 9; i++) sensor[i] = sensor[i] + sensorWhileLEDoff[i];
showsensorData();
}

void readSensor()
{
for (i = 0; i < NumOfSensor; i++)
{
digitalWrite(sensorPin[i], HIGH);
pinMode(sensorPin[i], OUTPUT);
}
delayMicroseconds(10);
for (i = 0; i < NumOfSensor; i++)
{
pinMode(sensorPin[i], INPUT);
digitalWrite(sensorPin[i], LOW);
sensor[i] = MaxWaitTime;
firstData[i] = false;
}
unsigned long startTime = micros();
while (micros() - startTime < MaxWaitTime)
{
unsigned int time = micros() - startTime;
for (i = 0; i < NumOfSensor; i++)
{
if ((digitalRead(sensorPin[i]) == LOW) && (firstData[i] == false))
{
sensor[i] = time;
firstData[i] = true;
}
}
}
}
void showsensorData()
{
for (i = 0; i < NumOfSensor; i++)
{
Serial.print(sensor[i]);
Serial.print(" ");
}
Serial.println();
}
