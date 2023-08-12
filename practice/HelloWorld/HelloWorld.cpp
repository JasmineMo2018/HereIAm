// HelloWorld.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main() {
  std::cout << "Hello World!\n";

  int age;
  double height;
  std::cout << "please input your age and height" << std::endl;
  std::cin >> age;
  std::cin >> height;
  std::cout << "your age:" << age << ",your height : " << height << std::endl;

  return 0;
}

// C++的cin和cout，不需要对类型做过多的考虑。类型更安全，扩展性更好，但是效率不是很高。
