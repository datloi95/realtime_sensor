// include the library code:
//#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(4, 5, 9, 10, 11, 12);
#define analogPin A0 //the thermistor attach to 
#define beta 4090 //the beta of the thermistor
#define resistance 10 //the value of the pull-down resistor

float sumTemp = 0;
int i = 0;
float maxTemp = -500;
float minTemp = 500;
void setup()
{
Serial.begin(9600);
}
void loop()
{
//read thermistor value 
long a = analogRead(analogPin);
//the calculating formula of temperature
float tempC = beta /(log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;

sumTemp = sumTemp + tempC;
i++;

if (tempC >= maxTemp)
{
  maxTemp = tempC;
}
if (tempC <= minTemp)
{
  minTemp = tempC;
}


//Serial.print("Current Temp: ");
Serial.print(tempC, "\n");
Serial.print("\n");
/*
Serial.print("Average temperature is ");
Serial.print(sumTemp/i);
Serial.print(" C\n");

Serial.print("Maximimum temperature is ");
Serial.print(maxTemp);
Serial.print(" C\n");

Serial.print("Minimum temperature is ");
Serial.print(minTemp);
Serial.print(" C\n");
Serial.print("\n");
*/
delay(2000);
}
