#ifndef _LCD1602_H_
#define _LCD1602_H_

#include<reg52.h>

//LCD1602 IO����
#define LCD1602_DB P0
sbit LCD1602_RS = P2 ^ 6;
sbit LCD1602_RW = P2 ^ 5;
sbit LCD1602_E = P2 ^ 7;

//�������߱�������

/*�ȴ�Һ��׼����*/
void LcdWaitReady();

/*��LCD1602Һ��д��һ�ֽ����cmdΪ��д������ֵ*/
void LcdWriteCmd(unsigned char cmd);

/*��LCD1602Һ��д��һ�ֽ����ݣ�datΪ��д������ֵ*/
void LcdWriteDat(unsigned char dat);

/*������ʾRAM��ʼ��ַ���༴���Ϊֹ��(x,y)Ϊ��Ӧ��Ļ�ϵ��ַ�����*/
void LcdSetCursor(unsigned char x, unsigned char y);

/*��Һ������ʾ�ַ�����(x,y)Ϊ��Ӧ��Ļ�ϵ���ʼ���꣬strΪ�ַ���ָ�룬lenΪ��Ҫ��ʾ���ַ�����*/
void LcdShowStr(unsigned char x, unsigned char y, unsigned char *str);

/*��ʼ��1602Һ��*/
void InitLcd1602();

#endif