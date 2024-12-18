#pragma once

// 单例模式
/*
  动机：全局唯一的类的实例、全局共享状态或数据，或频繁创建可能带来的资源的成本过高
  注意：平台和机制限制和程序本身的行为是两回事


  1. 懒汉 or 饿汉： 饿汉-加载的时候就创建了 资源浪费；懒汉-用，才创建
  2. 懒汉模式的多线程考虑问题，double check
  3. C++11等最新的一些实现和关注点

*/
#include <mutex>

// C++ 98 懒汉
//class Singleton {
// public:
//  static Singleton* GetInstance() {
//    if (instance_ == nullptr) {
//      std::lock_guard<std::mutex> lck(mutex_);
//      if (instance_ == nullptr) {
//        instance_ = new Singleton(); // double check
//      } 
//    }
//    return instance_;
//  }
//
// private:
//  Singleton() {}
//   ~Singleton() {}
//
// private:
//  static Singleton* instance_;
//  static std::mutex mutex_;
//};

// 多线程： 加锁
// new 之后没有delete



// 新式 C++11 懒汉 线程安全 不new
class Singleton {
 public:
  static Singleton& GetInstance() {
    static Singleton instance;
    return  ;
  }

 private:
  Singleton() = default;
  ~Singleton() = default;

  Singleton(const Singleton& ob) = delete;
  Singleton(Singleton&& ob) = delete;

  Singleton& operator=(const Singleton& ob) = delete;
  Singleton& operator=(Singleton&& ob) = delete;
};

// 饿汉
class SingletonH {
 public:
  static SingletonH& GetInstance() {
    return instance_h;
  }

 private:
  SingletonH() = default;
  ~SingletonH() = default;

  SingletonH(const SingletonH& ob) = delete;
  SingletonH(SingletonH&& ob) = delete;

  SingletonH& operator=(const SingletonH& ob) = delete;
  SingletonH& operator=(SingletonH&& ob) = delete;

  static SingletonH instance_h;
};

// C++11 call_once
 class Singleton11 {
 public:
  static Singleton11& GetInstance() {
    std::call_once(flag_, []() { instance_.reset(new Singleton11()); });
    return *instance_;
  }


  ~Singleton11() {}
 private:
  Singleton11() {}

 private:
  static std::unique_ptr<Singleton11> instance_;
  static std::once_flag flag_;
 };




