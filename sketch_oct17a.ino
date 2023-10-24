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

// Debounce variables
const unsigned long debounceDelay = 50;  // Adjust this value as needed
unsigned long lastDebounceTime = 0;
int lastButtonState = HIGH;

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
  Button_State_A = debounce(Button_Pin_A, Button_State_A);

  int Button_State_B = digitalRead(Button_Pin_B);
  Button_State_A = debounce(Button_Pin_B, Button_State_B);

  int Button_State_C = digitalRead(Button_Pin_C);
  Button_State_A = debounce(Button_Pin_C, Button_State_C);

  int Button_State_D = digitalRead(Button_Pin_D);
  Button_State_A = debounce(Button_Pin_D, Button_State_D);

  int Button_State_E = digitalRead(Button_Pin_E);
  Button_State_A = debounce(Button_Pin_E, Button_State_E);

  int Button_State_F = digitalRead(Button_Pin_F);
  Button_State_A = debounce(Button_Pin_F, Button_State_F);

  int Button_State_G = digitalRead(Button_Pin_G);
  Button_State_A = debounce(Button_Pin_G, Button_State_G);

  int Button_State_H = digitalRead(Button_Pin_H);
  Button_State_A = debounce(Button_Pin_H, Button_State_H);

  // Put State in array
  int Button_State_Array[8];
  Button_State_Array[1] = Button_State_A;
  Button_State_Array[2] = Button_State_B;
  Button_State_Array[3] = Button_State_C;
  Button_State_Array[4] = Button_State_D;
  Button_State_Array[5] = Button_State_E;
  Button_State_Array[6] = Button_State_F;
  Button_State_Array[7] = Button_State_G;
  Button_State_Array[8] = Button_State_H;
  
  delay(150);
  }

  int debounce(int buttonPin, int buttonState) {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      // Handle the button press here...
      if (buttonState == LOW) {
        // The button is pressed
        Serial.print("Button Pressed: ");
        Serial.println(buttonPin);
        // Update LEDs or perform other actions as needed
      }
    }
  }

  lastButtonState = reading;
  return buttonState;
}