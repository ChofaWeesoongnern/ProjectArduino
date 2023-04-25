#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int pinSpeed_1 = 13;
int pinSpeed_2 = 12;
int pinSpeed_3 = 11;
int pinSpeed_4 = 10 ;

int state_Speed_1 = 0;
int state_Speed_2 = 0;
int state_Speed_3 = 0;
int state_Speed_4 = 0;

int coin_10 = 0 ;
int coin_5 = 0 ;
int coin_2 = 0 ;
int coin_1 = 0 ;
int sum = 0;

int oneClink_1 = 0;
int oneClink_2 = 0;
int oneClink_3 = 0;
int oneClink_4 = 0;

void setup()
{
  lcd.init();     // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("1  2  5  10  sum");

  Serial.begin(9600);
  delay(50);
  pinMode(pinSpeed_1, INPUT); 
  pinMode(pinSpeed_2, INPUT); 
  pinMode(pinSpeed_3, INPUT);
  pinMode(pinSpeed_4, INPUT);
}

void loop()
{

  state_Speed_1 = digitalRead(pinSpeed_1);
  state_Speed_2 = digitalRead(pinSpeed_2);
  state_Speed_3 = digitalRead(pinSpeed_3);
  state_Speed_4 = digitalRead(pinSpeed_4);
  
  Serial.println(state_Speed_1);
  Serial.println(state_Speed_2);
  Serial.println(state_Speed_3);
  Serial.println(state_Speed_4);

  if (state_Speed_1 == 1) {
    if (oneClink_1 == 0) {
      oneClink_1 = 1;
      coin_1++;
      sum = sum + 1;
    }
  }
  else if (state_Speed_1 == 0 ) {
    oneClink_1 = 0;
  }



  if (state_Speed_2 == 1) {
    if (oneClink_2 == 0) {
      oneClink_2 = 1;
      coin_2++;
      sum = sum + 2;
    }
  }
  else if (state_Speed_2 == 0 ) {
    oneClink_2 = 0;
  }



  if (state_Speed_3 == 1) {
    if (oneClink_3 == 0) {
      oneClink_3 = 1;
      coin_5 ++;
      sum = sum + 5;
    }
  }
  else if (state_Speed_3 == 0 ) {
    oneClink_3 = 0;
  }


if (state_Speed_4 == 1) {
    if (oneClink_4 == 0) {
      oneClink_4 = 1;
      coin_10 ++;
      sum = sum + 10;
    }
  }
  else if (state_Speed_4 == 0 ) {
    oneClink_4 = 0;
  }

  Serial.println(coin_1);
  Serial.println(coin_2);
  Serial.println(coin_5);
  Serial.println(coin_10);


  lcd.setCursor(0, 1);
  lcd.print(coin_1);

  lcd.setCursor(3, 1);
  lcd.print(coin_2);

  lcd.setCursor(6, 1);
  lcd.print(coin_5);

  lcd.setCursor(9, 1);
  lcd.print(coin_10);

  lcd.setCursor(13,1);
  lcd.print(sum);


}
