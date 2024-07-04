

#include <SoftwareSerial.h>

SoftwareSerial BTserial(15, 14); // RX | TX
#include <QTRSensors.h>

// This example is designed for use with eight RC QTR sensors. These
// reflectance sensors should be connected to digital pins 3 to 10. The
// sensors' emitter control pin (CTRL or LEDON) can optionally be connected to
// digital pin 2, or you can leave it disconnected and remove the call to
// setEmitterPin().
//
// The main loop of the example reads the raw sensor values (uncalibrated). You
// can test this by taping a piece of 3/4" black electrical tape to a piece of
// white paper and sliding the sensor across it. It prints the sensor values to
// the serial monitor as numbers from 0 (maximum reflectance) to 2500 (minimum
// reflectance; this is the default RC timeout, which can be changed with
// setTimeout()).

QTRSensors qtr;

const uint8_t SensorCount = 10;
uint16_t sensorValues[SensorCount];

void setup()
{
  // configure the sensors
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){7,6,5,4,3,2,A0,A1,A2,A3}, SensorCount);
  qtr.setEmitterPin(10);
BTserial.begin(9600);
  //Serial.begin(9600);
}


void loop()
{
  // read raw sensor values
  qtr.read(sensorValues);

  // print the sensor values as numbers from 0 to 2500, where 0 means maximum
  // reflectance and 2500 means minimum reflectance
  for (uint8_t i = 0; i < SensorCount; i++)
  {
   // Serial.print(sensorValues[i]);
    //Serial.print('\t');

  }
  //Serial.println();

  delay(250);
  
    BTserial.print("1234");

BTserial.print(",");

BTserial.print("1234.0");

BTserial.print(",");

BTserial.print("1234 hPa");

BTserial.print(",");

BTserial.print("500 ml/s");

BTserial.print(",");
BTserial.print("500 ml/s");

BTserial.print(",");
//BTserial.print(sensorValue);

//BTserial.print(";");

//message to the receiving device

delay(20);

}



//IMPORTANT: The complete String has to be of the Form: 1234,1234,1234,1234;

//(every Value has to be seperated through a comma (',') and the message has to

//end with a semikolon (';'))
