#include <LiquidCrystal_I2C.h>
#define BUZZER 5
#define BUTTON 6

LiquidCrystal_I2C lcd(0x27, 16, 2);
bool buttonPressed = false;

void setup()
{
lcd.init();
lcd.backlight();
pinMode(2, OUTPUT);//RED VH, GREEN PD
pinMode(3, OUTPUT);//yellow VH
pinMode(4, OUTPUT);//Green VH RED PD
pinMode(BUZZER, OUTPUT);
pinMode(BUTTON, INPUT_PULLUP);
}

void playTone() {
tone(BUZZER, 2000);
delay(75);
noTone(BUZZER);
delay(75);
tone(BUZZER, 2000);
delay(75);
noTone(BUZZER);
delay(75);
}

void loop()
{
int time_left = 30;
int time_left2 = 30;

int buttonState = digitalRead(BUTTON);

if (digitalRead(BUTTON) == HIGH && !buttonPressed){
  buttonPressed = true;
  goto a;
}
else if (digitalRead(BUTTON) == LOW && buttonPressed) {
buttonPressed = false;
digitalWrite(3, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(2, HIGH);
while (time_left > 0) {
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Timer: ");
lcd.print(time_left);
lcd.setCursor(0, 1);
lcd.print("Cross Now");
delay(750);
time_left--;
playTone();
}
}

a:

lcd.clear();
digitalWrite(2, LOW);
digitalWrite(4, LOW);
delay(500);
digitalWrite(3, HIGH);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Time's Up!");
delay(5000);
digitalWrite(3, LOW);
delay(1000);



while (time_left2 > 0) {
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Timer: ");
lcd.print(time_left2);
lcd.setCursor(0, 1);
lcd.print("Please Wait");
delay(1000);
time_left2--;
}
}
