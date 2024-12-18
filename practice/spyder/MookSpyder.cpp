#include "MookSpyder.h"

// 流程 （不变的）
bool MookSpyder::GetInfo(string url) {
  vector<string> str_vec = Match(HttpGet(url));
  Write(str_vec);
}

// 可变的， 考虑虚方法封装
// 获取
string MookSpyder::HttpGet(string url) {
  cout << "HttpGet" << endl;
  return "xx";
}
// 精确提取数据
vector<string> MookSpyder::Match(string html) {
  vector<string> vec;
  cout << "Match" << endl;
  return vec;
}
// 写数据
bool MookSpyder::Write(vector<string> content) {
  cout << "Write" << endl;
  return true;
}