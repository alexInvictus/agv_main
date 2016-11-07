#include "ks103.h"
/*ģ��iicͨ��*/
u8 KS103_ReadOneByte(u8 address, u8 reg)
{
  u8 temp=0;
	
	IIC_Start();
	IIC_Send_Byte(address);  //���͵͵�ַ
	IIC_Wait_Ack();
	IIC_Send_Byte(reg);      //���͸ߵ�ַ
	IIC_Wait_Ack();
	IIC_Start();
	IIC_Send_Byte(address+1);  //�������ģʽ
	IIC_Wait_Ack();
	
	delay_us(50);
	temp=IIC_Read_Byte(0);    
	IIC_Stop();              //����һ��ֹͣ����
	return temp;
}

void KS103_WriteOneByte(u8 address,u8 reg,u8 command)
{
  IIC_Start();
	IIC_Send_Byte(address);
	IIC_Wait_Ack();
	IIC_Send_Byte(reg);      //���͸ߵ�ַ
	IIC_Wait_Ack();
	IIC_Send_Byte(command);
	IIC_Wait_Ack();
	IIC_Stop();              
}

u16 Wave_test(void)
{
	  static u16 range=0;
		KS103_WriteOneByte(0xe8,0x02,0xb0);
		delay_ms(80);
		range=KS103_ReadOneByte(0xe8,0x02);
		range<<=8; 
		range+=KS103_ReadOneByte(0xe8,0x03);
		return range*2;
}

