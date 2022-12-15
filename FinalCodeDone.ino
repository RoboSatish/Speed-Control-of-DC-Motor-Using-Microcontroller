/*
 LCS COnnections:
 1-->GND
 2-->5V
 3-->GND
 4-->D8
 5-->GND
 6-->D9
 7-->
 8-->
 9-->
 10-->
 11-->D11
 12-->D10
 13--> D6
 14--> D7
 15-->5v
 16--> GND

 POT Coonection
 Middle--> A0
 VCC and GND

 D4 and D5 connect to DC MOTOR
 */

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8,9,4,10,11,7);
int ledPin = 6;      // LED connected to digital pin 9
int ledPin1 = 5;      // LED connected to digital pin 9
int analogPin = A0;   // potentiometer connected to analog pin 3
int val = 0;         // variable to store the read value
char read1;

void setup()
{

 lcd.begin(16,2);
  pinMode(ledPin, OUTPUT);   // sets the pin as output
  pinMode(ledPin1, OUTPUT);   // sets the pin as output
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop()

{
   
  val = analogRead(analogPin); // read the input pin
  Serial.println(val);
  lcd.setCursor(0,0);
  lcd.print(val);
  delay(1000);
  analogWrite(ledPin, val / 4);// analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  lcd.clear();

  if(val>=850 && val<=1024)
  {
    lcd.setCursor(0,1);
     lcd.print("DutyCycle-100%");
    // lcd.clear();
       
  }
  if(val>=750 && val<=849)
  {
    lcd.setCursor(0,1);
     lcd.print("DutyCycle-75%");
    // lcd.clear();
       
  }

  if(val>=500 && val<=749)
  {
    lcd.setCursor(0,1);
     lcd.print("DutyCycle-50%");
    // lcd.clear();
       
  }

  if(val>=101 && val<=499)
  {
    lcd.setCursor(0,1);
     lcd.print("DutyCycle-25%");
    // lcd.clear();
       
  }

  if(val>=1 && val<=100)
  {
    lcd.setCursor(0,1);
     lcd.print("DutyCycle-0 %");
    // lcd.clear();
       
  }
  
  

if (Serial.available()>0) 
{

  read1=Serial.read();

  if(read1=='1')
{
 analogWrite(ledPin,1023/4);
 delay(2000);
}
  if(read1=='2')
{
 analogWrite(ledPin,700/4);
 delay(2000);
}
  if(read1=='3')
{
 analogWrite(ledPin,400/4);
 delay(2000);
}
  if(read1=='4')
{
 analogWrite(ledPin,4/4);
 delay(2000);

} 
}
}
  
