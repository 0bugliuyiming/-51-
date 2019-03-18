#include<reg52.h>
#include"as608.h"
#include"uart.h"

//验证口令（默认密码00000000H）
unsigned char PS_VfyPwd()
{
	unsigned char querenma = 0xFF;		//接收应答包的确认码
	unsigned char i;

	//发送指令包：

	/*包头 2 bytes*/
	SendByte(0xEF);
	SendByte(0x01);

	/*芯片地址 4 bytes*/
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);

	/*包标识 1 byte*/
	SendByte(0x01);

	/*包长度 2 bytes*/
	SendByte(0x00);
	SendByte(0x07);

	/*指令码 1 byte*/
	SendByte(0x13);

	/*口令 4 bytes*/
	SendByte(0x00);
	SendByte(0x00);
	SendByte(0x00);
	SendByte(0x00);

	/*校验和 2 bytes*/
	SendByte(0x00);
	SendByte(0x1B);

	//接收应答包：

	/*前9位为包头，芯片地址，包标识，包长度。为不需要的部分，不进行保存*/
	for(i = 0; i < 9; i++)
	{
		while(!RI);
		RI = 0;
	}

	/*确认码 1 byte*/
	querenma = ReceiveByte();

	/*校验和 2 bytes，不需要，不进行保存*/
	while(!RI);
	RI = 0;
	while(!RI);
	RI = 0;

	return querenma;	//返回包为确认码 	
}

//录入指纹图像
unsigned char PS_GetImage()		
{
	unsigned char querenma = 0xFF;		//接收应答包的确认码
	unsigned char i;

	//发送指令包：

	/*包头 2 bytes*/
	SendByte(0xEF);
	SendByte(0x01);

	/*芯片地址 4 bytes*/
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);

	/*包标识 1 byte*/
	SendByte(0x01);

	/*包长度 2 bytes*/
	SendByte(0x00);
	SendByte(0x03);

	/*指令码 1 byte*/
	SendByte(0x01);

	/*校验和 2 bytes*/
	SendByte(0x00);
	SendByte(0x05);

	//接收应答包：

	/*前9位为包头，芯片地址，包标识，包长度。为不需要的部分，不进行保存*/
	for(i = 0; i < 9; i++)
	{
		while(!RI);
		RI = 0;
	}

	/*确认码 1 byte*/
	querenma = ReceiveByte();

	/*校验和 2 bytes，不需要，不进行保存*/
	while(!RI);
	RI = 0;
	while(!RI);
	RI = 0;

	return querenma;	//返回包为确认码 
}	

//生成特征
unsigned char PS_GenChar(unsigned char BufferID)
{
	unsigned char querenma = 0xFF;		//接收应答包的确认码
	unsigned int summaf;		//16位校验和
	unsigned char sum[2];			//2 * 8位校验和
	unsigned char i;

	//发送指令包：

	/*包头 2 bytes*/
	SendByte(0xEF);
	SendByte(0x01);

	/*芯片地址 4 bytes*/
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);

	/*包标识 1 byte*/
	SendByte(0x01);

	/*包长度 2 bytes*/
	SendByte(0x00);
	SendByte(0x04);

	/*指令码 1 byte*/
	SendByte(0x02);

	/*缓冲区号 1 byte*/
	SendByte(BufferID);

	/*校验和 2 bytes*/
	summaf = 0x07 + BufferID;		//计算16位校验和
	sum[0] = summaf;
	sum[1] = summaf >> 8;	
	SendByte(sum[1]);		//先发送高8位
	SendByte(sum[0]);		//后发送低8位

	//接收应答包

	/*前9位为包头，芯片地址，包标识，包长度。为不需要的部分，不进行保存*/
	for(i = 0; i < 9; i++)
	{
		while(!RI);
		RI = 0;
	}

	/*确认码 1 byte*/
	querenma = ReceiveByte();

	/*校验和 2 bytes，不需要，不进行保存*/
	while(!RI);
	RI = 0;
	while(!RI);
	RI = 0;

	return querenma;	//返回包为确认码 
}

//合并特征（生成模板）
unsigned char PS_RegModel()
{
	unsigned char querenma = 0xFF;		//接收应答包的确认码
	unsigned char i;

	//发送指令包

	/*包头 2 bytes*/
	SendByte(0xEF);
	SendByte(0x01);

	/*芯片地址 4 bytes*/
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);

	/*包标识 1 byte*/
	SendByte(0x01);

	/*包长度 2 bytes*/
	SendByte(0x00);
	SendByte(0x03);
	
	/*指令码 1 byte*/
	SendByte(0x05);

	/*校验和 2 bytes*/
	SendByte(0x00);
	SendByte(0x09);

	//接收应答包

	/*前9位为包头，芯片地址，包标识，包长度。为不需要的部分，不进行保存*/
	for(i = 0; i < 9; i++)
	{
		while(!RI);
		RI = 0;
	}

	/*确认码 1 byte*/
	querenma = ReceiveByte();

	/*校验和 2 bytes，不需要，不进行保存*/
	while(!RI);
	RI = 0;
	while(!RI);
	RI = 0;

	return querenma;	//返回包为确认码 
}

//储存模板
unsigned char PS_StoreChar(unsigned char BufferID, unsigned int PageID)
{
	unsigned char querenma = 0xFF;		//接收应答包的确认码
	unsigned char page[2];		//2 * 8位位置号
	unsigned int summaf;		//16位校验和
	unsigned char sum[2];			//2 * 8位校验和
	unsigned char i;
	
	//发送指令包：

	/*包头 2 bytes*/
	SendByte(0xEF);
	SendByte(0x01);

	/*芯片地址 4 bytes*/
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);

	/*包标识 1 byte*/
	SendByte(0x01);

	/*包长度 2 bytes*/
	SendByte(0x00);
	SendByte(0x06);

	/*指令码 1 byte*/
	SendByte(0x06);

	/*缓冲区号 1 byte*/
	SendByte(BufferID);	

	/*位置号 2 bytes*/
	page[0] = PageID;
	page[1] = PageID >> 8;
	SendByte(page[1]);
	SendByte(page[0]);

	/*校验和 2 bytes*/
	summaf = (0x01 + 0x06 + 0x06 + BufferID + PageID);
	sum[0] = summaf;
	sum[1] = summaf >> 8;
	SendByte(sum[1]);
	SendByte(sum[0]); 

	//接收应答包

	/*前9位为包头，芯片地址，包标识，包长度。为不需要的部分，不进行保存*/
	for(i = 0; i < 9; i++)
	{
		while(!RI);
		RI = 0;
	}

	/*确认码 1 byte*/
	querenma = ReceiveByte();

	/*校验和 2 bytes，不需要，不进行保存*/
	while(!RI);
	RI = 0;
	while(!RI);
	RI = 0;

	return querenma;	//返回包为确认码
}