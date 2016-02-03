
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

void setup() {
  Serial.begin(9600);
  Serial.println("kokoro no badge Start!!!!!");
  
  matrix.begin(0x70);  // pass in the address
}

static const int8_t W = 8;
static const int8_t H = 8;
String pic_heart = "000000000GG00YY0GGGRRYYYGGGRRYYYGGGRRYYY0GGRRYY000GRRY00000RR000";
String pic_smile = "00000000000000000Y0000Y0Y0Y00Y0Y0000000000YYYY00000YY00000000000";
String pic_angry = "R000000R0R0000R000R00R00000000000000000000RRRR000R0000R000000000";

void draw(String pict) {
  matrix.clear();
  for (int8_t i=0; i<H; i++)
  {
    for (int8_t j=0; j<W; j++)
    {
      uint16_t color;

      char color_char = pict.charAt((i * H) + j);
      if ( color_char == 'R' )  color = LED_RED;
      else if ( color_char == 'G' )  color = LED_GREEN;
      else if ( color_char == 'Y' )  color = LED_YELLOW;
      else continue;
      matrix.drawPixel(i, j, color);    
    }
    if ( 8 % i == 1) Serial.println("========");
  }
  matrix.writeDisplay();
}

void loop() {

  matrix.blinkRate(3);
  draw(pic_heart);
  delay(10000);
  matrix.blinkRate(2);
  draw(pic_smile);
  delay(10000);
  matrix.blinkRate(1);
  draw(pic_angry);
  delay(10000);
  matrix.blinkRate(0);

}
