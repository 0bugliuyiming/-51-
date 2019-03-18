#include<reg52.h>
#include"as608.h"
#include"uart.h"

//��֤���Ĭ������00000000H��
unsigned char PS_VfyPwd()
{
	unsigned char querenma = 0xFF;		//����Ӧ�����ȷ����
	unsigned char i;

	//����ָ�����

	/*��ͷ 2 bytes*/
	SendByte(0xEF);
	SendByte(0x01);

	/*оƬ��ַ 4 bytes*/
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);

	/*����ʶ 1 byte*/
	SendByte(0x01);

	/*������ 2 bytes*/
	SendByte(0x00);
	SendByte(0x07);

	/*ָ���� 1 byte*/
	SendByte(0x13);

	/*���� 4 bytes*/
	SendByte(0x00);
	SendByte(0x00);
	SendByte(0x00);
	SendByte(0x00);

	/*У��� 2 bytes*/
	SendByte(0x00);
	SendByte(0x1B);

	//����Ӧ�����

	/*ǰ9λΪ��ͷ��оƬ��ַ������ʶ�������ȡ�Ϊ����Ҫ�Ĳ��֣������б���*/
	for(i = 0; i < 9; i++)
	{
		while(!RI);
		RI = 0;
	}

	/*ȷ���� 1 byte*/
	querenma = ReceiveByte();

	/*У��� 2 bytes������Ҫ�������б���*/
	while(!RI);
	RI = 0;
	while(!RI);
	RI = 0;

	return querenma;	//���ذ�Ϊȷ���� 	
}

//¼��ָ��ͼ��
unsigned char PS_GetImage()		
{
	unsigned char querenma = 0xFF;		//����Ӧ�����ȷ����
	unsigned char i;

	//����ָ�����

	/*��ͷ 2 bytes*/
	SendByte(0xEF);
	SendByte(0x01);

	/*оƬ��ַ 4 bytes*/
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);

	/*����ʶ 1 byte*/
	SendByte(0x01);

	/*������ 2 bytes*/
	SendByte(0x00);
	SendByte(0x03);

	/*ָ���� 1 byte*/
	SendByte(0x01);

	/*У��� 2 bytes*/
	SendByte(0x00);
	SendByte(0x05);

	//����Ӧ�����

	/*ǰ9λΪ��ͷ��оƬ��ַ������ʶ�������ȡ�Ϊ����Ҫ�Ĳ��֣������б���*/
	for(i = 0; i < 9; i++)
	{
		while(!RI);
		RI = 0;
	}

	/*ȷ���� 1 byte*/
	querenma = ReceiveByte();

	/*У��� 2 bytes������Ҫ�������б���*/
	while(!RI);
	RI = 0;
	while(!RI);
	RI = 0;

	return querenma;	//���ذ�Ϊȷ���� 
}	

//��������
unsigned char PS_GenChar(unsigned char BufferID)
{
	unsigned char querenma = 0xFF;		//����Ӧ�����ȷ����
	unsigned int summaf;		//16λУ���
	unsigned char sum[2];			//2 * 8λУ���
	unsigned char i;

	//����ָ�����

	/*��ͷ 2 bytes*/
	SendByte(0xEF);
	SendByte(0x01);

	/*оƬ��ַ 4 bytes*/
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);

	/*����ʶ 1 byte*/
	SendByte(0x01);

	/*������ 2 bytes*/
	SendByte(0x00);
	SendByte(0x04);

	/*ָ���� 1 byte*/
	SendByte(0x02);

	/*�������� 1 byte*/
	SendByte(BufferID);

	/*У��� 2 bytes*/
	summaf = 0x07 + BufferID;		//����16λУ���
	sum[0] = summaf;
	sum[1] = summaf >> 8;	
	SendByte(sum[1]);		//�ȷ��͸�8λ
	SendByte(sum[0]);		//���͵�8λ

	//����Ӧ���

	/*ǰ9λΪ��ͷ��оƬ��ַ������ʶ�������ȡ�Ϊ����Ҫ�Ĳ��֣������б���*/
	for(i = 0; i < 9; i++)
	{
		while(!RI);
		RI = 0;
	}

	/*ȷ���� 1 byte*/
	querenma = ReceiveByte();

	/*У��� 2 bytes������Ҫ�������б���*/
	while(!RI);
	RI = 0;
	while(!RI);
	RI = 0;

	return querenma;	//���ذ�Ϊȷ���� 
}

//�ϲ�����������ģ�壩
unsigned char PS_RegModel()
{
	unsigned char querenma = 0xFF;		//����Ӧ�����ȷ����
	unsigned char i;

	//����ָ���

	/*��ͷ 2 bytes*/
	SendByte(0xEF);
	SendByte(0x01);

	/*оƬ��ַ 4 bytes*/
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);

	/*����ʶ 1 byte*/
	SendByte(0x01);

	/*������ 2 bytes*/
	SendByte(0x00);
	SendByte(0x03);
	
	/*ָ���� 1 byte*/
	SendByte(0x05);

	/*У��� 2 bytes*/
	SendByte(0x00);
	SendByte(0x09);

	//����Ӧ���

	/*ǰ9λΪ��ͷ��оƬ��ַ������ʶ�������ȡ�Ϊ����Ҫ�Ĳ��֣������б���*/
	for(i = 0; i < 9; i++)
	{
		while(!RI);
		RI = 0;
	}

	/*ȷ���� 1 byte*/
	querenma = ReceiveByte();

	/*У��� 2 bytes������Ҫ�������б���*/
	while(!RI);
	RI = 0;
	while(!RI);
	RI = 0;

	return querenma;	//���ذ�Ϊȷ���� 
}

//����ģ��
unsigned char PS_StoreChar(unsigned char BufferID, unsigned int PageID)
{
	unsigned char querenma = 0xFF;		//����Ӧ�����ȷ����
	unsigned char page[2];		//2 * 8λλ�ú�
	unsigned int summaf;		//16λУ���
	unsigned char sum[2];			//2 * 8λУ���
	unsigned char i;
	
	//����ָ�����

	/*��ͷ 2 bytes*/
	SendByte(0xEF);
	SendByte(0x01);

	/*оƬ��ַ 4 bytes*/
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);
	SendByte(0xFF);

	/*����ʶ 1 byte*/
	SendByte(0x01);

	/*������ 2 bytes*/
	SendByte(0x00);
	SendByte(0x06);

	/*ָ���� 1 byte*/
	SendByte(0x06);

	/*�������� 1 byte*/
	SendByte(BufferID);	

	/*λ�ú� 2 bytes*/
	page[0] = PageID;
	page[1] = PageID >> 8;
	SendByte(page[1]);
	SendByte(page[0]);

	/*У��� 2 bytes*/
	summaf = (0x01 + 0x06 + 0x06 + BufferID + PageID);
	sum[0] = summaf;
	sum[1] = summaf >> 8;
	SendByte(sum[1]);
	SendByte(sum[0]); 

	//����Ӧ���

	/*ǰ9λΪ��ͷ��оƬ��ַ������ʶ�������ȡ�Ϊ����Ҫ�Ĳ��֣������б���*/
	for(i = 0; i < 9; i++)
	{
		while(!RI);
		RI = 0;
	}

	/*ȷ���� 1 byte*/
	querenma = ReceiveByte();

	/*У��� 2 bytes������Ҫ�������б���*/
	while(!RI);
	RI = 0;
	while(!RI);
	RI = 0;

	return querenma;	//���ذ�Ϊȷ����
}