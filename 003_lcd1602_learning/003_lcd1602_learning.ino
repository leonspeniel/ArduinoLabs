#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

// Your long message
String message = "Leons Chelladurai, Sherin Melba, Lemuel Leons, Lucas Leons ";

void setup() {
  lcd.begin(16,2);
  lcd.print(message);

}

void loop() {
  //Simple Display
  //lcd.scrollDisplayLeft();
  //delay(300);

  // FOr long string in single row
  // Scroll the text to the left every 300 milliseconds
  for (int position = 0; position < message.length(); position++) {
    lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
    lcd.print(message.substring(position)); // Print the substring starting at the current position
    lcd.print(message.substring(0, position)); // Print the substring from the beginning to the current position
    delay(300);
  }
}
