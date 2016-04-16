#include <ESP8266HTTPUpdateServer.h>

#include <ESP8266WiFi.h>
#include <Milkcocoa.h>
#include <Wire.h>
#include <Adafruit_LEDBackpack.h>
#include <Adafruit_GFX.h>

#include "private.h"
#include "pict.h"
#include "sound_note.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();


/******************/

#define BADGE_OWNER       "matsuo" // "yasui" "satoon"

#define PIN_BEEP 12

/************* Milkcocoa Setup (you don't need to change this!) ******************/

#define MILKCOCOA_SERVERPORT  1883

/************ Global State (you don't need to change this!) ******************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;

const char MQTT_SERVER[] PROGMEM    = MILKCOCOA_APP_ID ".mlkcca.com";
const char MQTT_CLIENTID[] PROGMEM  = __TIME__ MILKCOCOA_APP_ID;

Milkcocoa milkcocoa = Milkcocoa(&client, MQTT_SERVER, MILKCOCOA_SERVERPORT, MILKCOCOA_APP_ID, MQTT_CLIENTID);

/********* Counter *****************************/

int count=0;
int display_num=0;
/**************** Sound Function **************************/
void normal_sound(){
  tone(PIN_BEEP, NOTE_A7, 30);
  delay(50);
  tone(PIN_BEEP, NOTE_D8, 100);
  delay(150);
}

void zelda_sound(){
  tone(PIN_BEEP, NOTE_G8, 150);
  delay(200);
  tone(PIN_BEEP, NOTE_FS7, 150);
  delay(200);
  tone(PIN_BEEP, NOTE_DS7, 150);
  delay(200);
  tone(PIN_BEEP, NOTE_A6, 150);
  delay(200);
  tone(PIN_BEEP, NOTE_GS6, 150);
  delay(200);
  tone(PIN_BEEP, NOTE_E7, 150);
  delay(200);
  tone(PIN_BEEP, NOTE_GS7, 150);
  delay(200);
  tone(PIN_BEEP, NOTE_G9, 150);
  delay(200);

}

void one_up_sound(){
  tone(PIN_BEEP, NOTE_E7, 100);
  delay(100);
  tone(PIN_BEEP, NOTE_G7, 100);
  delay(100);
  tone(PIN_BEEP, NOTE_E8, 100);
  delay(100);
  tone(PIN_BEEP, NOTE_C8, 100);
  delay(100);
  tone(PIN_BEEP, NOTE_D8, 100);
  delay(100);
  tone(PIN_BEEP, NOTE_G8, 50);
  delay(300);
}

/***********/

void onpush(DataElement *elem) {

   count++; //カウントアップ
   if(count==10){
    display_num=100;  //ハート(100)をセット
    zelda_sound();
   }else if(count>=20){
   display_num=101; //ワンナップ(101)をセット
   one_up_sound();
   }else{
      display_num=count;  
      normal_sound();
   }

  int v = 0;
  int led_color = 3;
  int vertical_or_horizontal =1; //horizontalmode
  int forward_or_backward = random(2); // 0-1
  int icon_no = random(sizeof(icons) / MATRIX_LINES);
  
  for (v = 0; v < MATRIX_LINES; v++) {
    matrix.clear();
    matrix.writeDisplay();
    delay(1);
   

    int vv = (forward_or_backward == FORWARD_MODE ? v - MATRIX_LINES + 1 : MATRIX_LINES - v  - 1);
    if ( vertical_or_horizontal == VERTICAL_MODE ) {
      matrix.drawBitmap(vv, 0, numbertable[display_num], 8, 8, led_color);
    }
    else if ( vertical_or_horizontal == HORIZONTAL_MODE ) {
      matrix.drawBitmap(0, vv,numbertable[display_num], 8, 8, led_color);
    }
    matrix.writeDisplay();
    delay(29 + abs(v));
    
  }
  delay(1000);
  matrix.clear();
  matrix.writeDisplay();
  
};

void setup() {

  Serial.begin(115200);
  delay(100);

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
  matrix.setRotation(4);
  matrix.clear();
  matrix.writeDisplay();

  pinMode(PIN_BEEP, OUTPUT);

  randomSeed(analogRead(2));
  };

void loop() {
  milkcocoa.loop();
  delay(200);
};


