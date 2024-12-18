#pragma once
#include <iostream>
#include "UI.h"
class WindowsButton : public PushButton {
 public:
  virtual void Click() { std::cout << "windows button click" << std::endl;
  }
  virtual void Close() { std::cout << "windows button close" << std::endl;
  }
};




class WindowsWin : public MainWindow {
 public:
  virtual void Show() { std::cout << "windows win show" << std::endl; }
  virtual void Close() { std::cout << "windows win close" << std::endl; }
};

class WindowsFactory : public GUIFactory {
 public:
  virtual shared_ptr<PushButton> CreateButton() {
    std::cout << "windows CreateButton" << std::endl; 
    return std::make_shared<WindowsButton>();
  }
  virtual shared_ptr<MainWindow> CreateWindow() {
    std::cout << "windows CreateWindow" << std::endl;
    return std::make_shared<WindowsWin>();
  }
};