#include <ESP8266WiFi.h>
#include <Milkcocoa.h>
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();


#define BADGE_OWNER       "matsuo" // "yasui" "satoon"


/************************* WiFi Access Point *********************************/

#define WLAN_SSID       ""
#define WLAN_PASS       ""

/************************* Your Milkcocoa Setup *********************************/

#define MILKCOCOA_APP_ID      ""
#define MILKCOCOA_DATASTORE   "reaction"

/************* Milkcocoa Setup (you don't need to change this!) ******************/

#define MILKCOCOA_SERVERPORT  1883

/************ Global State (you don't need to change this!) ******************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;

const char MQTT_SERVER[] PROGMEM    = MILKCOCOA_APP_ID ".mlkcca.com";
const char MQTT_CLIENTID[] PROGMEM  = __TIME__ MILKCOCOA_APP_ID;

static const uint8_t PROGMEM
  smile1_bmp[] =
  { B11111111,
    B11111111,
    B11011011,
    B11011011,
    B11111111,
    B10111101,
    B11000011,
    B11111111 },
  smile2_bmp[] =
  { B11111111,
    B11111111,
    B11011011,
    B11011011,
    B11111111,
    B10000001,
    B11000011,
    B11111111 },
  smile3_bmp[] =
  { B11111111,
    B11011011,
    B11011011,
    B11111111,
    B10000001,
    B10000001,
    B11000011,
    B11111111 },
  
  heart1_bmp[] =
  { B00000000,
    B00000000,
    B00000000,
    B00100100,
    B00111100,
    B00011000,
    B00000000,
    B00000000 },
    
  heart2_bmp[] =
  { B00000000,
    B00000000,
    B00100100,
    B01111110,
    B01111110,
    B00111100,
    B00011000,
    B00000000 },
  heart3_bmp[] =
  { B01100110,
    B01111110,
    B11111111,
    B11111111,
    B11111111,
    B01111110,
    B00111100,
    B00011000 };

Milkcocoa milkcocoa = Milkcocoa(&client, MQTT_SERVER, MILKCOCOA_SERVERPORT, MILKCOCOA_APP_ID, MQTT_CLIENTID);

void onpush(DataElement *elem) {
  Serial.println("OnPush!!!!!");
  matrix.clear();
  matrix.drawBitmap(0, 0, heart3_bmp, 8, 8, LED_RED);
  matrix.writeDisplay();
  delay(1000);
  matrix.clear();
  matrix.writeDisplay();
  

};


void setup() {

  Serial.begin(115200);
  delay(100);

  Serial.println(F("Milkcocoa SDK demo"));

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println( milkcocoa.on(MILKCOCOA_DATASTORE, "push", onpush) );

  matrix.begin(0x70);
  matrix.setRotation(3);
  matrix.clear();
  matrix.writeDisplay();


};

void loop() {
  milkcocoa.loop();
  delay(200);
};


