// buildermode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "computerbuilder.h"
#include "lenevocomputer.h"
/*
  builder 生成器

  将一个复杂对象的构建过程于其表示分离，使同一个构建过程可以创建不同的表示

  当需要创建一个包含多个部分或配置选项的复杂对象，并且需要将构建过程和表示分离时

  页面生成 ORM框架

  1. 经典builder
  2. 链式builder
  3. builder和 factory的区别
    builer 关注一个对象
    factory 关注多个对象
*/

class Director {

  public:
  Computer BuildComputer(ComputerBuilder& builder) {
    builder.BuildCpu();
    builder.BuildMempry();
    builder.BuildStorage();

    return builder.CreateComputer();
  }
};

class Render {
 public:
  virtual void RenderShape() = 0;

};

class OpenGL : public Render {
 public:
  virtual void RenderShape() { return;
  }

};

class xxGL : public Render {
 public:
  virtual void RenderShape() {
    std::cout << "xxgl rander shape." << std::endl;
    return;
  }
};

// 桥接
class Shape {
 protected:
  std::shared_ptr<Render> render_;

 public:
  Shape(std::shared_ptr<Render> render) : render_(render) {
  
  }

  virtual void Draw() = 0;
};

class CircleShape : public Shape {

 public:
  CircleShape(std::shared_ptr<Render> render) : Shape(render) {}

  virtual void Draw() { std::cout << "circlel shape draw" << std::endl;
    render_->RenderShape();
  }
};

int main() {
  auto ptr_r = make_shared<xxGL>();
  auto ptr = make_shared<CircleShape>(ptr_r);
  ptr->Draw();
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

