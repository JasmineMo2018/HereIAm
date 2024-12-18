#pragma once

// ����ģʽ
/*
  ������ȫ��Ψһ�����ʵ����ȫ�ֹ���״̬�����ݣ���Ƶ���������ܴ�������Դ�ĳɱ�����
  ע�⣺ƽ̨�ͻ������ƺͳ��������Ϊ��������


  1. ���� or ������ ����-���ص�ʱ��ʹ����� ��Դ�˷ѣ�����-�ã��Ŵ���
  2. ����ģʽ�Ķ��߳̿������⣬double check
  3. C++11�����µ�һЩʵ�ֺ͹�ע��

*/
#include <mutex>

// C++ 98 ����
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

// ���̣߳� ����
// new ֮��û��delete



// ��ʽ C++11 ���� �̰߳�ȫ ��new
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

// ����
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




