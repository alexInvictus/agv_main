#ifndef _H_DEFINE_
#define _H_DEFINE_
#define USART_REC_LEN_1       200          //�������ֽ�
#define USART_REC_LEN_2       200          //�������ֽ�
#define USART_REC_LEN_3       200          //�������ֽ�
#define RXBUFFERSIZE   1
void Error_Handler(void);
void MX_GPIO_Init(void);                        //gpio�ڳ�ʼ������ 
void MX_TIM13_Init(void);                       //��ʱ��13��ʼ�����ò���PWM��
void MX_TIM14_Init(void);                       //��ʱ��14��ʼ�����ò���PWM��
void SystemClock_Config(void);                  //ʱ�ӵ�����
void MX_USART1_UART_Init(void);                 //����1��ʼ��
void MX_USART2_UART_Init(void);                 //����2��ʼ��
void MX_USART3_UART_Init(void);                 //����3��ʼ��
void Uart_test(void);                           //���ڲ��Գ���
void Eeprom_Read(void);                         //��ȡeeprom����ĳ���
void Send_Id(void);                             //����id�Ÿ��п�ϵͳ
#endif


