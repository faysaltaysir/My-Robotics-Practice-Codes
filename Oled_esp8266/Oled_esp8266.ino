#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1  // Set to -1 if not used
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Initialize the OLED display with SDA and SCL pins
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false, 14, 12)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Clear the display buffer
  display.clearDisplay();

  // Set text size, color and print some text
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Hello, OLED!");
  
  // Display text on the OLED
  display.display();
}

void loop() {
  // No need for anything here as the content is static
}
