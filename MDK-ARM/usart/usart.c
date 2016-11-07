#include "..\all.h"


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance==USART1)//����Ǵ���1
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
					if(USART_RX_STA_1>(USART_REC_LEN_1-1))flag=0;//�������ݴ���,���¿�ʼ����	
				}
		    
				
	}
	 else if(huart->Instance==USART2)
	{
	if((USART_RX_STA_2&0x8000)==0)//����δ���
		{
			if(USART_RX_STA_2&0x4000)//���յ���0x0d
			{
				if(aRxBuffer_2[0]!=0x0a)USART_RX_STA_2=0;//���մ���,���¿�ʼ
				else USART_RX_STA_2|=0x8000;	//��������� 
			}
			else //��û�յ�0X0D
			{	
				if(aRxBuffer_2[0]==0x0d)USART_RX_STA_2|=0x4000;
				else
				{
					Rx_buff_2[USART_RX_STA_2&0X3FFF]=aRxBuffer_2[0] ;
					USART_RX_STA_2++;
					if(USART_RX_STA_2>(USART_REC_LEN_2-1))USART_RX_STA_2=0;//�������ݴ���,���¿�ʼ����	  
				}		 
			}
		}
	}
	else if(huart->Instance==USART3)
	{
	if((USART_RX_STA_3&0x8000)==0)//����δ���
		{
			if(USART_RX_STA_3&0x4000)//���յ���0x0d
			{
				if(aRxBuffer_3[0]!=0x0a)USART_RX_STA_3=0;//���մ���,���¿�ʼ
				else USART_RX_STA_3|=0x8000;	//��������� 
			}
			else //��û�յ�0X0D
			{	
				if(aRxBuffer_3[0]==0x0d)USART_RX_STA_3|=0x4000;
				else
				{
					Rx_buff_3[USART_RX_STA_3&0X3FFF]=aRxBuffer_3[0] ;
					USART_RX_STA_3++;
					if(USART_RX_STA_3>(USART_REC_LEN_3-1))USART_RX_STA_3=0;//�������ݴ���,���¿�ʼ����	  
				}		 
			}
		}
	}
}

void USART1_IRQHandler(void)                	
{ 
	u32 timeout=0;
#if SYSTEM_SUPPORT_OS	 	//ʹ��OS
	OSIntEnter();    
#endif
	
	HAL_UART_IRQHandler(&huart1);	//����HAL���жϴ����ú���
	
	timeout=0;
    while (HAL_UART_GetState(&huart1) != HAL_UART_STATE_READY)//�ȴ�����
	{
	 timeout++;////��ʱ����
     if(timeout>HAL_MAX_DELAY) break;		
	}
     
	timeout=0;
	while(HAL_UART_Receive_IT(&huart1, (u8 *)aRxBuffer_1, RXBUFFERSIZE) != HAL_OK)//һ�δ������֮�����¿����жϲ�����RxXferCountΪ1
	{
	 timeout++; //��ʱ����
	 if(timeout>HAL_MAX_DELAY) break;	
	}
#if SYSTEM_SUPPORT_OS	 	//ʹ��OS
	OSIntExit();  											 
#endif
} 

void USART2_IRQHandler(void)                	
{ 
	u32 timeout=0;
#if SYSTEM_SUPPORT_OS	 	//ʹ��OS
	OSIntEnter();    
#endif
	
	HAL_UART_IRQHandler(&huart2);	//����HAL���жϴ����ú���
	
	timeout=0;
    while (HAL_UART_GetState(&huart2) != HAL_UART_STATE_READY)//�ȴ�����
	{
	 timeout++;////��ʱ����
     if(timeout>HAL_MAX_DELAY) break;		
	}
     
	timeout=0;
	while(HAL_UART_Receive_IT(&huart2, (u8 *)aRxBuffer_2, RXBUFFERSIZE) != HAL_OK)//һ�δ������֮�����¿����жϲ�����RxXferCountΪ1
	{
	 timeout++; //��ʱ����
	 if(timeout>HAL_MAX_DELAY) break;	
	}
#if SYSTEM_SUPPORT_OS	 	//ʹ��OS
	OSIntExit();  											 
#endif
} 

void USART3_IRQHandler(void)                	
{ 
	u32 timeout=0;
#if SYSTEM_SUPPORT_OS	 	//ʹ��OS
	OSIntEnter();    
#endif
	
	HAL_UART_IRQHandler(&huart3);	//����HAL���жϴ����ú���
	
	timeout=0;
    while (HAL_UART_GetState(&huart3) != HAL_UART_STATE_READY)//�ȴ�����
	{
	 timeout++;////��ʱ����
     if(timeout>HAL_MAX_DELAY) break;		
	}
     
	timeout=0;
	while(HAL_UART_Receive_IT(&huart3, (u8 *)aRxBuffer_3, RXBUFFERSIZE) != HAL_OK)//һ�δ������֮�����¿����жϲ�����RxXferCountΪ1
	{
	 timeout++; //��ʱ����
	 if(timeout>HAL_MAX_DELAY) break;	
	}
#if SYSTEM_SUPPORT_OS	 	//ʹ��OS
	OSIntExit();  											 
#endif
} 	

void Uart_test(void)            //����1
{	
   	  if(packflag==1)            //���ڻ������ݱ�־λ
		{					   
			len=USART_RX_STA_1&0x3fff;//�õ��˴ν��յ������ݳ���
			printf("\r\nthe news is:\r\n");
			HAL_UART_Transmit(&huart1,(uint8_t*)Rx_buff_1,len,1000);	//���ͽ��յ�������
			while(__HAL_UART_GET_FLAG(&huart1,UART_FLAG_TC)!=SET);		//�ȴ����ͽ���
			printf("\r\n\r\n");//���뻻��
			packflag=0;                                              //
			USART_RX_STA_1=0; 
		}else
		{
			times++;
			if(times%200==0)printf("please input char \r\n");  
			delay_ms(10); 
    }
}
