#include <LiquidCrystal.h>
#include <Time.h>
#include <Wire.h>
#include <DS1307RTC.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  //clear screen
  lcd.clear();
  // Print a message to the LCD.
  lcd.print("CO:de champions");
  lcd.setCursor(0, 1);
  lcd.print("until ");
}

void loop () {


  setSyncProvider(RTC.get); //need RTC chip installed to work. Otherwise, just counting down secs.

  time_t timeLeft,eventDate; // setup the fields needed.
       eventDate = 12732290; // April 01, 2016, in seconds until RTC chip is installed
       timeLeft = eventDate - now();

      // Display the seconds until event.
      lcd.setCursor(6, 1);
      lcd.print(timeLeft);
      delay(1000);
}
