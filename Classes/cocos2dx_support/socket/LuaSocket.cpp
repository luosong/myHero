#include "LuaSocket.h"


static LuaSocket *s_pGameHttp = NULL;
LuaSocket::LuaSocket(void)
{
			
}
LuaSocket::~LuaSocket(void)
{
	
}

LuaSocket* LuaSocket::getInstance()
{
	if (s_pGameHttp == NULL) {
		s_pGameHttp = new LuaSocket();
	}
	return s_pGameHttp;
}

//����������
void LuaSocket::openSocket(const char *ip,int poush){
	cSocket = new ODSocket();
	cSocket->Init();
	cSocket->Create(AF_INET, SOCK_STREAM, 0);
	cSocket->Connect(ip,poush);
}

//��������
void LuaSocket::sendSocket(const char *ch){
	//CCLog("%s completed","��ʼ����socket����");
	CCLog("%s ","send socket start");
	cSocket->Send(ch,strlen(ch),0);
}

char* LuaSocket::getSocket(){

	char recvBuf[35240] = "\0";
	cSocket->Recv(recvBuf,35240,0);
	//printf("����socket���ݽ���!\n");
	//printf(recvBuf);
	CCLog("%s ","get socket data over");
	//CCLog("%f size",strlen(recvBuf));
	return recvBuf;
}

void LuaSocket::closeSocket(){
	cSocket->Close();
	cSocket->Clean();
}
