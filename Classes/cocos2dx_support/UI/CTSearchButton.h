#ifndef __CTSearchButton_h__
#define __CTSearchButton_h__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "CTButton.h"
#include "CTEditBox.h"
//#include "ClickManager.h"
USING_NS_CC;
USING_NS_CC_EXT;

class CTSearchButton:public CTButton
{
public:/*��3��ģʽ�İ�ť������pStrNormalImageΪ�������
	   1����ֻ��pStrNormalImage����������ΪNULL,��ʾ�ð�ť���µ�ͼƬ�͵�������ͼƬһ����
	   2:��pStrNormalImage��pStrSelectedImage������ΪNULL,��ʾ����ȥ��ͼƬ�͵�������ͼƬ��һ����
	   3��3��״̬���У����setCDownTime���õ�ֵ����0,��������ť����벻����״̬��������Ӧ��ʱ����Զ��ص�����״̬��
*/
	static CTSearchButton* createCTSearchButton(const char *pStrNormalImage,const char *pStrSelectedImage,const char *pStrDisableImage);
public:
	virtual void active();
	void setEditBoxBinding(CTEditBox *pEditBox);
	CTEditBox *m_pEditBox;
};
#endif   