#ifndef _H_VARDEF_
#define _H_VARDEF_
#define uchar unsigned char
#define uint  unsigned int
#ifdef _C_MAIN_
u16 USART_RX_STA_1=0;       //���ձ�־λ
u8 Rx_buff_1[USART_REC_LEN_1];
u8 aRxBuffer_1[RXBUFFERSIZE];//HAL��ʹ�õĴ���1���ջ���

u16 USART_RX_STA_2=0;       //���ձ�־λ
u8 Rx_buff_2[USART_REC_LEN_2];
u8 aRxBuffer_2[RXBUFFERSIZE];//HAL��ʹ�õĴ���2���ջ���

u16 USART_RX_STA_3=0;       //���ձ�־λ
u8 Rx_buff_3[USART_REC_LEN_3];
u8 aRxBuffer_3[RXBUFFERSIZE];//HAL��ʹ�õĴ���2���ջ���
/*����Ķ���*/
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
TIM_HandleTypeDef htim13;
TIM_HandleTypeDef htim14;
/*ȫ�ֱ���������*/
u8 len;                       //��������ĳ���
u16 times=0;                  //ͳ��ʱ��
u16 flag=0;                   //�յ���ͷ��־λ
u16 packflag;                 //�յ���β��־λ��
enum
{
 Wait_State,                      //�ȴ��п�����
 Read_State,                      //��ȡeepromֵ�����ҷ���ID���п�
 Push_State,                      //���ݶ��㣬����������Ϣ���п�
 Analyse_State,                   //������·��״̬
 Run_State                        //�������·��ʼѭ����״̬    
}Command_State=Read_State;

enum
{
 Left_90,                         //��⵽��תRFID
 Right_90,                        //��⵽��תRFID
 Head,                            //ֱ�ߵ�RFID
}Turn_State=Head;
#else
extern u16 USART_RX_STA_1;       //���ձ�־λ
extern u8 Rx_buff_1[USART_REC_LEN_1];
extern u8 aRxBuffer_1[RXBUFFERSIZE];//HAL��USART����Buffer

extern u16 USART_RX_STA_2;       //���ձ�־λ
extern u8 Rx_buff_2[USART_REC_LEN_2];
extern u8 aRxBuffer_2[RXBUFFERSIZE];//HAL��USART����Buffer

extern u16 USART_RX_STA_3;       //���ձ�־λ
extern u8 Rx_buff_3[USART_REC_LEN_3];
extern u8 aRxBuffer_3[RXBUFFERSIZE];//HAL��USART����Buffer

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern TIM_HandleTypeDef htim13;
extern TIM_HandleTypeDef htim14;

extern u8 len;                       //��������ĳ���
extern u16 times;
extern u16 flag;
extern u16 packflag;
extern enum
{
 Wait_State,
 Read_State,
 Push_State,
 Analyse_State
}Command_State;

extern enum
{
 Left_90,
 Right_90,
 Head,
}Turn_State;

#endif
#endif

