#include "Singleton.h"

// 首先 只有一份 所以要放到cpp中
// 其次 优化编译时间
// C++ 98
// Singleton* Singleton::instance_ = nullptr;  // 注意单独声明，类的静态成员变量

// C++11 饿汉
SingletonH SingletonH::instance_h;

std::unique_ptr<Singleton11> Singleton11::instance_;
std::once_flag Singleton11::flag_;