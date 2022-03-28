#include <Wire.h>
#include "RTClib.h"

#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 

RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

LiquidCrystal_I2C lcd(0x27,16,2);

void setup () {

lcd.init();
lcd.backlight();
lcd.setCursor(0, 0);

 while (!Serial); // for Leonardo/Micro/Zero
 Serial.begin(57600);
 if (! rtc.begin()) {
   Serial.println("Couldn't find RTC");
   while (1);
 }
 if (! rtc.isrunning()) {
   Serial.println("RTC is NOT running!");
   // following line sets the RTC to the date & time this sketch was compiled
   rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
   // This line sets the RTC with an explicit date & time, for example to set
   // January 21, 2014 at 3am you would call:
   // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
 }
}
void loop () {
 DateTime now = rtc.now();
 lcd.print(now.day(), DEC);
 lcd.print('/');
 lcd.print(now.month(), DEC);
 lcd.print('/');
 lcd.print(now.year(), DEC);

 lcd.setCursor(-1, 1);
 lcd.print(" (");
 lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
 lcd.print(") ");
 lcd.print(now.hour(), DEC);
 lcd.print(':');
 lcd.print(now.minute(), DEC);
 lcd.print(':');
 lcd.print(now.second(), DEC);
 lcd.println();
lcd.setCursor(0, 2); 
}
