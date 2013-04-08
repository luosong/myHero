#ifndef __CTEditBox_h__
#define __CTEditBox_h__
#include "cocos2d.h"

USING_NS_CC;

class CTEditBox: public CCTextFieldTTF, public CCTextFieldDelegate, public CCTouchDelegate
{
private:
    // �����ʼλ��
    CCPoint m_beginPos;
    
    // ��꾫��
    CCSprite *m_pCursorSprite;
    
    // ��궯��
    CCAction *m_pCursorAction;
                 
    // �������
    CCPoint m_cursorPos;
    
    // ���������
    std::string *m_pInputText;

	int m_nLimitedLen;
public:
    CTEditBox();
    ~CTEditBox();
    
    // static
    static CTEditBox* createCTEditBox(const char *placeholder, const char *fontName, float fontSize);
    
    // CCLayer
    void onEnter();
    void onExit();
    
    // ��ʼ����꾫��
    void initCursorSprite(int nHeight);
    
    // CCTextFieldDelegate
    virtual bool onTextFieldAttachWithIME(CCTextFieldTTF *pSender);
    virtual bool onTextFieldDetachWithIME(CCTextFieldTTF * pSender);
    virtual bool onTextFieldInsertText(CCTextFieldTTF * pSender, const char * text, int nLen);
    virtual bool onTextFieldDeleteBackward(CCTextFieldTTF * pSender, const char * delText, int nLen);
    
    // CCLayer Touch
    bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    
    // �ж��Ƿ�����TextField��
    bool isInTextField(CCTouch *pTouch);
    // �õ�TextField����
    CCRect getRect();
    
    // �����뷨
    void openIME();
    // �ر����뷨
    void closeIME();

	void setLimitedLen(int nLimitedLen);

	const char* getInputString();
};

#endif
