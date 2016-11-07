#include "..\all.h"


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance==USART1)//如果是串口1
	{
				if(aRxBuffer_1[0]==0x2a)
				{
					flag=1;
				  packflag=0;
				}
				if(aRxBuffer_1[0]==0x23)
				{
					Rx_buff_1[USART_RX_STA_1&0X3FFF]=aRxBuffer_1[0] ;
				  flag=0;
				  packflag=1;
				}
				if(flag==1)
				{
				  Rx_buff_1[USART_RX_STA_1&0X3FFF]=aRxBuffer_1[0] ;
					USART_RX_STA_1++;
					if(USART_RX_STA_1>(USART_REC_LEN_1-1))flag=0;//接收数据错误,重新开始接收	
				}
		    
				
	}
	 else if(huart->Instance==USART2)
	{
	if((USART_RX_STA_2&0x8000)==0)//接收未完成
		{
			if(USART_RX_STA_2&0x4000)//接收到了0x0d
			{
				if(aRxBuffer_2[0]!=0x0a)USART_RX_STA_2=0;//接收错误,重新开始
				else USART_RX_STA_2|=0x8000;	//接收完成了 
			}
			else //还没收到0X0D
			{	
				if(aRxBuffer_2[0]==0x0d)USART_RX_STA_2|=0x4000;
				else
				{
					Rx_buff_2[USART_RX_STA_2&0X3FFF]=aRxBuffer_2[0] ;
					USART_RX_STA_2++;
					if(USART_RX_STA_2>(USART_REC_LEN_2-1))USART_RX_STA_2=0;//接收数据错误,重新开始接收	  
				}		 
			}
		}
	}
	else if(huart->Instance==USART3)
	{
	if((USART_RX_STA_3&0x8000)==0)//接收未完成
		{
			if(USART_RX_STA_3&0x4000)//接收到了0x0d
			{
				if(aRxBuffer_3[0]!=0x0a)USART_RX_STA_3=0;//接收错误,重新开始
				else USART_RX_STA_3|=0x8000;	//接收完成了 
			}
			else //还没收到0X0D
			{	
				if(aRxBuffer_3[0]==0x0d)USART_RX_STA_3|=0x4000;
				else
				{
					Rx_buff_3[USART_RX_STA_3&0X3FFF]=aRxBuffer_3[0] ;
					USART_RX_STA_3++;
					if(USART_RX_STA_3>(USART_REC_LEN_3-1))USART_RX_STA_3=0;//接收数据错误,重新开始接收	  
				}		 
			}
		}
	}
}

void USART1_IRQHandler(void)                	
{ 
	u32 timeout=0;
#if SYSTEM_SUPPORT_OS	 	//使用OS
	OSIntEnter();    
#endif
	
	HAL_UART_IRQHandler(&huart1);	//调用HAL库中断处理公用函数
	
	timeout=0;
    while (HAL_UART_GetState(&huart1) != HAL_UART_STATE_READY)//等待就绪
	{
	 timeout++;////超时处理
     if(timeout>HAL_MAX_DELAY) break;		
	}
     
	timeout=0;
	while(HAL_UART_Receive_IT(&huart1, (u8 *)aRxBuffer_1, RXBUFFERSIZE) != HAL_OK)//一次处理完成之后，重新开启中断并设置RxXferCount为1
	{
	 timeout++; //超时处理
	 if(timeout>HAL_MAX_DELAY) break;	
	}
#if SYSTEM_SUPPORT_OS	 	//使用OS
	OSIntExit();  											 
#endif
} 

void USART2_IRQHandler(void)                	
{ 
	u32 timeout=0;
#if SYSTEM_SUPPORT_OS	 	//使用OS
	OSIntEnter();    
#endif
	
	HAL_UART_IRQHandler(&huart2);	//调用HAL库中断处理公用函数
	
	timeout=0;
    while (HAL_UART_GetState(&huart2) != HAL_UART_STATE_READY)//等待就绪
	{
	 timeout++;////超时处理
     if(timeout>HAL_MAX_DELAY) break;		
	}
     
	timeout=0;
	while(HAL_UART_Receive_IT(&huart2, (u8 *)aRxBuffer_2, RXBUFFERSIZE) != HAL_OK)//一次处理完成之后，重新开启中断并设置RxXferCount为1
	{
	 timeout++; //超时处理
	 if(timeout>HAL_MAX_DELAY) break;	
	}
#if SYSTEM_SUPPORT_OS	 	//使用OS
	OSIntExit();  											 
#endif
} 

void USART3_IRQHandler(void)                	
{ 
	u32 timeout=0;
#if SYSTEM_SUPPORT_OS	 	//使用OS
	OSIntEnter();    
#endif
	
	HAL_UART_IRQHandler(&huart3);	//调用HAL库中断处理公用函数
	
	timeout=0;
    while (HAL_UART_GetState(&huart3) != HAL_UART_STATE_READY)//等待就绪
	{
	 timeout++;////超时处理
     if(timeout>HAL_MAX_DELAY) break;		
	}
     
	timeout=0;
	while(HAL_UART_Receive_IT(&huart3, (u8 *)aRxBuffer_3, RXBUFFERSIZE) != HAL_OK)//一次处理完成之后，重新开启中断并设置RxXferCount为1
	{
	 timeout++; //超时处理
	 if(timeout>HAL_MAX_DELAY) break;	
	}
#if SYSTEM_SUPPORT_OS	 	//使用OS
	OSIntExit();  											 
#endif
} 	

void Uart_test(void)            //串口1
{	
   	  if(packflag==1)            //串口缓存数据标志位
		{					   
			len=USART_RX_STA_1&0x3fff;//得到此次接收到的数据长度
			printf("\r\nthe news is:\r\n");
			HAL_UART_Transmit(&huart1,(uint8_t*)Rx_buff_1,len,1000);	//发送接收到的数据
			while(__HAL_UART_GET_FLAG(&huart1,UART_FLAG_TC)!=SET);		//等待发送结束
			printf("\r\n\r\n");//插入换行
			packflag=0;                                              //
			USART_RX_STA_1=0; 
		}else
		{
			times++;
			if(times%200==0)printf("please input char \r\n");  
			delay_ms(10); 
    }
}
