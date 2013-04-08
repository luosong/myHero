#include "ODSocket.h"
#include <vector>

 #include "cocos2d.h"
#include "cocos-ext.h"
 USING_NS_CC;
 USING_NS_CC_EXT;
using namespace std;
class LuaSocket: public CCObject
{
public:
	ODSocket *cSocket;
public:
	static LuaSocket* getInstance();
	LuaSocket(void);
	~LuaSocket(void);
	void openSocket(const char *ip,int poush);//��socket������
	void sendSocket(const char *ch);//���ͷ�����
	char* getSocket();//�ӷ������������
	void closeSocket();//�رշ�����
};

