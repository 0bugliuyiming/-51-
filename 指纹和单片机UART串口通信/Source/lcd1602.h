#ifndef _LCD1602_H_
#define _LCD1602_H_

#include<reg52.h>

//LCD1602 IO设置
#define LCD1602_DB P0
sbit LCD1602_RS = P2 ^ 6;
sbit LCD1602_RW = P2 ^ 5;
sbit LCD1602_E = P2 ^ 7;

//函数或者变量声明

/*等待液晶准备好*/
void LcdWaitReady();

/*向LCD1602液晶写入一字节命令，cmd为待写入命令值*/
void LcdWriteCmd(unsigned char cmd);

/*向LCD1602液晶写入一字节数据，dat为待写入数据值*/
void LcdWriteDat(unsigned char dat);

/*设置显示RAM起始地址，亦即光标为止，(x,y)为对应屏幕上的字符坐标*/
void LcdSetCursor(unsigned char x, unsigned char y);

/*在液晶上显示字符串，(x,y)为对应屏幕上的起始坐标，str为字符串指针，len为需要显示的字符长度*/
void LcdShowStr(unsigned char x, unsigned char y, unsigned char *str);

/*初始化1602液晶*/
void InitLcd1602();

#endif