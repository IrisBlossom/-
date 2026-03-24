#include "Bsp.h" 
#include "Motor.h"
#include "CH452.h"
#include "stm32f10x_tim.h"
#include "timer.h"
int Motor_PWM_1=0;
int Motor_PWM_2=0;
int Motor_PWM_3=0;
//polabear2.0

int main(void)//������
{
    BSP_Init();
    while(1)
        {
            Motor_PWM_1=(RC_CH1-1500)/2;//Rc_Ch1ֵ��1000(�����)----2000(���ұ�)
            if((Motor_PWM_1>=20&&Motor_PWM_1<=250) ||((Motor_PWM_1>=-250)&&Motor_PWM_1<=-20))//��ɾ����ע���ʼλ��ʱ 1.���ת�ٺ�2.ң����ֵ
                Set_Motor1_RPM(Motor_PWM_1); 
            else
               Set_Motor1_RPM(0);  
        }
        
}



		



