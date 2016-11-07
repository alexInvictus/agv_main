#ifndef _H_DEFINE_
#define _H_DEFINE_
#define USART_REC_LEN_1       200          //最大接收字节
#define USART_REC_LEN_2       200          //最大接收字节
#define USART_REC_LEN_3       200          //最大接收字节
#define RXBUFFERSIZE   1
void Error_Handler(void);
void MX_GPIO_Init(void);                        //gpio口初始化配置 
void MX_TIM13_Init(void);                       //定时器13初始化配置产生PWM波
void MX_TIM14_Init(void);                       //定时器14初始化配置产生PWM波
void SystemClock_Config(void);                  //时钟的配置
void MX_USART1_UART_Init(void);                 //串口1初始化
void MX_USART2_UART_Init(void);                 //串口2初始化
void MX_USART3_UART_Init(void);                 //串口3初始化
void Uart_test(void);                           //串口测试程序
void Eeprom_Read(void);                         //读取eeprom里面的车号
void Send_Id(void);                             //发送id号给中控系统
#endif


