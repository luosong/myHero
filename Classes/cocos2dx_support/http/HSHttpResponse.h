/********************************************************************
  *  Copyright(C) 2012 Ambition( All rights reserved. )
  *    Created:    2012/09/20   9:42
  *    File base:    HSHttpResponse.h
  *    Author:        Ambition
  *    
  *    Purpose:    ��Ӧ�������صľ������ݣ�����û�н���
 *********************************************************************/
 #ifndef __HSHttpResponse_H__
 #define __HSHttpResponse_H__
 #pragma once
 #include "HSHttpRequest.h"
 
 
 class HSHttpResponse : public CCObject
 {
 public:
     HSHttpResponse(HSHttpRequest* request);
     virtual ~HSHttpResponse(void);
 
 protected:
     HSHttpRequest*    pHttpRequest;    //��Ӧ������ָ��
     bool            isSucceed;        //�Ƿ�ɹ�
     vector<char>    vResponseData;    
     int                iResponseCode;    //��Ӧ����
     string            strErrorBuffer;    //������Ϣ����
 
 public:
     HSHttpRequest* GetHttpRequest();
 
     void SetResponseData(std::vector<char>* data);
     vector<char>* GetResponseData();
 
     void SetResponseCode(int value);
     int GetResponseCode();
 
     void SetSucceed(bool value);
     bool GetSucceed();
 
     void SetErrorBuffer(const char* value);
     const char* GetErrorBuffer();
 
 };
 
 #endif // __HSHttpResponse_H__