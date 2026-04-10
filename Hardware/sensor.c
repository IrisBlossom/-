#include "sensor.h"

void Sensor_Init(){
    GPIO_InitTypeDef GPIO_Input;

    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

    GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Input.GPIO_Pin = GPIO_Pin_12;
    GPIO_Init(GPIOA, &GPIO_Input);

    GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Input.GPIO_Pin = GPIO_Pin_15;
    GPIO_Init(GPIOA, &GPIO_Input);

    GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Input.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOB, &GPIO_Input);

    GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Input.GPIO_Pin = GPIO_Pin_4;
    GPIO_Init(GPIOB, &GPIO_Input);

    GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Input.GPIO_Pin = GPIO_Pin_5;
    GPIO_Init(GPIOB, &GPIO_Input);

    GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Input.GPIO_Pin = GPIO_Pin_8;
    GPIO_Init(GPIOB, &GPIO_Input);

    GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Input.GPIO_Pin = GPIO_Pin_9;
    GPIO_Init(GPIOB, &GPIO_Input);

    GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Input.GPIO_Pin = GPIO_Pin_13;
    GPIO_Init(GPIOC, &GPIO_Input);

    GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Input.GPIO_Pin = GPIO_Pin_14;
    GPIO_Init(GPIOC, &GPIO_Input);
}

uint8_t Get_Sensor1_Status(void){
    return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12);
}

uint8_t Get_Sensor2_Status(void){
    return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15);
}

uint8_t Get_Sensor3_Status(void){
    return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3);
}

uint8_t Get_Sensor4_Status(void){
    return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4);
}

uint8_t Get_Sensor5_Status(void){
    return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5);
}