#include<reg52.h>
#include"uart.h"

//���ڳ�ʼ������
void ConfigUART()
{
    SCON  = 0x50;  //���ô���Ϊģʽ1
	PCON = 0x80;   //�����ʷ���
    TMOD &= 0x0F;  //����T1�Ŀ���λ
    TMOD |= 0x20;  //����T1Ϊģʽ2
    TH1 = 0xFA;    //������9600
    TL1 = TH1;     //��ֵ��������ֵ
    ET1 = 0;       //��ֹT1�ж�
    ES  = 1;       //ʹ�ܴ����ж�
    TR1 = 1;       //����T1
}

//����һ���ֽڵ����ݣ��β�d��Ϊ���������ݡ�
void SendByte(unsigned char d)                  
{
        SBUF = d; //������д�뵽���ڻ���
        while(!TI); //�ȴ��������
        TI = 0;
}

//����һ���ֽڵ����ݣ�����ֵΪunsigned char����
unsigned char ReceiveByte()
{
	unsigned char dat;
	while(!RI);		//�������
	RI = 0;
	dat = SBUF;		//���մ��ڷ���������
	return dat;
}      