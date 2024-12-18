// factorymode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


// pushbutton： click close
// mainwindow: show close
#include <iostream>
#include "windowsui.h"
#include "osui.h"

// 抽象工厂模式
/*
  动机：
    提供一个接口，用于创建一系列相关或相互依赖的对象
    抽象工厂接口，允许客户端代码通过工厂接口创建产品，而不需要具体的产品类
    客户端代码可以于特定产品具体类解耦，实现了 抽象和实现 的分离

  模式的实现：
    抽象的工厂抽象的类，扩展的整体风格
    一系列有相互依赖相互作用的对象组合的生成
    难以应对新对象的需求变动

  应用场景：
    1. 图形用户界面库一套UI，不同系统下的按钮、文本框啥的
    2. 数据库访问需要不同的数据库系统
    3. 游戏开发，不同的平台
*/



int main() {
  std::shared_ptr<GUIFactory> factory = std::make_shared<WindowsFactory>();

  std::shared_ptr<PushButton> button = factory->CreateButton();
  std::shared_ptr<MainWindow> window = factory->CreateWindow();

  button->Click();

  button->Close();

  window->Show();
  window->Close();

  std::shared_ptr<GUIFactory> factory2 = std::make_shared<osFactory>();
  std::shared_ptr<PushButton> button2 =  factory2->CreateButton();
  std::shared_ptr<MainWindow> win2 = factory2->CreateWindow();

  button2->Click();
  button2->Close();

  win2->Show();
  win2->Close();


    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
