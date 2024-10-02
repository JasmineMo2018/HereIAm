#include "MyTestString.h"
#pragma warning(disable : 4996)
MyTestString::MyTestString() {
  data_ptr_ = new (std::nothrow) char[1];
  if (data_ptr_ != nullptr) {
    *data_ptr_ = '\0';
    data_len_ = 0;
    data_alloc_ = 1;
  }
  ref_count_ = 0;
}

MyTestString::MyTestString(const char* ptr) {
  if (ptr == nullptr) {
    data_ptr_ = new (std::nothrow) char[1];
    if (data_ptr_ != nullptr) {
      *data_ptr_ = '\0';
      data_len_ = 0;
      data_alloc_ = 1;
    }
  } else {
    size_t size = strlen(ptr);
    data_ptr_ = new (std::nothrow) char[size + 1];
    if (data_ptr_ != nullptr) {
      data_len_ = size;
      data_alloc_ = size + 1;
      strcpy(data_ptr_, ptr);
    }
  }
}

MyTestString::MyTestString(const MyTestString& ob) {
  size_t len = strlen(ob.data_ptr_);
  data_ptr_ = new (std::nothrow) char[len + 1];
  if (data_ptr_ != nullptr) {
    strcpy(data_ptr_, ob.data_ptr_);
  }
  data_len_ = len;
  data_alloc_ = len + 1;
}

MyTestString::MyTestString(MyTestString&& ob) {
  if (ob.data_ptr_ != nullptr) {
    data_ptr_ = ob.data_ptr_;
    data_len_ = ob.data_len_;
    data_alloc_ = ob.data_alloc_;
    ob.data_ptr_ = nullptr;
  }
}

MyTestString::MyTestString(int size) {
  data_ptr_ = new (std::nothrow) char[size + 1];
  if (data_ptr_ != nullptr) {
    data_len_ = size;
    data_alloc_ = size + 1;
    data_ptr_[size] = '\0';
  }
}

MyTestString& MyTestString::operator=(const MyTestString& ob) {
  if (this != &ob) {
    delete[] data_ptr_;

    size_t len = strlen(ob.data_ptr_);
    data_ptr_ = new (std::nothrow) char[len + 1];
    if (data_ptr_ != nullptr) {
      strcpy(data_ptr_, ob.data_ptr_);
    }
    data_len_ = len;
    data_alloc_ = len + 1;
  }
  return *this;
}

MyTestString& MyTestString::operator=(MyTestString&& ob) {
  if (this != &ob) {
    delete[] data_ptr_;

    data_ptr_ = ob.data_ptr_;
    data_len_ = ob.data_len_;
    data_alloc_ = ob.data_alloc_;
    ob.data_ptr_ = nullptr;
  }
  return *this;
}

MyTestString::~MyTestString() {
  if (data_ptr_ != nullptr) {
    delete[] data_ptr_;
    data_ptr_ = nullptr;
  }    
  data_len_ = 0;
  data_alloc_ = 0;
}
