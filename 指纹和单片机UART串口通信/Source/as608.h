#ifndef _AS608_H_
#define _AS608_H_

unsigned char PS_VfyPwd();
/****************************************************************************************************************
录入图像 PS_GetImage

**功能说明：探测手指，探测到后录入指纹图像存于ImageBuffer，返回确认码标识：录入成功，无手指等。
**输入参数：none
**返回参数：确认字
**指令代码：01H
**指令包格式：略
**应答包格式：略
**注：确认码=00H表示录入成功；
******确认码=01H表示收包有错；
******确认码=02H表示传感器上无手指；
******确认码=03H表示录入不成功；
****************************************************************************************************************/
unsigned char PS_GetImage();
unsigned char PS_GenChar(unsigned char BufferID);
unsigned char PS_RegModel(); 
unsigned char PS_StoreChar(unsigned char BufferID, unsigned int PageID);

#endif
