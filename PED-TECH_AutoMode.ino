#include <LiquidCrystal_I2C.h>
#define BUZZER 5

//AUTOMATIC VERSION


LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void setup()
{
lcd.init(); // initialize the lcd
lcd.backlight();
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(13, OUTPUT);
pinMode(BUZZER, OUTPUT);
}

void playTone() {
tone(BUZZER, 2000); // play a tone of frequency 1000 Hz
delay(75); // wait for half a second
noTone(BUZZER); // stop the tone
delay(75); // wait for half a second
tone(BUZZER, 2000); // play a tone of frequency 2000 Hz 1700 is stable
delay(75); // wait for half a second
noTone(BUZZER); // stop the tone
delay(75); // wait for half a second
}



void loop()
{
int time_left = 30; // timer in seconds
int time_left2 = 30;

digitalWrite(4, LOW);
digitalWrite(2, HIGH);//Vehicle RED LED ON
digitalWrite(13, LOW);
while (time_left > 0) {
lcd.clear(); // clear display
lcd.setCursor(0, 0); // move cursor to (0, 0)
lcd.print("Timer: "); // print message at (0, 0)
lcd.print(time_left); // print timer value
lcd.setCursor(0, 1); // move cursor to (0, 1)
lcd.print("Cross Now"); // print message at (0, 1)
delay(750); // wait for 1 second
 // decrease timer value
time_left--;
playTone();

}



lcd.clear();

digitalWrite(2, LOW); // turn the RED Light Off
delay(500); // transiition to yellow LED

digitalWrite(3, HIGH);
digitalWrite(13, LOW); //Yellow LED On
lcd.clear(); // clear display
lcd.setCursor(0, 0); // move cursor to (0, 0)
lcd.print("Time's Up!"); // print message at (0, 0)
delay(5000); //Yellow LED on for 5s
digitalWrite(3, LOW);
delay(1000);//Yellow LED transition to Green


digitalWrite(4, HIGH);
digitalWrite(13, LOW);//Vehicle RED LED ON
while (time_left2 > 0) {
lcd.clear(); // clear display
lcd.setCursor(0, 0); // move cursor to (0, 0)
lcd.print("Timer: "); // print message at (0, 0)
lcd.print(time_left2); // print timer value
lcd.setCursor(0, 1); // move cursor to (0, 1)
lcd.print("Please Wait"); // print message at (0, 1)
delay(1000); // wait for 1 second
time_left2--; // decrease timer value
}


}
