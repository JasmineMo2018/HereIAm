#pragma once
#include "MookSpyder.h"
class MyMookSpyder : public MookSpyder {
  // 可变的， 考虑虚方法封装
  // 获取
  virtual string HttpGet(string url) override;
  // 精确提取数据
  virtual vector<string> Match(string html) override;
  // 写数据
  virtual bool Write(vector<string> content) override;
};
