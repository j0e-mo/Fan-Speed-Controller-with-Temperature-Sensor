/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: Joe Metwally
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void ADC_init(const ADC_ConfigType *Config_Ptr) {
	ADMUX = (ADMUX & 0x3F) | ((0x0003 & Config_Ptr->ADC_ReferenceVolatge) << 6);
	ADCSRA = (1 << ADEN)
			| ((ADCSRA & 0xFC) | (0x0003 & Config_Ptr->ADC_Prescaler));
	/*initialize ADC with the required configuration using insertion*/
}

uint16 ADC_readChannel(uint8 channel_num) {
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA, ADSC); /* Start conversion write '1' to ADSC */
	while (BIT_IS_CLEAR(ADCSRA, ADIF))
		; /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA, ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
