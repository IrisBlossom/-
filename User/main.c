#include "Bsp.h" 
#include "Motor.h"
#include "CH452.h"
#include "stm32f10x_tim.h"
#include "timer.h"
int Motor_PWM_1=0;
int Motor_PWM_2=0;
int Motor_PWM_3=0;


int main(void)//主程序
{
    BSP_Init();
    while(1)
        {
            Motor_PWM_1=(RC_CH1-1500)/2;//Rc_Ch1值是1000(最左边)----2000(最右边)
            if((Motor_PWM_1>=20&&Motor_PWM_1<=250) ||((Motor_PWM_1>=-250)&&Motor_PWM_1<=-20))//可删除，注意初始位置时 1.电机转速和2.遥控器值
                Set_Motor1_RPM(Motor_PWM_1); 
            else
               Set_Motor1_RPM(0);  
        }
        
}



		



