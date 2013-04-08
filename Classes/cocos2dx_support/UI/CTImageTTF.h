#ifndef __CTImageTTF_h__
#define __CTImageTTF_h__
#include "cocos2d.h"
USING_NS_CC;

enum
{
	CTIMGTTF_Z_BG,
	CTIMGTTF_Z_FONT,
};

/*
*����ͼ�ľ�̬�ı�
*
*/

class CTImageTTF:public CCNode
{
public:
	CCLabelTTF *m_lbStrValue;
	CCSprite *m_sprBg;
public:
	/*
	*bgImage:����ͼ
	*strValue���ַ���
	*fStartX���ַ������ĵ����x������ľ���
	*fontName:��������
	*fontSize:�����С
	*/
	static CTImageTTF* createImageTTF(
		const char* bgImage,
		const char* strValue,
		float fStartX,const char *fontName, float fontSize
		);

	bool initImageTTF(
		const char* bgImage,
		const char* strValue,
		float fStartX,const char *fontName, float fontSize
		);
	/*
	*strValue:�����ַ���
	**/
	void setImageTTFString(const char *strValue);
	/*
	*color:������ɫ
	*/
	void setImageTTFColor(const ccColor3B& color);
};
#endif