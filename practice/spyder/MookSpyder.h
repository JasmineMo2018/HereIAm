#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class MookSpyder {
 public:
  // ���� ������ģ�
  bool GetInfo(string url);

  // �ɱ�ģ� �����鷽����װ
  // ��ȡ
  virtual string HttpGet(string url);
  // ��ȷ��ȡ����
  virtual vector<string> Match(string html);
  // д����
  virtual bool Write(vector<string> content);
};
