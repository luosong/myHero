#ifndef __CTButton_h__
#define __CTButton_h__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "CTBase.h"
//#include "ClickManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
class CTBase;
enum
{
	kTagCTButtonNormalImage = 0,
	kTagCTButtonSelectedImage,
	kTagCTButtonDisableImage,
};
enum
{
	kTagCTButtonStateNormal= 0,
	kTagCTButtonStateSelected,
	kTagCTButtonStateDisable,
};
class CTButton:public CTBase, public CCTouchDelegate
{
public:/*��3��ģʽ�İ�ť������pStrNormalImageΪ�������
	   1����ֻ��pStrNormalImage����������ΪNULL,��ʾ�ð�ť���µ�ͼƬ�͵�������ͼƬһ����
	   2:��pStrNormalImage��pStrSelectedImage������ΪNULL,��ʾ����ȥ��ͼƬ�͵�������ͼƬ��һ����
	   3��3��״̬���У����setCDownTime���õ�ֵ����0,��������ť����벻����״̬��������Ӧ��ʱ����Զ��ص�����״̬��
*/
	static CTButton* createCTButton(const char *pStrNormalImage,const char *pStrSelectedImage,const char *pStrDisableImage);
	~CTButton();
	void setCDownTime(int nTime);
	void setCTButtonPosition(CCPoint &pt);//�������������Ͻ����������Ļ���Ͻǵ����꣬
	CTButton()
		: m_bIsEnabled(true)
		,m_bNorImgExisted(false)
		,m_bSelImgExisted(false)
		,m_bDisImgExisted(false)
		,m_nCDTime(0)
	{}
public:
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

	virtual void active();
	bool isInSelf(CCTouch *pTouch);
	bool isInSelf(CCPoint &pt);
	CCRect getRect();
	virtual void setEnabled(bool value);
	bool isEnabled();
	void CDTimeCallBack(float dt);
private:
	bool m_bIsEnabled;
	bool m_bNorImgExisted;
	bool m_bSelImgExisted;
	bool m_bDisImgExisted;
	int m_nCDTime;
	CCSize  m_selfSize;
	CCPoint m_beginPos;
	CCPoint m_cursorPos;
public:
	bool initCTButton(const char *pStrNormalImage,const char *pStrSelectedImage,const char *pStrDisableImage);
	void onEnter();
	void onExit();
	int m_nStateCurrent;
};
#endif   