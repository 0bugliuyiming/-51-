#include<reg52.h>
#include<intrins.h>
#include"uart.h"
#include"as608.h"
#include"lcd1602.h"
#include"DELAY.h"

unsigned char querenma;		//����ȷ����

//������ָ�Ƶ�½һ��ģ�����flashָ�ƿ�
unsigned char PS_Input()
{
	unsigned char querenma;		//����ȷ����
	unsigned int PageID = 2;

	querenma = PS_VfyPwd();		//��֤����
	if(querenma != 0x00)
	{
		return querenma;
	}
	querenma = PS_GetImage();	//¼��ָ��ͼ��
	if(querenma != 0x00)
	{
		return querenma;
	}
	querenma = PS_GenChar(0x01);	//��������������CharBuffer1��
	if(querenma != 0x00)
	{
		return querenma;
	}
	querenma = PS_GetImage();		//�ٴ�¼��ָ��ͼ��
	if(querenma != 0x00)
	{
		return querenma;
	}
	querenma = PS_GenChar(0x02);	//��������������CharBuffer2��
	if(querenma != 0x00)
	{
		return querenma;
	}
	querenma = PS_RegModel();		//�ϲ�����������ģ�壩
	if(querenma != 0x00)
	{
		return querenma;
	}
	querenma = PS_StoreChar(0x02, PageID);	//����ģ�������ݿ�01��

	return querenma;
}

void main()
{
	unsigned char str[2];
	
	InitLcd1602();		//��ʼ��Һ��
	LcdShowStr(0,0,"Fingerprint Test");		//Һ��������ʾ����
	ConfigUART();		//��ʼ������
	Delay_Ms(200);		//��ʱ500MS���ȴ�ָ��ģ�鸴λ
	querenma = PS_Input(); 	//¼��ָ��
	LcdWriteCmd(0x01);			//����
	switch (querenma)
	{
	case 0xF0: str[0] = '2'; str[1] = '6'; break;
	case 0xF1: str[0] = '2'; str[1] = '7'; break;
	case 0xF2: str[0] = '2'; str[1] = '8'; break;
	case 0xF3: str[0] = '2'; str[1] = '9'; break;
	case 0xF4: str[0] = '3'; str[1] = '0'; break;
	case 0xF5: str[0] = '3'; str[1] = '1'; break;
	case 0xF6: str[0] = '3'; str[1] = '2'; break;
	default: str[0] = querenma / 10; str[1] = querenma % 10;
		break;
	}
	str[0] += '0';
	str[1] += '0';
	while(1)
	{	
		if(querenma == 0x00)
		{
			LcdShowStr(0, 0, "Succeed");
		}
		else
		{
			/*str[0] = (querenma & 0x0F) + '0';
			str[1] = (querenma >> 4) + '0';*/
			LcdShowStr(0, 0, "FS Error");
			LcdShowStr(0, 1, str);
		}
	}
}