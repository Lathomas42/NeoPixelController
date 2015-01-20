#include <CmdMessenger.h> //CmdMessenger
#include <Adafruit_NeoPixel.h> // Adafruit NeoPixel

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            7

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      12

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

CmdMessenger cmdMessenger = CmdMessenger(Serial);

enum
{
  //Commands
  kSetLed,
  kChangeBrightness
};

void attachCommandCallbacks()
{
  cmdMessenger.attach(kSetLed, setLed);
  cmdMessenger.attach(kChangeBrightness, changeBrightness);
}

void setLed()
{
  float ind = cmdMessenger.readFloatArg();
  float r = cmdMessenger.readFloatArg();
  float g = cmdMessenger.readFloatArg();
  float b = cmdMessenger.readFloatArg();
  pixels.setPixelColor(ind, pixels.Color(r,g,b));
  pixels.show();
}

void changeBrightness()
{
  float brightness = cmdMessenger.readFloatArg();
  pixels.setBrightness(brightness);
  pixels.show();
}
  
  
void setup(){
  pixels.begin();
  Serial.begin(115200);
  cmdMessenger.printLfCr();
  attachCommandCallbacks();
}

void loop(){
  cmdMessenger.feedinSerialData();
}
  
  
