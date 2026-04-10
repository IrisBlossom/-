#include "Servo_Motor.h"
#include "sys.h"
#include "stm32f10x_tim.h"

void Servo_Motor_Init(){

}

void Set_Servo_Angle(uint8_t channel, uint16_t angle){
    if(angle > 180) angle = 180;
    
    uint16_t pulse = 150 + (angle * 600 / 180);
    
    switch(channel){
        case 1:
            TIM_SetCompare1(TIM2, pulse);
            break;
        case 2:
            TIM_SetCompare2(TIM2, pulse);
            break;
        case 3:
            TIM_SetCompare3(TIM2, pulse);
            break;
    }
}
