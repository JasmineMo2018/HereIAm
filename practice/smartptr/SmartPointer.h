#pragma once

/*
  1. 类型需要通用
  2. 行为需要实现：取地址 解引用 -> bool值行为
  3. 归属权转移
*/


/*
  // auto_ptr 归属权完全转移
    SmartPointer(SmartPointer& other) {
      ptr_ = other.ptr_;
      other.ptr_ = nullptr;
    }

    SmartPointer& operator=(SmartPointer& other) {
      std::swap(ptr_, other.ptr_);
      return *this;
    }

  // unique_ptr 使用权转移 独占！
     SmartPointer(SmartPointer&& other) {
      ptr_ = other.ptr_;
      other.ptr_ = nullptr;
    }

    SmartPointer& operator=(const SmartPointer& other) {
      std::swap(ptr_, other.ptr_);
      return *this;
    }


  // shared_ptr 引用计数



  // weak_ptr 避免循环引用


*/



template<typename T>
class SmartPointer {
 public:
  explicit SmartPointer(T* ptr = nullptr) : ptr_(ptr) { // 拒绝隐式转换
  
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


