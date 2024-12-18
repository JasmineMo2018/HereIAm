#include "Singleton.h"

// ���� ֻ��һ�� ����Ҫ�ŵ�cpp��
// ��� �Ż�����ʱ��
// C++ 98
// Singleton* Singleton::instance_ = nullptr;  // ע�ⵥ����������ľ�̬��Ա����

// C++11 ����
SingletonH SingletonH::instance_h;

std::unique_ptr<Singleton11> Singleton11::instance_;
std::once_flag Singleton11::flag_;