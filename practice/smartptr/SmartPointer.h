#pragma once

/*
  1. ������Ҫͨ��
  2. ��Ϊ��Ҫʵ�֣�ȡ��ַ ������ -> boolֵ��Ϊ
  3. ����Ȩת��
*/


/*
  // auto_ptr ����Ȩ��ȫת��
    SmartPointer(SmartPointer& other) {
      ptr_ = other.ptr_;
      other.ptr_ = nullptr;
    }

    SmartPointer& operator=(SmartPointer& other) {
      std::swap(ptr_, other.ptr_);
      return *this;
    }

  // unique_ptr ʹ��Ȩת�� ��ռ��
     SmartPointer(SmartPointer&& other) {
      ptr_ = other.ptr_;
      other.ptr_ = nullptr;
    }

    SmartPointer& operator=(const SmartPointer& other) {
      std::swap(ptr_, other.ptr_);
      return *this;
    }


  // shared_ptr ���ü���



  // weak_ptr ����ѭ������


*/



template<typename T>
class SmartPointer {
 public:
  explicit SmartPointer(T* ptr = nullptr) : ptr_(ptr) { // �ܾ���ʽת��
  
  }

  // SmartPointer(const SmartPointer& other) = delete;
  // SmartPointer& operator=(const SmartPointer& other) = delete;

  SmartPointer(SmartPointer&& other) {
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
  }

  SmartPointer& operator=(const SmartPointer& other) {
    std::swap(ptr_, other.ptr_);
    return *this;
  }

  ~SmartPointer() {
    delete ptr_;
  }

  T& operator*() const {
    return *ptr_;
  }

  T* operator->() const {
    return ptr_;
  }

  operator bool() const { return ptr_; } 

 private:
  T* ptr_;
};

//template<typename T>
//class SmartPointer {
// public:
//  explicit SmartPointer(T* ptr = nullptr) : ptr_(ptr) {
//  
//  }
//  SmartPointer(SmartPointer& other) {
//    ptr_ = other.ptr_;
//    other.ptr_ = nullptr;
//  }
//
//  SmartPointer& operator=(SmartPointer& other) {
//    std::swap(ptr_, other.ptr_);
//    return *this;
//  }
//
//  ~SmartPointer() {
//    delete ptr_;
//  }
//
//  T& operator*() const {
//    return *ptr_;
//  }
//  T* operator->() const {
//    return ptr_;
//  }
//  operator bool() const {
//    return ptr_;
//  }
//
// private:
//  T* ptr_;
//};


