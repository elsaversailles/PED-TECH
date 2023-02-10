#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
SoftwareSerial mySerial(10, 11); // RX, TX


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  lcd.init(); // initialize the lcd
  lcd.backlight();
  mySerial.begin(9600);
  Serial.begin(9600);

  sendCommand("AT");
  sendCommand("AT+ROLE0");
  sendCommand("AT+UUID0xFFE0");
  sendCommand("AT+CHAR0xFFE1");
  sendCommand("AT+NAMEStopLight");
  
 
}

void sendCommand(const char * command){
  Serial.print("Command send :");
  Serial.println(command);
  mySerial.println(command);
  //wait some time
  delay(100);
  
  char reply[100];
  int i = 0;
  while (mySerial.available()) {
    reply[i] = mySerial.read();
    i += 1;
  }
  //end the string
  reply[i] = '\0';
  Serial.println(reply);
  Serial.println("Reply end");
}

void loop() {
  // Check if there is data available in the Bluetooth serial buffer
  if (mySerial.available() > 0) {
    // Read the incoming character
    char incomingByte = mySerial.read();

    // If the character is 'c', turn on the LED
    if (incomingByte == 'c') {
      digitalWrite(2, HIGH);
      lcd.clear(); // clear display
lcd.setCursor(0, 0); // move cursor to (0, 0)
lcd.print("Debug Mode "); // print message at (0, 0)
lcd.setCursor(0, 1); // move cursor to (0, 1)
lcd.print("VH Red ON");
    }
    else if (incomingByte == 'f'){
      digitalWrite(3, HIGH);
      lcd.clear(); // clear display
lcd.setCursor(0, 0); // move cursor to (0, 0)
lcd.print("Debug Mode "); // print message at (0, 0)
lcd.setCursor(0, 1); // move cursor to (0, 1)
lcd.print("Amber ON");
    }
    else if (incomingByte == 'g'){
      digitalWrite(4, HIGH);
      lcd.clear(); // clear display
lcd.setCursor(0, 0); // move cursor to (0, 0)
lcd.print("Debug Mode "); // print message at (0, 0)
lcd.setCursor(0, 1); // move cursor to (0, 1)
lcd.print("VH Green ON");
    }
    else if (incomingByte == 'd') {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      lcd.clear(); // clear display
lcd.setCursor(0, 0); // move cursor to (0, 0)
lcd.print("Debug Mode "); // print message at (0, 0)
lcd.setCursor(0, 1); // move cursor to (0, 1)
lcd.print("RESET");
    }
  }
}
