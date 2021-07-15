/*
 * Project Lab19
 * Description:
 * Author:
 * Date:
 */
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
#include "WatchDog_WCL.h"
#include "oled-wing-adafruit.h"
OledWingAdafruit display;
WatchDog wd;
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(D5,INPUT);
  display.setup();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  Serial.begin(9600);
  wd.initialize(5000);

  if(System.resetReason() == RESET_REASON_WATCHDOG){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Watch Dog timer issue reset");
    display.display();
  }
  else{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Normal issue reset");
    display.display();
  }


}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  if(D5 == HIGH){
    wd.pet();
  }
  
}