/*
 ================================================================================================
 Name        : App.c
 Author      : Joe Metwally
 Description : Calculate the required speed based on the temperature
 ================================================================================================
 */

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "motor.h"
typedef enum {
		OFF, ON
	} fan_state_type;
/* define a type for the state of the fan for easier readability */

int main(void) {
	uint8 temp; /*initialize a variable to store the temperature reading from adc*/
	fan_state_type state; /*initialize a variable to track fan state*/
	ADC_ConfigType configuration; /*initialize variable to store the adc configuration*/
	configuration.ADC_ReferenceVolatge = INTERNAL; /*choose the required reference voltage for adc*/
	configuration.ADC_Prescaler = prescalar_8; /*choose the required prescalar for adc */
	LCD_init(); /* initialize LCD driver */
	ADC_init(&configuration); /* initialize ADC driver with the specified configurations */
	DcMotor_Init(); /*initialize the fan motor*/


	LCD_moveCursor(0, 3);
	LCD_displayString("FAN is    ");
	/* Display this string "FAN is   " only once on LCD at the middle of the first row */
	LCD_moveCursor(1, 3);
	LCD_displayString("Temp =    C");
	/* Display this string "Temp =   C" only once on LCD at the middle of the second row */

	for (;;) {

		temp = LM35_getTemperature();

		/* Display the temperature value every time at same position */
		LCD_moveCursor(1, 10);
		if (temp >= 100) {
			LCD_intgerToString(temp);
		} else {
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		/*required logic calculations for correct speed and direction rotation of the fan*/
		if (temp >= 120) {
			DcMotor_Rotate(CW, 100);
			state = ON;
		} else if (temp >= 90) {
			DcMotor_Rotate(CW, 75);
			state = ON;
		} else if (temp >= 60) {
			DcMotor_Rotate(CW, 50);
			state = ON;
		} else if (temp >= 30) {
			DcMotor_Rotate(CW, 25);
			state = ON;
		} else if (temp < 30) {
			DcMotor_Rotate(STOP, 0);
			state = OFF;
		}
		/* Display the fan state every time at same position */
		LCD_moveCursor(0, 10);
		if (state == OFF) {
			LCD_displayString("OFF");
		} else {
			LCD_displayString("ON ");

		}
	}
}
