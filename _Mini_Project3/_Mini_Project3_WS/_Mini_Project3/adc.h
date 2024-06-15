 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Joe Metwally
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                                Type Declarations                            *
 *******************************************************************************/
typedef enum{
	AREF,AVCC,INTERNAL=3
}ref_volt;
/*type definition for reference voltage configurations*/
typedef enum{
	prescalar_2,prescalar_4=2,prescalar_8,prescalar_16,prescalar_32,prescalar_64,prescalar_128
}prescalar;
/*type definition for prescalar configurations*/
typedef struct{
 ref_volt ADC_ReferenceVolatge;
 prescalar ADC_Prescaler;
}ADC_ConfigType;
/*type definition for ADC configurations*/
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
