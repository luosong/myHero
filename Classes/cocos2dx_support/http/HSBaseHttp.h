/********************************************************************
  
*  Copyright(C) 2012 Ambition( All rights reserved. )
  
*    Created:    2012/09/18   11:21
 
*    File base:    HSBaseHttp.h
  
*    Author:        Ambition
  
*    
  
*    Purpose:    
 
*********************************************************************/
 
#ifndef __HSBaseHttp_H__
 
#define __HSBaseHttp_H__
 
#pragma once
 
#include "cocos2d.h"
 
//#include "curl.h"
#include "curl/curl.h"
#include <queue>
 
#include <pthread.h>
 
#include <semaphore.h>
 
#include <errno.h>
 
#include "HSHttpRequest.h"
 
#include "HSHttpResponse.h"

using namespace cocos2d;
 
 
#if WIN32
 
#pragma comment(lib,"libcurl_imp.lib")

 #pragma comment(lib,"pthreadVCE2.lib")
 
#endif
 
 
 
class HSBaseHttp : public CCObject
 {

 
 public:
     HSBaseHttp();

     virtual ~HSBaseHttp();

 
 private:
     int iTimeoutForConnect;        //���ӳ�ʱʱ��
	  
     int iTimeoutForRead;        //��ȡ��ʱʱ��

 public:
     //�õ�һ��ʵ��

     static HSBaseHttp* GetInstance();
     //����ʵ��

     static void DestroyInstance();
     //��������

     void Send(HSHttpRequest* request);

     void SetTimeoutForConnect(int value);

     
int GetTimeoutForConnect();

  
   void SetTimeoutForRead(int value);

 
    int GetTimeoutForRead();

 private:
     
     //���ٻص�

     void DispatchResponseCallbacks(float delta);

     //�߳��źų�ʼ��

     bool LazyInitThreadSemphore();

 };

 
#endif 
// __HSBaseHttp_H__