#include "MookSpyder.h"

// ���� ������ģ�
bool MookSpyder::GetInfo(string url) {
  vector<string> str_vec = Match(HttpGet(url));
  Write(str_vec);
}

// �ɱ�ģ� �����鷽����װ
// ��ȡ
string MookSpyder::HttpGet(string url) {
  cout << "HttpGet" << endl;
  return "xx";
}
// ��ȷ��ȡ����
vector<string> MookSpyder::Match(string html) {
  vector<string> vec;
  cout << "Match" << endl;
  return vec;
}
// д����
bool MookSpyder::Write(vector<string> content) {
  cout << "Write" << endl;
  return true;
}