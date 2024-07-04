#include <Wire.h>

int ADXL345 = 0x53;  // I2C address of ADXL345
int X_out, Y_out, Z_out;
int threshold = 200; // Adjust this threshold based on your sensor and environment
int stepCount = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D); // talk to POWER_CTL Register - 0x2D
  Wire.write(8);    // Bit D3 High for measuring enable (8dec -> 0000 1000 binary)
  Wire.endTransmission();
  delay(10);
}

void loop() {
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true);

  X_out = (Wire.read() | Wire.read() << 8);
  Y_out = (Wire.read() | Wire.read() << 8);
  Z_out = (Wire.read() | Wire.read() << 8);

  // Calculate the magnitude of acceleration vector
  int magnitude = sqrt(X_out * X_out + Y_out * Y_out + Z_out * Z_out);

  // Detect steps based on acceleration magnitude
  if (magnitude > threshold) {
    stepCount++;
    Serial.print("Step Count: ");
    Serial.println(stepCount);
    delay(500); // Adjust the delay to avoid counting multiple steps for a single movement
  }

  Serial.print("Acceleration Magnitude: ");
  Serial.println(magnitude);
  delay(100);
}
