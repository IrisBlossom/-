#include "Bsp.h" 
#include "Motor.h"
#include "Servo_Motor.h"
#include "CH452.h"
#include "stm32f10x_tim.h"
#include "timer.h"
int Motor_PWM_1=0;
int Motor_PWM_2=0;
int Motor_PWM_3=0;
int key_current=0;
int key_last=0;
int motor7_running = 0;
//polabear2.0

int main(void)//������
{
    BSP_Init();
		while(1)
		{	
		Key_Handle();
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
                Set_Motor1_RPM(10);
                break;
            case 2:
                Set_Motor1_RPM(20);
                break;
            case 3:
                Set_Motor1_RPM(30);
                break;
            case 4:
                Set_Motor1_RPM(-10);
                break;
            case 5:
                Set_Motor1_RPM(-20);
                break;
            case 6:
                Set_Motor1_RPM(-30);
                break;
            case 7:
                motor7_running = 1;
                Set_Motor1_RPM(150);
                break;
            case 0:
                motor7_running = 0;
                Set_Motor1_RPM(0);
								break;
						case 9:
								Set_Servo_Angle(2, 45);
								delay_s(2);
								Set_Servo_Angle(2, 90);
								delay_s(2);
								Set_Servo_Angle(2, 135);
								delay_s(2);
								Set_Servo_Angle(2, 180);
								delay_s(2);
								Set_Servo_Angle(2, 135);
								delay_s(2);
								Set_Servo_Angle(2, 90);
								delay_s(2);
								Set_Servo_Angle(2, 45);
								delay_s(2);
								Set_Servo_Angle(2, 0);
								break;
        }
        key_last = key_current;
    }
	}
