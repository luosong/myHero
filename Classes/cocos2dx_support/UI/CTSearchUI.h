#ifndef __CTSearchUI_h__
#define __CTSearchUI_h__
#include "cocos2d.h"
#include "CTSearchButton.h"
#include "CTEditBox.h"
USING_NS_CC;
class CTSearchUI:public CCNode
{
public:
	/*
	*������pStrNormalImage����ťͼδѡ��,pStrSelectedImage����ťѡ��,pStrDisableImage:��ť������,
	placeholder:�༭��Ĭ���ı�,fontName:�������ͣ�fontSize�������С,type:��ť�������ͣ�����id����pParams����Ӧ�¼�����
	*/
	static CTSearchUI* createCTSearchUI(const char *pStrNormalImage,const char *pStrSelectedImage,const char *pStrDisableImage,
		const char *placeholder, const char *fontName, float fontSize,int type,char *pParams);	
	
	bool initCTSearchUI(const char *pStrNormalImage,const char *pStrSelectedImage,const char *pStrDisableImage,
		const char *placeholder, const char *fontName, float fontSize,int type,char *pParams);
	/*
	*
	*/
	void setCTSearchUIPosition(CCPoint &ptEditBox,CCPoint &ptBtn);//δ���
	void registerScriptTapHandler(int nHandler);
	void unregisterScriptTapHandler(void);
public:
	CTSearchButton* m_pBtn;
	CTEditBox* m_pEditBox;
};
#endif