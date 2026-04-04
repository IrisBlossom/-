#ifndef __SERVO_MOTOR_H
#define __SERVO_MOTOR_H

#include "stdint.h"

void Servo_Motor_Init(void);
void Set_Servo_Angle(uint8_t channel, uint16_t angle);

#endif
