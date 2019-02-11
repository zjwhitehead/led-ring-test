#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 180

#define DATA_PIN 5
#define CLOCK_PIN 13
#define POT_PIN A1
#define BRIGHTNESS 60

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds < WS2812B, DATA_PIN, GRB > (leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(POT_PIN, INPUT);
  Serial.begin(115200);
  Serial.println(F("Booting up LED tester"));
}

void loop() {
  int potValue = analogRead(POT_PIN);
  int leds_on = map(potValue, 0, 1023, 0, NUM_LEDS);
  for (int i = 0; i < NUM_LEDS; i++) {
    if (i < leds_on) {
      if ( (i % 2) == 0) { // alternate red and white
        leds[i] = CRGB::Red; }
      else{
        leds[i] = CRGB::White;
      }
    } else {
      leds[i] = CRGB::Black;
    }
  }
  FastLED.show();
  delay(10);
}
