/**
 * This is simple test code for my CNC Router PCB
 * You can find out more at www.github.com/njhulsey
 * 
 * 
 * Nick Hulsey (@njhulsey)
 * 8/27/2019
 */


#include <Adafruit_NeoPixel.h>

#define DIR1                 36
#define STEP1                37

#define DIR2                 34
#define STEP2                35

#define DIR3                 32
#define STEP3                33

#define NEO_PIXEL_PIN        8 
Adafruit_NeoPixel pixels(1, NEO_PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(20);
  ledColor(0xFF00BF);

  Serial.begin(115200);
  ledColor(0x00DFBF);
  

  pinMode(DIR1,OUTPUT);
  pinMode(STEP1,OUTPUT);

  pinMode(DIR2,OUTPUT);
  pinMode(STEP2,OUTPUT);
  
  pinMode(DIR3,OUTPUT);
  pinMode(STEP3,OUTPUT);


}

void loop() {

  delay(1000);
  Serial.write("Turning motor 1 for 500 millisec\n");
 
  digitalWrite(DIR1,HIGH); // Enables the motor to move in a particular direction
  digitalWrite(DIR2,LOW);
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(STEP1,HIGH); 
    digitalWrite(STEP2,HIGH);
    delayMicroseconds(500); 
    digitalWrite(STEP1,LOW); 
    digitalWrite(STEP2,LOW);
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
}


void ledColor(uint32_t color){
  pixels.setPixelColor(0, color);
  pixels.show();   // Send the updated pixel colors to the hardware.
}
