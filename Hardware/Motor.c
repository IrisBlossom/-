#include "Motor.h"
#include "sys.h" // STMͷ�ļ�
void Motor_Init(){
	GPIO_InitTypeDef GPIO_Motor;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM1,ENABLE); // TIM1��Ҫ��ӳ��
	
	// PB12����Motor1��ʹ��
	GPIO_Motor.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Motor.GPIO_Pin = GPIO_Pin_12;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Motor);
	Motor1_Enable(); // ʹ��Motor1,���Motor.h
	
	// PB13����Motor2��ʹ��
	GPIO_Motor.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Motor.GPIO_Pin = GPIO_Pin_13;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Motor);
	Motor2_Enable(); // ʹ��Motor2
	
	// PB14����Motor3��ʹ��
	GPIO_Motor.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Motor.GPIO_Pin = GPIO_Pin_14;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Motor);
	Motor3_Enable(); // ʹ��Motor3
	
	// PB15����Motor4��ʹ��
	GPIO_Motor.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Motor.GPIO_Pin = GPIO_Pin_15;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Motor);
	Motor4_Enable(); // ʹ��Motor4
	
	// PA6ΪTIM3��CH1ͨ����Motor1+
	GPIO_Motor.GPIO_Pin = GPIO_Pin_6;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Motor);

	// PA7ΪTIM3��CH2ͨ����Motor1-
	GPIO_Motor.GPIO_Pin = GPIO_Pin_7;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Motor);
	
	// PB0ΪTIM3��CH3ͨ����Motor2+
	GPIO_Motor.GPIO_Pin = GPIO_Pin_0;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Motor);

	// PB1ΪTIM3��CH4ͨ����Motor2-
	GPIO_Motor.GPIO_Pin = GPIO_Pin_1;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Motor);
	
	// PA8ΪTIM1��CH1ͨ����Motor3+
	GPIO_Motor.GPIO_Pin = GPIO_Pin_8;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Motor);

	// PA9ΪTIM1��CH2ͨ����Motor3-
	GPIO_Motor.GPIO_Pin = GPIO_Pin_9;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Motor);
	
	// PA10ΪTIM1��CH3ͨ����Motor4+
	GPIO_Motor.GPIO_Pin = GPIO_Pin_10;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Motor);

	// PA11ΪTIM1��CH4ͨ����Motor4-
	GPIO_Motor.GPIO_Pin = GPIO_Pin_11;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Motor);
	
	// ����TIM1��TIM3��ʱ������
	TIM_TimeBaseStructure.TIM_Period = (1000-1); // �������Զ���װ������ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = 0; // ����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; // ����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); // ��ʼ��TIM1
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); // ��ʼ��TIM3
	
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; // ѡ��PWMģʽ 2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; // �Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;// ������Ը�
	TIM_OC1Init(TIM1, &TIM_OCInitStructure); // ��ʼ������TIM1 OC1
	TIM_OC2Init(TIM1, &TIM_OCInitStructure); // ��ʼ������TIM1 OC2
	TIM_OC3Init(TIM1, &TIM_OCInitStructure); // ��ʼ������TIM1 OC3
	TIM_OC4Init(TIM1, &TIM_OCInitStructure); // ��ʼ������TIM1 OC4
	TIM_OC1Init(TIM3, &TIM_OCInitStructure); // ��ʼ������TIM3 OC1
	TIM_OC2Init(TIM3, &TIM_OCInitStructure); // ��ʼ������TIM3 OC2
	TIM_OC3Init(TIM3, &TIM_OCInitStructure); // ��ʼ������TIM3 OC3
	TIM_OC4Init(TIM3, &TIM_OCInitStructure); // ��ʼ������TIM3 OC4
	
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); // ʹ��TIM1 OC1Ԥװ�ؼĴ���
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable); // ʹ��TIM1 OC2Ԥװ�ؼĴ���
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable); // ʹ��TIM1 OC3Ԥװ�ؼĴ���
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable); // ʹ��TIM1 OC4Ԥװ�ؼĴ���
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable); // ʹ��TIM3 OC1Ԥװ�ؼĴ���
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable); // ʹ��TIM3 OC2Ԥװ�ؼĴ���
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable); // ʹ��TIM3 OC3Ԥװ�ؼĴ���
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable); // ʹ��TIM3 OC4Ԥװ�ؼĴ���
    
	TIM_CtrlPWMOutputs(TIM1,ENABLE); // TIM1��Ҫ��
	TIM_Cmd(TIM1, ENABLE); // ʹ��TIM1
	TIM_Cmd(TIM3, ENABLE); // ʹ��TIM3	
}

void Set_Motor1_RPM(int RPM){
	if(RPM > 720)
		RPM = 720;
	if(RPM < -720)
		RPM = -720;
	if(RPM == 0){
		TIM_SetCompare1(TIM3, 1000-RPM);
		TIM_SetCompare2(TIM3, 1000);
	}
	else if(RPM > 0){
		RPM = RPM*0.8+280;
		TIM_SetCompare1(TIM3, 1000-RPM);
		TIM_SetCompare2(TIM3, 1000);
	}
	else{
		RPM = RPM*0.8-280;
		TIM_SetCompare1(TIM3, 1000);
		TIM_SetCompare2(TIM3, 1000+RPM);
	}
}
void Set_Motor2_RPM(int RPM){
	if(RPM > 720)
		RPM = 720;
	if(RPM < -720)
		RPM = -720;
	if(RPM == 0){
		TIM_SetCompare3(TIM3, 1000-RPM);
		TIM_SetCompare4(TIM3, 1000);
	}
	else if(RPM > 0){
		RPM = RPM*0.8+280;
		TIM_SetCompare3(TIM3, 1000-RPM);
		TIM_SetCompare4(TIM3, 1000);
	}
	else{
		RPM = RPM*0.8-280;
		TIM_SetCompare3(TIM3, 1000);
		TIM_SetCompare4(TIM3, 1000+RPM);
	}
}
void Set_Motor3_RPM(int RPM){
	if(RPM > 720)
		RPM = 720;
	if(RPM < -720)
		RPM = -720;
	if(RPM == 0){
		TIM_SetCompare1(TIM1, 1000-RPM);
		TIM_SetCompare2(TIM1, 1000);
	}
	else if(RPM > 0){
		RPM = RPM*0.8+280;
		TIM_SetCompare1(TIM1, 1000-RPM);
		TIM_SetCompare2(TIM1, 1000);
	}
	else{
		RPM = RPM*0.8-280;
		TIM_SetCompare1(TIM1, 1000);
		TIM_SetCompare2(TIM1, 1000+RPM);
	}
}
void Set_Motor4_RPM(int RPM){
	if(RPM > 720)
		RPM = 720;
	if(RPM < -720)
		RPM = -720;
	if(RPM == 0){
		TIM_SetCompare3(TIM1, 1000-RPM);
		TIM_SetCompare4(TIM1, 1000);
	}
	else if(RPM > 0){
		RPM = RPM*0.8+280;
		TIM_SetCompare3(TIM1, 1000-RPM);
		TIM_SetCompare4(TIM1, 1000);
	}
	else{
		RPM = RPM*0.8-280;
		TIM_SetCompare3(TIM1, 1000);
		TIM_SetCompare4(TIM1, 1000+RPM);
	}
}




