#ifndef _AS608_H_
#define _AS608_H_

unsigned char PS_VfyPwd();
/****************************************************************************************************************
¼��ͼ�� PS_GetImage

**����˵����̽����ָ��̽�⵽��¼��ָ��ͼ�����ImageBuffer������ȷ�����ʶ��¼��ɹ�������ָ�ȡ�
**���������none
**���ز�����ȷ����
**ָ����룺01H
**ָ�����ʽ����
**Ӧ�����ʽ����
**ע��ȷ����=00H��ʾ¼��ɹ���
******ȷ����=01H��ʾ�հ��д�
******ȷ����=02H��ʾ������������ָ��
******ȷ����=03H��ʾ¼�벻�ɹ���
****************************************************************************************************************/
unsigned char PS_GetImage();
unsigned char PS_GenChar(unsigned char BufferID);
unsigned char PS_RegModel(); 
unsigned char PS_StoreChar(unsigned char BufferID, unsigned int PageID);

#endif
