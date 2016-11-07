#ifndef _H_VARDEF_
#define _H_VARDEF_
#define uchar unsigned char
#define uint  unsigned int
#ifdef _C_MAIN_
u16 USART_RX_STA_1=0;       //接收标志位
u8 Rx_buff_1[USART_REC_LEN_1];
u8 aRxBuffer_1[RXBUFFERSIZE];//HAL库使用的串口1接收缓冲

u16 USART_RX_STA_2=0;       //接收标志位
u8 Rx_buff_2[USART_REC_LEN_2];
u8 aRxBuffer_2[RXBUFFERSIZE];//HAL库使用的串口2接收缓冲

u16 USART_RX_STA_3=0;       //接收标志位
u8 Rx_buff_3[USART_REC_LEN_3];
u8 aRxBuffer_3[RXBUFFERSIZE];//HAL库使用的串口2接收缓冲
/*句柄的定义*/
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
TIM_HandleTypeDef htim13;
TIM_HandleTypeDef htim14;
/*全局变量的声明*/
u8 len;                       //反馈数组的长度
u16 times=0;                  //统计时间
u16 flag=0;                   //收到包头标志位
u16 packflag;                 //收到包尾标志位。
enum
{
 Wait_State,                      //等待中控命令
 Read_State,                      //读取eeprom值，并且发送ID给中控
 Push_State,                      //在暂定点，主动发送信息给中控
 Analyse_State,                   //分析道路的状态
 Run_State                        //分析完道路开始循迹的状态    
}Command_State=Read_State;

enum
{
 Left_90,                         //检测到左转RFID
 Right_90,                        //检测到右转RFID
 Head,                            //直走的RFID
}Turn_State=Head;
#else
extern u16 USART_RX_STA_1;       //接收标志位
extern u8 Rx_buff_1[USART_REC_LEN_1];
extern u8 aRxBuffer_1[RXBUFFERSIZE];//HAL库USART接收Buffer

extern u16 USART_RX_STA_2;       //接收标志位
extern u8 Rx_buff_2[USART_REC_LEN_2];
extern u8 aRxBuffer_2[RXBUFFERSIZE];//HAL库USART接收Buffer

extern u16 USART_RX_STA_3;       //接收标志位
extern u8 Rx_buff_3[USART_REC_LEN_3];
extern u8 aRxBuffer_3[RXBUFFERSIZE];//HAL库USART接收Buffer

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern TIM_HandleTypeDef htim13;
extern TIM_HandleTypeDef htim14;

extern u8 len;                       //反馈数组的长度
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

