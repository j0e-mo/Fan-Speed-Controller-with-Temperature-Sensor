 /******************************************************************************
 *
 * Module: MOTOR
 *
 * File Name: motor.h
 *
 * Description: Header file for the AVR MOTOR driver
 *
 * Author: Joe Metwally
 *
 *******************************************************************************/
#ifndef MOTOR_H_
#define MOTOR_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#include "std_types.h"
#define DcMotor_PORT PORTD_ID
#define DcMotor_PIN PIN3_ID
/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum{
	STOP,CW,A_CW
}DcMotor_State;
/*type definition for rotation directions of the Dc Motor*/
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Initializes the motor module with connected h-bridge
 */
void DcMotor_Init(void);

/*
 * Description :
 * Changes the direction the motor is moving towards
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* MOTOR_H_ */
