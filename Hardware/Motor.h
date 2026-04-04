#ifndef __MOTOR_H
#define __MOTOR_H	

#define Motor1_Enable() GPIO_SetBits(GPIOB,GPIO_Pin_12)    // ʹ��Motor1
#define Motor1_Disable() GPIO_ResetBits(GPIOB,GPIO_Pin_12) // ʧ��Motor1
#define Motor2_Enable() GPIO_SetBits(GPIOB,GPIO_Pin_13)    // ʹ��Motor2
#define Motor2_Disable() GPIO_ResetBits(GPIOB,GPIO_Pin_13) // ʧ��Motor2
#define Motor3_Enable() GPIO_SetBits(GPIOB,GPIO_Pin_14)    // ʹ��Motor3
#define Motor3_Disable() GPIO_ResetBits(GPIOB,GPIO_Pin_14) // ʧ��Motor3
#define Motor4_Enable() GPIO_SetBits(GPIOB,GPIO_Pin_15)    // ʹ��Motor4
#define Motor4_Disable() GPIO_ResetBits(GPIOB,GPIO_Pin_15) // ʧ��Motor4

void Motor_Init(void);
void Set_Motor1_RPM(int RPM);
void Set_Motor2_RPM(int RPM);
void Set_Motor3_RPM(int RPM);
void Set_Motor4_RPM(int RPM);

#endif
