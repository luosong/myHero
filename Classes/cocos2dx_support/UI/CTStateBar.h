#ifndef __CTStateBar_h__
#define __CTStateBar_h__
#include "cocos2d.h"
USING_NS_CC;

class CTStateBar:public CCNode
{
public:
	virtual void visit(void);
	//����ͼƬbgImageΪ�����������ͼƬȷ���ÿؼ���ContentSize��fIconStartX��icon���Ե��Ըÿؼ����Ե���룬fValueStartX����ֵ������Ըÿؼ����Ե���롣
	static CTStateBar* createCTStateBar(const char *bgImage,const char *foreImage,const char *iconImage,float fIconStartX,float fValueStartX);
	bool initCTStateBar(const char *bgImage,const char *foreImage,const char *iconImage,float fIconStartX,float fValueStartX);
	void setCTStateBarValue(float fCur,float fMax);//���ȶԱȶȣ�fcur�ǵ�ǰ��ֵ��fmax�������ֵ
	void setCTStateBarPosition(CCPoint &pt);//�������������Ͻ����������Ļ���Ͻǵ����꣬

private:
	CCLabelTTF *m_lbStrValue;
	CCSprite *m_sprFore;
	CCSprite *m_sprBg;
	CCSprite *m_sprIcon;
	float m_fCur,m_fMax;
	CCSize m_selfSize;
private:
	CCString *createCStrValue();
};


#endif