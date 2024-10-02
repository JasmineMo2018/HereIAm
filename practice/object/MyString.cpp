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


   // 四个构造
MyStringTest::MyStringTest(int size) {
  my_string_ptr_ = new (std::nothrow) char[size];
  if (my_string_ptr_ == nullptr) {
    exit(-1);
  }
  my_string_ptr_[size - 1] = '\0';
  string_len = size - 1;
  malloc_len = size;
}

MyStringTest::MyStringTest() {
  my_string_ptr_ = new (std::nothrow) char[1];
  if (my_string_ptr_ == nullptr) {
    exit(-1);
  }
  *my_string_ptr_ = '\0';
  string_len = 0;
  malloc_len = 1;
}

MyStringTest::MyStringTest(const char* str_ptr) {
  if (str_ptr == nullptr) {
    my_string_ptr_ = new (std::nothrow) char[1];
    if (my_string_ptr_ == nullptr) {
      exit(-1);
    }
    *my_string_ptr_ = '\0';
    string_len = 0;
    malloc_len = 1;
  } else {
    int cur_len = strlen(str_ptr);
    my_string_ptr_ = new (std::nothrow) char[cur_len + 1];
    if (my_string_ptr_ == nullptr) {
      exit(-1);
    }
    strcpy(my_string_ptr_, str_ptr);
    string_len = cur_len;
    malloc_len = cur_len + 1;
  }
}

MyStringTest::MyStringTest(const MyStringTest& ob) {
  my_string_ptr_ = new (std::nothrow) char[ob.malloc_len];
  if (my_string_ptr_ == nullptr) {
    exit(-1);
  }
  strcpy(my_string_ptr_, ob.my_string_ptr_);

  string_len = ob.string_len;
  malloc_len = ob.malloc_len;
}

MyStringTest::MyStringTest(MyStringTest&& ob) {
  my_string_ptr_ = ob.my_string_ptr_;
  string_len = ob.string_len;
  malloc_len = ob.malloc_len;

  ob.my_string_ptr_ = nullptr;
}

// 两个赋值
MyStringTest& MyStringTest::operator=(const MyStringTest& ob) {
  if (this != &ob) {
    if (my_string_ptr_ != nullptr) {
      delete[] my_string_ptr_;
    }

    my_string_ptr_ = new (std::nothrow) char[ob.malloc_len];
    if (my_string_ptr_ == nullptr) {
      exit(-1);
    }
    strcpy(my_string_ptr_, ob.my_string_ptr_);

    string_len = ob.string_len;
    malloc_len = ob.malloc_len;
  }
  return *this;
}

MyStringTest& MyStringTest::operator=(MyStringTest&& ob) {
  if (this != &ob) {
    if (my_string_ptr_ != nullptr) {
      delete[] my_string_ptr_;
    }

    my_string_ptr_ = ob.my_string_ptr_;
    string_len = ob.string_len;
    malloc_len = ob.malloc_len;

    ob.my_string_ptr_ = nullptr;
  }
  return *this;
}

// 一个析构
MyStringTest::~MyStringTest() {
  if (my_string_ptr_ != nullptr) {
    delete[] my_string_ptr_;
  }
  my_string_ptr_ = nullptr;
  string_len = 0;
  malloc_len = 0;
}