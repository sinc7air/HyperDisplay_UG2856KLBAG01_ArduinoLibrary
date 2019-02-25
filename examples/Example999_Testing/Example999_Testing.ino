#include "HyperDisplay_UG2856KLBAG01.h"

#define SERIAL_PORT Serial  
#define WIRE_PORT Wire      // Used if USE_SPI == 0
#define SPI_PORT SPI        // Used if USE_SPI == 1

#define RES_PIN 2           // Optional
#define CS_PIN 4            // Used only if USE_SPI == 1
#define DC_PIN 5            // Used only if USE_SPI == 1

#define USE_SPI 1


#if USE_SPI
  UG2856KLBAG01_SPI myTOLED;  // Declare a SPI-based Transparent OLED object called myTOLED
#else
  UG2856KLBAG01_I2C myTOLED;  // Declare a I2C-based Transparent OLED object called myTOLED
#endif /* USE_SPI */


uint8_t color = 0x01;

void setup() {
  Serial.begin(9600);

  Serial.println("Example999_Testing: Transparent Graphical OLED");
  Serial.println(sizeof(SSD1309_Bite_t));

#if USE_SPI 
  SPI_PORT.begin();
  myTOLED.begin(CS_PIN, DC_PIN, SPI_PORT);
#else
  WIRE_PORT.begin();
  myTOLED.begin(WIRE_PORT, false, SSD1309_ARD_UNUSED_PIN);
  Wire.setClock(400000);
#endif /* USSE_SPI */

  myTOLED.line(10, 10, 350, 20, 1, (color_t)&color); 

  myTOLED.rectangleSet(15,15, 45, 38, true);
  myTOLED.rectangleClear(20,20, 40, 33, true);

  

  myTOLED.circleSet(100, 32, 28, true);

  delay(1000);
  
  myTOLED.circleClear(88, 28, 17, true);
  
  
  for(uint8_t indi = 255; indi > 1; indi--)
  {
    myTOLED.setContrastControl(indi);
    delay(5);
  }
  for(uint8_t indi = 0; indi < 254; indi++)
  {
    myTOLED.setContrastControl(indi);
    delay(5);
  }
}

void loop() {

  myTOLED.pixelSet(126,2);
  delay(1000);

  myTOLED.pixelClear(126,2);
  delay(1000);

}
