/*
Created by RobotCing Team
*/


//--------------------------------------------
//            Library import
//--------------------------------------------
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <IRremote.h>
#include <VL53L0X.h>
#include <Servo.h>
#include <Adafruit_ADS1015.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>

//--------------------------------------------
#include "Arduino.h"
#include "Atmega328_IO.h"
//--------------------------------------------
Cing::Cing(){}
//--------------------------------------------
//             Servo setup
//--------------------------------------------
#define Servo_A 9
#define Servo_B 10
#define Servo_C 6

Servo ServoA;
Servo ServoB;
Servo ServoC;
//--------------------------------------------
//            Neopixel setup
//--------------------------------------------
#define PIN 13
#define Neopixels 120
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(Neopixels, PIN, NEO_GRB + NEO_KHZ800);
//--------------------------------------------
//            Gyro setup
//--------------------------------------------
MPU6050 mpu6050(Wire);
//--------------------------------------------
//            VL53L0X setup
//--------------------------------------------
VL53L0X sensor;
//--------------------------------------------
//            DS18B20 Setup
//--------------------------------------------
#define ONE_WIRE_BUS 13
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
//--------------------------------------------
//                BMS
//--------------------------------------------
Adafruit_ADS1015 ads;
//--------------------------------------------
//               IR Setup
//--------------------------------------------
#define RECV_PIN 4
IRrecv irrecv(RECV_PIN);
decode_results results;
//--------------------------------------------
//               BME280
//--------------------------------------------
Adafruit_BME280 bme;
//--------------------------------------------
//               16x2 display
//--------------------------------------------
LiquidCrystal_I2C lcd(0x27,16,2);
//--------------------------------------------
//               Bluetooth
//--------------------------------------------
SoftwareSerial hc06(2,5);
//--------------------------------------------
//              Stepper Motors
//--------------------------------------------
#define DIRA 9
#define STEPA 10
#define SLEEPA 12

#define DIRB 8
#define STEPB 7
#define SLEEPB 11
//--------------------------------------------
//              Motors
//--------------------------------------------
void Cing::RunMotor(String motor,int speed,String mode)
	{
		 #define motorA 12
		 #define motorB 11
		 #define INA1 10
		 #define INA2 9
		 #define INB1 8
		 #define INB2 7
		 pinMode(motorA,OUTPUT);
		 pinMode(motorB,OUTPUT);
		 //---------------------
		 pinMode(INA1,OUTPUT);
		 pinMode(INA2,OUTPUT);
		 pinMode(INB1,OUTPUT);
		 pinMode(INB2,OUTPUT);
		 if(mode=="digital")
			{
				int speed_set;
				if (speed == 1 || speed == -1)
					{
						speed_set = HIGH;
					}
				else if (speed == 0)
					{
						speed_set = LOW;
					}
				//--------------------------
				//           A
				//--------------------------
				if(motor=="A")
					{
						if (speed == 1)
							{
								digitalWrite(INA1,HIGH);
								digitalWrite(INA2,LOW);
								digitalWrite(motorA,speed_set);
							}
						else if (speed == -1)
							{
								digitalWrite(INA1,LOW);
								digitalWrite(INA2,HIGH);
								digitalWrite(motorA,speed_set);
							}
						else if (speed == 0)
							{
								digitalWrite(INA1,LOW);
								digitalWrite(INA2,LOW);
								digitalWrite(motorA,LOW);
							}
					}
				//--------------------------
				//            B
				//--------------------------
				else if(motor=="B")
					{
						if (speed == 1)
							{
								digitalWrite(INB1,HIGH);
								digitalWrite(INB2,LOW);
								digitalWrite(motorB,speed_set);
							}
						  else if (speed == -1)
							{
								digitalWrite(INB1,LOW);
								digitalWrite(INB2,HIGH);
								digitalWrite(motorB,speed_set);
							}
						  else if (speed == 0)
							{
								digitalWrite(INB1,LOW);
								digitalWrite(INB2,LOW);
								digitalWrite(motorB,LOW);
							}
					}
				//--------------------------
				//            AB
				//--------------------------
				else if(motor=="AB")
					{
						if (speed == 1)
							{
								digitalWrite(INA1,HIGH);
								digitalWrite(INA2,LOW);
								digitalWrite(INB1,HIGH);
								digitalWrite(INB2,LOW);
								digitalWrite(motorA,speed_set);
								digitalWrite(motorB,speed_set);
							}
						else if (speed == -1)
							{
								digitalWrite(INA1,LOW);
								digitalWrite(INA2,HIGH);
								digitalWrite(INB1,LOW);
								digitalWrite(INB2,HIGH);
								digitalWrite(motorA,speed_set);
								digitalWrite(motorB,speed_set);
							}
						else if (speed == 0)
							{
								digitalWrite(INA1,LOW);
								digitalWrite(INA2,LOW);
								digitalWrite(INB1,LOW);
								digitalWrite(INB2,LOW);
								digitalWrite(motorA,LOW);
								digitalWrite(motorB,LOW);
							}
					}
				else
					{
						digitalWrite(motorA,LOW);
						digitalWrite(motorB,LOW);
					}
			}
	}
//--------------------------------------------
//                  Sensors
//--------------------------------------------

//--------------------------------------------
//                  LightSensor
//--------------------------------------------

int Cing::ReadLightSensor(int sensor,String mode)
	{
		#define LightSensor1 A2
		#define LightSensor2 A3
		pinMode(LightSensor1,INPUT);//1
		pinMode(LightSensor2,INPUT);//2
		if (mode=="analog")
			{
				if (sensor == 1)
					{
						int value;
						value = map(analogRead(LightSensor1),0,1023,100,0);
						return value;
					}
				else if (sensor == 2)
					{
						int value;
						value = map(analogRead(LightSensor2),0,1023,100,0);
						return value;
					}
			}
			else if(mode=="digital")
			{
				if (sensor == 1)
					{
						int value;
						value = map(digitalRead(LightSensor1),0,1,1,0);
						return value;
					}
				else if (sensor == 2)
					{
						int value;
						value = map(digitalRead(LightSensor2),0,1,1,0);
						return value;
					}
				else
					{
						int value;
						value = map(digitalRead(LightSensor1),0,1,1,0);
						return value;
					}
			}
	}
//--------------------------------------------
//           UltrasonicSensor
//--------------------------------------------
void Cing::InitUltrasonicSensor()
	{
		Wire.begin();
	}
uint8_t Cing::ReadUltrasonicSensor(String mode,int address){
	Wire.requestFrom(address, 4);
	uint8_t distance = Wire.read();
	uint8_t temperature = Wire.read();
	uint8_t humidity = Wire.read();
	uint8_t tdistance = Wire.read();
	if(mode = "Distance"){return distance;}
	else if(mode = "Temperature"){return temperature;}
	else if(mode = "Humidity"){return humidity;}
	else if(mode = "TDistance"){return tdistance;}
}
//--------------------------------------------
//             ShineSensors
//--------------------------------------------
int Cing::ReadShineSensor()
	{
		#define ShineSensor 13
		pinMode(ShineSensor,INPUT);
		int shine_value = map(digitalRead(ShineSensor),0,1,100,0);
		return shine_value;
	}
//--------------------------------------------
//               Button
//--------------------------------------------
bool Cing::ReadButton()
	{
		#define Button A6
		bool button_value;
		if(analogRead(Button)>1000){
			button_value = 1;
		}
		else{
			button_value = 0;
		}
		return button_value;
	}
//--------------------------------------------
//          ButtonExternal
//--------------------------------------------
bool Cing::ReadButtonExternal()
  {
		#define button_external 13
		pinMode(button_external,INPUT);
		bool button_external_value = digitalRead(button_external);
		return button_external_value;
  }
//--------------------------------------------
//          Potentiometer
//--------------------------------------------
int Cing::ReadPotentiometer()
  {
		#define potentiometer A1
		int potentiometer_value = map(analogRead(potentiometer),0,1023,0,100);
		return potentiometer_value;
	}
//--------------------------------------------
//            TemperatureSensors
//--------------------------------------------
float Cing::ReadTempSensor(int sensor)
	{
		float Temp;
		sensors.requestTemperatures();
		Temp = sensors.getTempCByIndex(sensor);
		delay(10);
		return Temp;
	}
//--------------------------------------------
//            LED WS2812
//--------------------------------------------
void Cing::InitLed(){
	pixels.begin();
	pixels.show();
}
void Cing::SetLedColor(int led,int red,int green,int blue){
	if(led>0)
		{
			pixels.setPixelColor(led-1,pixels.Color(map(green,0,100,0,255),map(red,0,100,0,255),map(blue,0,100,0,255)));
		}
	else
		{
			pixels.setPixelColor(0,pixels.Color(map(green,0,100,0,255),map(red,0,100,0,255),map(blue,0,100,0,255)));
		}
}
void Cing::ShowLed()
	{
		pixels.show();
	}

//--------------------------------------------
//                  Gyro
//--------------------------------------------
void Cing::InitGyro(bool gyro_off){
  Wire.begin(0x00);
  mpu6050.begin();
  mpu6050.calcGyroOffsets(gyro_off);
}
float Cing::ReadGyro(String axis,int mode){
	mpu6050.update();
	if(mode == "angle"){
		if(axis == "x" || axis == "X"){
			return int(mpu6050.getGyroAngleX());
		}
		else if(axis == "y" || axis == "Y"){
			return int(mpu6050.getGyroAngleY());
		}
		else if(axis == "z" || axis == "Z"){
			return int(mpu6050.getGyroAngleZ());
		}
	}
	else{
		if(axis == "x" || axis == "X"){
			return mpu6050.getAccX();
		}
		else if(axis == "y" || axis == "Y"){
			return mpu6050.getAccY();
		}
		else if(axis == "z" || axis == "Z"){
			return mpu6050.getAccZ();
		}
	}
}
//--------------------------------------------
//                  Shine Array
//--------------------------------------------
int Cing::ReadShineArray(int sensor){
  int value1 = map(analogRead(A0),0,1023,100,0);
  int value2 = map(analogRead(A7),0,1023,100,0);
  if(sensor == 1){
    return value1;
  }
  else{
    return value2;
  }
}
//--------------------------------------------
//               Show Sensors
//--------------------------------------------
void Cing::InitTest(String mode){
	if(mode == "PC"){
		Serial.begin(9600);
	}
	else{
		hc06.begin(9600);
	}
	InitLed();
	Wire.begin(0x00);
	if(Check(0x76)=="Ok"){
		InitBME280();
	}
	if(Check(0x68)=="Ok"){
		InitGyro();
	}
	if(Check(0x29)=="Ok"){
		InitLidar();
	}
	if(Check(0x27)=="Ok"){
		InitDisplay();
		TurnBacklight();
		SetCursor(4,1);
		DisplayPrint("Robot Cing");
		SetCursor(3,2);
		DisplayPrint("Display Test");
	}
}
void Cing::Test(String mode){
	SetLedColor(1,0,0,0);
	SetLedColor(2,0,0,5);
	SetLedColor(3,5,0,0);
	SetLedColor(4,0,5,0);
	ShowLed();
	if(mode == "PC"){
		Serial.println(ReadLightSensor(1,"analog"));//LightSensor1
		Serial.println(ReadLightSensor(2,"analog"));//LightSensor2
		Serial.println(ReadShineArray(1));//ShineArray1
		Serial.println(ReadShineArray(2));//ShineArray2
		//Gyro
		if(Check(0x68)=="Ok"){
			Serial.print("X:");
			Serial.print(ReadGyro("x","angle"));
			Serial.print(" ");
			Serial.print("Y:");
			Serial.print(ReadGyro("y","angle"));
			Serial.print(" ");
			Serial.print("Z:");
			Serial.println(ReadGyro("z","angle"));
			Serial.print(" ");
			Serial.print("X:");
			Serial.print(ReadGyro("x","acceleration"));
			Serial.print("G ");
			Serial.print("Y:");
			Serial.print(ReadGyro("y","acceleration"));
			Serial.print("G ");
			Serial.print("Z:");
			Serial.print(ReadGyro("z","acceleration"));
			Serial.println("G");
		}
		else{
			Serial.println("Fail");
			Serial.println("Fail");
		}
		Serial.println(ReadButton());//Button
		//BMS
		if(Check(0x48)=="Ok"){
			Serial.print(ReadBMS("voltage"));
			Serial.print(" V   ");
			Serial.print(ReadBMS("current"));
			Serial.println(" A");
		}
		else{
			Serial.println("BMS Failed");
		}
		Serial.println(Check(0x3c));//Oled Display
		Serial.println(Check(0x27));//16x2 Display
		//Ultrasonic Sensor
		bool err_ultra = 1;
		for(int x=16;x<24;x++){
			if(Check(x) == "Ok"){
				Serial.println(ReadUltrasonicSensor("distance",x));
				err_ultra = 0;
			}
		}
		if(err_ultra == 1){
			Serial.println("Fail");
		}
		//Lidar
		if(Check(0x29)=="Ok"){
			Serial.print(ReadLidar());
			Serial.println(" mm");
		}
		else{
			Serial.println("Fail");
		}
		Serial.println(ReadTempSensor());//TempSensor
		//BME280
		if(Check(0x76)=="Ok"){
			//Serial.print(ReadAmbientTemperature());
			//Serial.println(" C");
			Serial.print(ReadPressure());
			Serial.println(" hPa");
			Serial.print(ReadAltitude());
			Serial.println(" m");
		}
		else{
			Serial.println("Fail");
			Serial.println("Fail");
		}
		Serial.println(Check(0x69));//IO Expander
		Serial.println(ReadPotentiometer());//Potentiometer
		Serial.println(Check(0x40));//Servo Board
		Serial.println(Check(0x41));//Motor Encoder A
		Serial.println(Check(0x42));//Motor Encoder B
		Serial.println("------");
		delay(1);
	}
	else{
		hc06.println(ReadLightSensor(1,"analog"));//LightSensor1
		hc06.println(ReadLightSensor(2,"analog"));//LightSensor2
		hc06.println(ReadShineArray(1));//ShineArray1
		hc06.println(ReadShineArray(2));//ShineArray2
		//Gyro
		if(Check(0x68)=="Ok"){
			hc06.print("X:");
			hc06.print(ReadGyro("x","angle"));
			hc06.print(" ");
			hc06.print("Y:");
			hc06.print(ReadGyro("y","angle"));
			hc06.print(" ");
			hc06.print("Z:");
			hc06.println(ReadGyro("z","angle"));
			hc06.print(" ");
			hc06.print("X:");
			hc06.print(ReadGyro("x","acceleration"));
			hc06.print("G ");
			hc06.print("Y:");
			hc06.print(ReadGyro("y","acceleration"));
			hc06.print("G ");
			hc06.print("Z:");
			hc06.print(ReadGyro("z","acceleration"));
			hc06.println("G");
		}
		else{
			hc06.println("Fail");
			hc06.println("Fail");
		}
		hc06.println(ReadButton());//Button
		//BMS
		if(Check(0x48)=="Ok"){
			hc06.print(ReadBMS("voltage"));
			hc06.print(" V   ");
			hc06.print(ReadBMS("current"));
			hc06.println(" A");
		}
		else{
			hc06.println("BMS Failed");
		}
		hc06.println(Check(0x3c));//Oled Display
		hc06.println(Check(0x27));//16x2 Display
		//Ultrasonic Sensor
		bool err_ultra = 1;
		for(int x=16;x<24;x++){
			if(Check(x) == "Ok"){
				hc06.println(ReadUltrasonicSensor("distance",x));
				err_ultra = 0;
			}
		}
		if(err_ultra == 1){
			hc06.println("Fail");
		}
		//Lidar
		if(Check(0x29)=="Ok"){
			hc06.print(ReadLidar());
			hc06.println(" mm");
		}
		else{
			hc06.println("Fail");
		}
		hc06.println(ReadTempSensor());//TempSensor
		//BME280
		if(Check(0x76)=="Ok"){
			//hc06.print(ReadAmbientTemperature());
			//hc06.println(" C");
			hc06.print(ReadPressure());
			hc06.println(" hPa");
			hc06.print(ReadAltitude());
			hc06.println(" m");
		}
		else{
			hc06.println("Fail");
			hc06.println("Fail");
		}
		hc06.println(Check(0x69));//IO Expander
		hc06.println(ReadPotentiometer());//Potentiometer
		hc06.println(Check(0x40));//Servo Board
		hc06.println(Check(0x41));//Motor Encoder A
		hc06.println(Check(0x42));//Motor Encoder B
		hc06.println("------");
		delay(1);
	}
}
//--------------------------------------------
String Cing::Check(uint8_t address){
  Wire.beginTransmission(address);
  int error = Wire.endTransmission();
	String return_value;
  if (error == 0) {
			return_value = "Ok";
    }
    else {
        return_value = "Fail";
      }
	return return_value;
}

//--------------------------------------------
//               IR Sensors
//--------------------------------------------
int irvalue;
void Cing::InitIR(){
	irrecv.enableIRIn();
}

void Cing::SetIRValue(){
	long buttons[17] = {
		16753245,16736925,
		16769565,16720605,
		16712445,16761405,
		16769055,16754775,
		16748655,16738455,
		16750695,16756815,
		16718055,16726215,
		16730805,16716015,
		16734885
	};
	if (irrecv.decode(&results)) {
		if(results.value != 4294967295){
			for(int x = 0;x<17;x++){
				if(results.value == buttons[x]){
					irvalue = x+1;
				}
			}
		}
		irrecv.resume();
	}
}

int Cing::ReadIR(){
	SetIRValue();
	return irvalue;
}
//--------------------------------------------
//                  Lidar
//--------------------------------------------
void Cing::InitLidar(){
	sensor.init();
 	sensor.setTimeout(100);
	sensor.setMeasurementTimingBudget(50000);
}
int Cing::ReadLidar(){
	return sensor.readRangeSingleMillimeters();
}
//--------------------------------------------
//                  Servo
//--------------------------------------------
void Cing::InitServo(String servo){
	if(servo == "A"){
		ServoA.attach(Servo_A);
	}
	else if(servo == "B"){
		ServoB.attach(Servo_B);
	}
	else{
		ServoC.attach(Servo_C);
	}
}
void Cing::SetServo(String servo,int angle_in){
	int angle = constrain(map(angle_in,-90,90,0,180),0,180);
	if(servo == "A"){
		ServoA.write(angle);
	}
	else if(servo == "B"){
		ServoB.write(angle);
	}
	else{
		ServoC.write(angle);
	}
}
void Cing::DisableServo(String servo){
	if(servo == "A"){
		ServoA.detach(Servo_A);
	}
	else if(servo == "B"){
		ServoB.detach(Servo_B);
	}
	else{
		ServoC.detach(Servo_C);
	}
}
//--------------------------------------------
//                  BMS
//--------------------------------------------
void Cing::InitBMS(){
	ads.begin();
}
float Cing::ReadBMS(String mode){
  if(mode == "voltage"){
    float voltage = ads.readADC_Differential_0_1();
    return voltage*0.003;
  }
  else{
    return ads.readADC_Differential_2_3();
  }  
}
//--------------------------------------------
//                  BME280
//--------------------------------------------
void Cing::InitBME280(){
  bme.begin(0x76);
}
float Cing::ReadAltitude(){
  return bme.readAltitude(1013.25);
}
float Cing::ReadPressure(){
  return bme.readPressure()/100.0F;
}
float Cing::ReadHumidity(String mode){
  if (mode == "internal"){
	return bme.readPressure();
  }  
}
//--------------------------------------------
//                  Displays
//--------------------------------------------
void Cing::InitDisplay(String display){
  if(display == "16x2"){
	  lcd.init();
  }
}
void Cing::TurnBacklight(bool state){
	if (state == 1){
		lcd.backlight();
	}
	else{
		lcd.noBacklight();
	}
	
}
void Cing::SetCursor(int x,int y,String display){
	if(display == "16x2"){
		lcd.setCursor(x+1,y+1);
	}
	
}
void Cing::DisplayPrint(String message,String display){
	if(display == "16x2"){
		lcd.print(message);
	}
}


//--------------------------------------------
//                  ColorSensor
//--------------------------------------------
/*
void StartColorSensor(){
	SoftwareSerial mySerial(A3, A2);
	int ACK = 0x04; // Acknowledge byte
	int NACK = 0x02; // Not acknowledge byte
	int SensorDisconnected = 0;
	int lastRefresh = millis();
	int SerialValue [] = {0,0,0,0};
	int refreshTime = 250;
	long lastupdate = millis();
	mySerial.begin(2400);
	//Sensor setup
	while (true){
  int value = mySerial.read();
  if(value==-1 && value==0 && value==255){
    mySerial.read();
  }
  if(value!=-1){
    SerialValue[1] = SerialValue[0];
    SerialValue[0] = value;
  }

  if(SerialValue[0]==128 && SerialValue[1]==144){
    while (true){
      if(mySerial.read()==4){
        break;
      }
    }
    mySerial.write(ACK);
    delay(60);
    mySerial.end();
    mySerial.begin(57600);
    break;
  }
  }
}

int ReadColorSensor(){
	if (millis() - lastRefresh > refreshTime){
      SensorMode(2);
      lastRefresh = millis();
    }
    SerialValue[2] = mySerial.read();
    if(SerialValue[2]==-1 && SerialValue[2]==255){
      SensorDisconnected ++;
      mySerial.read();
    }
    if(SerialValue[2]!=-1 && SerialValue[2] <= 7 && SerialValue[3]==0){
      SensorDisconnected = 0;
      SerialValue[3] = 1;
      Serial.print(SerialValue[2]);
      Serial.print("          ");
      Serial.print((millis()-lastupdate));
      Serial.println("ms");
      lastupdate = millis();
      for(int x=1;x<5;x++){
        //Blue
        if(SerialValue[2]==2){
          Cing.SetLedColor(x,0,0,255);
        }
        //Green
        else if(SerialValue[2]==3){
          Cing.SetLedColor(x,255,0,0);
        }
        //Red
        else if(SerialValue[2]==5){
          Cing.SetLedColor(x,0,255,0);
        }
        //White
        else if(SerialValue[2]==6){
          Cing.SetLedColor(x,255,255,255);
        }
        //None or unmatched
        else{
          Cing.SetLedColor(x,0,0,0);
        }
      }
      Cing.LedShow();
    }
    else{
      SerialValue[3] = 0;
    }
    if(SensorDisconnected > 10){
      Serial.println("Sensor Disconnected");
    }
}

void SensorMode(int newMode){
  if (newMode <= 5 && newMode >= 0){
    sendMessage(0x44, 0x11);
    for (int n;n<3;n++){
      sendMessage(0x43, newMode & 0x7);
      mySerial.write(NACK);
    }
  }
}
void sendMessage(int cmd,int data){
  int cSum = 0xff ^ cmd ^ data;
  mySerial.write(cmd);
  mySerial.write(data);
  mySerial.write(cSum);
}
*/
