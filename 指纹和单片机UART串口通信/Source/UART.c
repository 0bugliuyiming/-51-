#include<reg52.h>
#include"uart.h"

//串口初始化程序
void ConfigUART()
{
    SCON  = 0x50;  //配置串口为模式1
	PCON = 0x80;   //波特率翻倍
    TMOD &= 0x0F;  //清零T1的控制位
    TMOD |= 0x20;  //配置T1为模式2
    TH1 = 0xFA;    //波特率9600
    TL1 = TH1;     //初值等于重载值
    ET1 = 0;       //禁止T1中断
    ES  = 1;       //使能串口中断
    TR1 = 1;       //启动T1
}

//发送一个字节的数据，形参d即为待发送数据。
void SendByte(unsigned char d)                  
{
        SBUF = d; //将数据写入到串口缓冲
        while(!TI); //等待发送完毕
        TI = 0;
}

//接收一个字节的数据，返回值为unsigned char类型
unsigned char ReceiveByte()
{
	unsigned char dat;
	while(!RI);		//接收完毕
	RI = 0;
	dat = SBUF;		//接收串口发来的数据
	return dat;
}      