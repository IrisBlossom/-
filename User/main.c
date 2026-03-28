#include "Bsp.h"
#include "Motor.h"
#include "CH452.h"
#include "stm32f10x_tim.h"
#include "timer.h"

int Motor_PWM_1=0;
int Motor_PWM_2=0;
int Motor_PWM_3=0;

u8 key_current = 16;
u8 key_last = 16;
u8 motor7_running = 0;
u8 servo_angle_index = 0;
u8 servo_direction = 1;
u32 servo_timer = 0;
u8 servo_moving = 0;

void Steering_Init_Main(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_Period = 7199;
    TIM_TimeBaseStructure.TIM_Prescaler = 199;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);

    TIM_OCStructInit(&TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OC4Init(TIM2, &TIM_OCInitStructure);

    TIM_Cmd(TIM2,ENABLE);
}

void Set_Servo_Angle(u8 angle)
{
    u16 pulse = 500 + (angle * 2000 / 180);
    TIM_SetCompare4(TIM2, pulse);
}

void Servo_Control(void)
{
    if(servo_moving)
    {
        servo_timer++;
        if(servo_timer >= 2000)
        {
            servo_timer = 0;

            if(servo_direction == 1)
            {
                servo_angle_index++;
                if(servo_angle_index >= 8)
                {
                    servo_angle_index = 7;
                    servo_direction = 0;
                }
            }
            else
            {
                if(servo_angle_index == 0)
                {
                    servo_moving = 0;
                    return;
                }
                servo_angle_index--;
            }

            u8 angles[8] = {0, 45, 90, 135, 180, 135, 90, 45};
            Set_Servo_Angle(angles[servo_angle_index]);
        }
    }
}

void Key_Handle(void)
{
    key_current = CH452_GetKey();

    if(key_current != key_last)
    {
        if(key_last == 1 || key_last == 2 || key_last == 3 ||
           key_last == 4 || key_last == 5 || key_last == 6)
        {
            Set_Motor1_RPM(0);
        }

        switch(key_current)
        {
            case 1:
                Set_Motor1_RPM(100);
                break;
            case 2:
                Set_Motor1_RPM(200);
                break;
            case 3:
                Set_Motor1_RPM(300);
                break;
            case 4:
                Set_Motor1_RPM(-100);
                break;
            case 5:
                Set_Motor1_RPM(-200);
                break;
            case 6:
                Set_Motor1_RPM(-300);
                break;
            case 7:
                motor7_running = 1;
                Set_Motor1_RPM(150);
                break;
            case 8:
                motor7_running = 0;
                Set_Motor1_RPM(0);
                break;
            case 9:
                servo_moving = 1;
                servo_angle_index = 0;
                servo_direction = 1;
                servo_timer = 0;
                Set_Servo_Angle(0);
                break;
        }
        key_last = key_current;
    }

    if(motor7_running)
    {
        Set_Motor1_RPM(150);
    }
}

int main(void)
{
    BSP_Init();
    Steering_Init_Main();
    Set_Servo_Angle(0);

    while(1)
    {
        Key_Handle();
        Servo_Control();
        delay_ms(1);
    }
}
