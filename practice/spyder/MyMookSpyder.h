#pragma once
#include "MookSpyder.h"
class MyMookSpyder : public MookSpyder {
  // �ɱ�ģ� �����鷽����װ
  // ��ȡ
  virtual string HttpGet(string url) override;
  // ��ȷ��ȡ����
  virtual vector<string> Match(string html) override;
  // д����
  virtual bool Write(vector<string> content) override;
};
