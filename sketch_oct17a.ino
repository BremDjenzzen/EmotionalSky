#include <FastLED.h>

#define NUM_LEDS 300 // Define the number of LEDs in your strip
#define DATA_PIN 10   // Define the data pin for your LED strip
#define DELAY_MS 1000 // Delay in milliseconds between adding colors

CRGB leds[NUM_LEDS];  // Create an array to store the LED colors
int currentLED = 0;  // Track the current LED to update

// Pinout
const int Button_Pin_A = 2; // Pin for button 1
const int Button_Pin_B = 3; // Pin for button 2
const int Button_Pin_C = 4; // Pin for button 3
const int Button_Pin_D = 5; // Pin for button 4
const int Button_Pin_E = 6; // Pin for button 5
const int Button_Pin_F = 7; // Pin for button 6
const int Button_Pin_G = 8; // Pin for button 7
const int Button_Pin_H = 9; // Pin for button 8

// Set Default state
int Button_State_A = 1;
int Button_State_B = 1;
int Button_State_C = 1;
int Button_State_D = 1;
int Button_State_E = 1;
int Button_State_F = 1;
int Button_State_G = 1;
int Button_State_H = 1;

//Check to see if button is being held down
int lastZeroIndex = -1;
boolean firstZeroDetected = false;  // Initialize to false

int CountDownState = 0;
int CountDown = 6;

void setup() {
  Serial.begin(115200);
  // Setup Pin Modes
  pinMode(Button_Pin_A, INPUT);
  pinMode(Button_Pin_B, INPUT);
  pinMode(Button_Pin_C, INPUT);
  pinMode(Button_Pin_D, INPUT);
  pinMode(Button_Pin_E, INPUT);
  pinMode(Button_Pin_F, INPUT);
  pinMode(Button_Pin_G, INPUT);
  pinMode(Button_Pin_H, INPUT);

  //LED Setup
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // Initialize the LED strip

}
 
void loop() {
  // Get Button state
  int Button_State_A = digitalRead(Button_Pin_A);
  int Button_State_B = digitalRead(Button_Pin_B);
  int Button_State_C = digitalRead(Button_Pin_C);
  int Button_State_D = digitalRead(Button_Pin_D);
  int Button_State_E = digitalRead(Button_Pin_E);
  int Button_State_F = digitalRead(Button_Pin_F);
  int Button_State_G = digitalRead(Button_Pin_G);
  int Button_State_H = digitalRead(Button_Pin_H);

  // Put State in array
  int Button_State_Array[8];
  Button_State_Array[0] = Button_State_A;
  Button_State_Array[1] = Button_State_B;
  Button_State_Array[2] = Button_State_C;
  Button_State_Array[3] = Button_State_D;
  Button_State_Array[4] = Button_State_E;
  Button_State_Array[5] = Button_State_F;
  Button_State_Array[6] = Button_State_G;
  Button_State_Array[7] = Button_State_H;



  // Detect if there is a zero
  // Iterate through the array to find the first 0
    for (int i = 0; i < 4; i++) {
    if (Button_State_Array[i] == 0) {


      if (i != lastZeroIndex || !firstZeroDetected) {
        if (!firstZeroDetected) {
          firstZeroDetected = true;

        }
        Serial.print("Button ");
        Serial.print(i);
        Serial.println(" Pressed");
        lastZeroIndex = i;

        // Act on specifc button
        switch (i) {
          case 0:
          Serial.println("You are Happy");
          leds[currentLED] = CRGB::Yellow;
          currentLED++;    // Move to the next LED
          FastLED.show();  // Update the LED strip with the new color
          break;
          case 1:
          Serial.println("You are Sad");
          leds[currentLED] = CRGB::Blue;
          currentLED++;    // Move to the next LED
          FastLED.show();  // Update the LED strip with the new color
          break;
          case 2:
          Serial.println("You are Suprised");
          leds[currentLED] = CRGB::Green;
          currentLED++;    // Move to the next LED
          FastLED.show();  // Update the LED strip with the new color
          break;
          };

        //Turn on countdown
        CountDownState = 1;
      }


    }
  }

//countdown
// Button needs Countdown amount to be reset
  if(CountDown < 0){
    CountDownState = 0;
    CountDown = 6;
    firstZeroDetected = false;
  }

  if(CountDownState == 1){
    CountDown = CountDown - 1;
  }



  // Check if no zero was found
  if (!firstZeroDetected) {
    // Do nothing
  }


  delay(150);
  }