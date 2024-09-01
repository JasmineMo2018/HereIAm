#include <string>
#include "MyString.h"
#pragma warning(disable : 4996)
MyString::MyString(const char* ch) {
  if (ch == nullptr) {
    m_ch = new (std::nothrow) char[1];
    if (m_ch == nullptr) {
      return;
    }
    *m_ch = '\0';
    m_len = 0;
    m_alloc = 1;
  } else {
    size_t len = strlen(ch);
    m_ch = new (std::nothrow) char[len + 1];
    if (m_ch == nullptr) {
      return;
    }
    m_len = len;
    m_alloc = len + 1;
    strcpy(m_ch, ch);
  }
}

MyString::MyString(size_t len) {
  m_ch = new (std::nothrow) char[len];
  if (m_ch == nullptr) {
    return;
  }
  m_len = len - 1;
  m_alloc = len;
  m_ch[len - 1] = '\0';
}

MyString::MyString(const MyString& ob) {
  size_t len = strlen(ob.m_ch);
  m_ch = new (std::nothrow) char[len + 1];
  if (m_ch == nullptr) {
    return;
  }
  m_len = len;
  m_alloc = len + 1;
  strcpy(m_ch, ob.m_ch);
}

MyString::MyString(MyString&& ob) {
  if (ob.m_ch != nullptr) {
    m_ch = ob.m_ch;
    m_len = ob.m_len;
    m_alloc = ob.m_alloc;
    ob.m_ch = nullptr;
  }
}

MyString& MyString::operator=(const MyString& ob) {
  // 判断是否自身赋值
  if (this != &ob) {
    // 清空自身的资源
    delete[] m_ch;
    // 申请空间
    size_t len = strlen(ob.m_ch);
    m_ch = new (std::nothrow) char[len + 1];
    if (m_ch == nullptr) {
      exit(-1);
    }
    m_len = ob.m_len;
    m_alloc = ob.m_alloc;
    strcpy(m_ch, ob.m_ch);
  }
  return *this;
}

MyString& MyString::operator=(MyString&& ob) {
  if (this != &ob) {
    if (m_ch != nullptr) {
      delete[] m_ch;
    }
    m_ch = ob.m_ch;
    m_len = ob.m_len;
    m_alloc = ob.m_alloc;
    ob.m_ch = nullptr;
  }
  return *this;
}

MyString::MyString() {
  // 构造函数里面不能放很复杂的操作
  // 打开文件、数据库、网络操作、申请空间之类的，都不要搞
  // 接口里面搞Init Start等，去做复杂操作
  m_ch = new (std::nothrow) char[1];
  if (m_ch == nullptr) {
    return;
  }
  *m_ch = '\0';
  m_len = 0;
  m_alloc = 1;
}

MyString::~MyString() {
  if (m_ch != nullptr) {
    delete[] m_ch;
    m_ch = nullptr;
  }
  m_len = 0;
  m_alloc = 0;
}