#include<reg52.h>
#include<intrins.h>
#include"uart.h"
#include"as608.h"
#include"lcd1602.h"
#include"DELAY.h"

unsigned char querenma;		//接收确认码

//按两次指纹登陆一个模板存于flash指纹库
unsigned char PS_Input()
{
	unsigned char querenma;		//接收确认码
	unsigned int PageID = 2;

	querenma = PS_VfyPwd();		//验证口令
	if(querenma != 0x00)
	{
		return querenma;
	}
	querenma = PS_GetImage();	//录入指纹图像
	if(querenma != 0x00)
	{
		return querenma;
	}
	querenma = PS_GenChar(0x01);	//生成特征，存于CharBuffer1中
	if(querenma != 0x00)
	{
		return querenma;
	}
	querenma = PS_GetImage();		//再次录入指纹图像
	if(querenma != 0x00)
	{
		return querenma;
	}
	querenma = PS_GenChar(0x02);	//生成特征，存于CharBuffer2中
	if(querenma != 0x00)
	{
		return querenma;
	}
	querenma = PS_RegModel();		//合并特征（生成模板）
	if(querenma != 0x00)
	{
		return querenma;
	}
	querenma = PS_StoreChar(0x02, PageID);	//储存模板于数据库01号

	return querenma;
}

void main()
{
	unsigned char str[2];
	
	InitLcd1602();		//初始化液晶
	LcdShowStr(0,0,"Fingerprint Test");		//液晶开机显示界面
	ConfigUART();		//初始化串口
	Delay_Ms(200);		//延时500MS，等待指纹模块复位
	querenma = PS_Input(); 	//录入指纹
	LcdWriteCmd(0x01);			//清屏
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