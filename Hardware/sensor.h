#ifndef __SENSOR_H
#define __SENSOR_H

#include "sys.h"
#include "stm32f10x_gpio.h"

void Sensor_Init(void);
uint8_t Get_Sensor1_Status(void);
uint8_t Get_Sensor2_Status(void);
uint8_t Get_Sensor3_Status(void);
uint8_t Get_Sensor4_Status(void);
uint8_t Get_Sensor5_Status(void);

#endif