#include "Bsp.h"
#include "math.h"
#include "Motor.h"
#include "CH452.h"
#include "timer.h"
#include "sensor.h"
extern u32 duty;
extern u16 freq;
/********************************************* ����ʼ�� *********************************************/
/******/
void BSP_Init(){
	// ��ʼ��ʱ��  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2  | RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
						   RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD |
						   RCC_APB2Periph_AFIO  | RCC_APB2Periph_TIM1, ENABLE); //APB2����ʱ��ʹ�� 
	Motor_Init();
	Digital_Input_Init();
	Sensor_Init();
	CH452_Init();
	RC_Init();
	Steering_Init();	
}

/************************************* �����ʼ��(test)*************************************/
/******/
void Steering_Init(){
 GPIO_InitTypeDef GPIO_InitStructure;
 TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
 TIM_OCInitTypeDef TIM_OCInitStructure;
 
 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA,&GPIO_InitStructure);
 
 TIM_InternalClockConfig(TIM2);
 
 TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
 TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
 TIM_TimeBaseStructure.TIM_Period = 7199;
 TIM_TimeBaseStructure.TIM_Prescaler = 199;
 TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
 TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);
 
 TIM_OCStructInit(&TIM_OCInitStructure);
 TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; // ѡ��PWMģʽ 2
 TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; // �Ƚ����ʹ��
 TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;// ������Ը�
 TIM_OCInitStructure.TIM_Pulse = 0;
 TIM_OC1Init(TIM2, &TIM_OCInitStructure); // ��ʼ������TIM2 OC1
 TIM_OC2Init(TIM2, &TIM_OCInitStructure); // ��ʼ������TIM2 OC2
 TIM_OC3Init(TIM2, &TIM_OCInitStructure); // ��ʼ������TIM2 OC3
 
 TIM_Cmd(TIM2,ENABLE);
 
}
/********************************************* ---------- *********************************************/
/***************************************** �����������ʼ�� ****************************************/
/******/
void Digital_Input_Init(){	
	/*********************************************
	***2x12�����룬��Reset�������£�����Ϊ***	**
	** PA12   5V							    **
	** PA15   5V								**
	** PB3    5V								**
	** PB4    5V								**
	** PB5    �գ���ֹ��С�Ľ�5V��3.3V��·��	**
	** PB8    3.3V								**
	** PB9    3.3V								**
	** PC13   3.3V								**
	** PC14   �գ���ֹ��С�Ľ�3.3V��GND��·��	**
	** PC15   GND								**
	** PB11   GND								**
	** PB10   GND								**
	**********************************************/
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);  
	GPIO_InitTypeDef GPIO_Input;
	// PA12
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_12;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Input);
	// PA15
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_15;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Input);
	// PB3
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_3;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Input);
	// PB4
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_4;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Input);
	// PB5
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_5;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Input);
	// PB8
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_8;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Input);
	// PB9
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_9;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Input);
	// PC13
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_13;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_Input);
	// PC14
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_14;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_Input);
	// PC15
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_15;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_Input);
	// PB11
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_11;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Input);
	// PB10
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_10;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Input);
	/****
	GPIO_ReadInputDataBit(GPIOx, GPIO_Pin);
	���������ȡio�������ź�ֵ0��1
	ʵ������ȡPA12���������ϵ��֣��ź�ֵ
	      a=GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12);
	****/
	
}

/************************************* ---------- *************************************/
/************************************* ��ʱ���� *************************************/
/******/
void delay_us(u32 uS){ //uS΢�뼶��ʱ���򣨲ο�ֵ������ʱ����72MHzʱ���ֵ233015��	
	SysTick->LOAD=AHB_INPUT*uS;      //��װ������ֵ������Ƶ��72MHz��72��Ϊ1΢�룩
	SysTick->VAL=0x00;        //��ն�ʱ���ļ�����
	SysTick->CTRL=0x00000005;//ʱ��ԴHCLK���򿪶�ʱ��
	while(!(SysTick->CTRL&0x00010000)); //�ȴ�������0
	SysTick->VAL=0x00;        //��ն�ʱ���ļ�����
	SysTick->CTRL=0x00000004;//�رն�ʱ��
}

void delay_ms(u16 ms){ //mS���뼶��ʱ���򣨲ο�ֵ������ʱ�������ֵ65535=2^16��	 		  	  
	while( ms-- != 0){
		delay_us(1000);	//����1000΢�����ʱ
	}
}
 
void delay_s(u16 s){ //S�뼶��ʱ���򣨲ο�ֵ������ʱ�������ֵ65535��	 		  	  
	while( s-- != 0){
		delay_ms(1000);	//����1000�������ʱ
	}
}

/*************************************   �� ע   *************************************/
/*
	GPIO_Mode_AIN ģ������
	GPIO_Mode_IN_FLOATING ��������
	GPIO_Mode_IPD ��������
	GPIO_Mode_IPU ��������
	GPIO_Mode_Out_OD ��©���
	GPIO_Mode_Out_PP �������
	GPIO_Mode_AF_OD ���ÿ�©���
	GPIO_Mode_AF_PP �����������
*/
/************************************* ---------- *************************************/
