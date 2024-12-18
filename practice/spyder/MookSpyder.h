#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class MookSpyder {
 public:
  // 流程 （不变的）
  bool GetInfo(string url);

  // 可变的， 考虑虚方法封装
  // 获取
  virtual string HttpGet(string url);
  // 精确提取数据
  virtual vector<string> Match(string html);
  // 写数据
  virtual bool Write(vector<string> content);
};
