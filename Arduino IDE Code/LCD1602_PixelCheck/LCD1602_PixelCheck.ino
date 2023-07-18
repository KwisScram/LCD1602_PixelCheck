#include <Arduino.h>

/*
Display wiring :
1  --> VSS --> GND
2  --> VDD --> +
3  --> VO  --> Middle pin of 10K Potentiometer. (potentiometer needs a + en - on the outer pins)
4  --> RS  --> to pin 7 of arduino
5  --> RW  --> GND
6  --> E   --> to pin 8 of arduino
7  --> D0  -->
8  --> D1  -->
9  --> D2  -->
10 --> D3  -->
11 --> D4  --> to pin 9 of arduino
12 --> D5  --> to pin 10 of arduino
13 --> D6  --> to pin 11 of arduino
14 --> D7  --> to pin 12 of arduino
15 --> A   --> +
16 --> K   --> GND
*/

#include <LiquidCrystal.h>                 //Include library (see Library manager)
int rs = 7;                                // set variable
int en = 8;                                // set variable
int d4 = 9;                                // set variable
int d5 = 10;                               // set variable
int d6 = 11;                               // set variable
int d7 = 12;                               // set variable
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // define pins to LCD

// create a variable with the desired pattern for the "odd" pixels
byte odd[] = {
    B11111,
    B01010,
    B10101,
    B01010,
    B10101,
    B01010,
    B10101,
    B01010};

// create a variable with the desired pattern for the "even" pixels
byte even[] = {
    B01010,
    B10101,
    B01010,
    B10101,
    B01010,
    B10101,
    B01010,
    B10101};

void setup()
{
  lcd.begin(16, 2);        // define number of Columns and row's
  lcd.createChar(0, odd);  // Create a character name 0. The array variable made in the 'byte' under "odd"
  lcd.createChar(1, even); // Create a character name 1. The array variable made in the 'byte' under "even"
  lcd.home();
}

void loop()
{

/*
Notes:
- lcd.setCursor(x, y) = Set cursor to location Colom x and row y (counting from zero)
- The FOR loop        = counts to 16 so after printing 1 character it shfits aside 16 times (because a row has 16 characters)
- lcd.write(byte(x))  = Prints the array (x). Where (x) is the number of the array (in this case the "odd" character)
- lcd.setCursor(x, y) = after 16 times the FOR loop has run it will shift to the next row and repeats with the same character
- delay               = Wait for 1000 Milli Seconds (1 second)
*/

  lcd.setCursor(0, 0);

    for (int i = 0; i < 16; i++)
    {
      lcd.write(byte(0));
    }

  lcd.setCursor(0, 1);

    for (int i = 0; i < 16; i++)
    {
      lcd.write(byte(0));
    }

  delay(1000);

// Now it does the SAME all over with the "even" character. 

  lcd.setCursor(0, 0);

    for (int i = 0; i < 16; i++)
    {
      lcd.write(byte(1));
    }

  lcd.setCursor(0, 1);

    for (int i = 0; i < 16; i++)
    {
      lcd.write(byte(1));
    }
  delay(1000);
}
