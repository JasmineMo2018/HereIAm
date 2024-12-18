#pragma once
#include <iostream>
#include "UI.h"

class osButton : public PushButton {
 public:
  virtual void Click() { std::cout << "os button click" << std::endl; };
  virtual void Close() { std::cout << "os button Close" << std::endl; };
};

class osWin : public MainWindow {
 public:
  virtual void Show() { std::cout << "os win show" << std::endl; };
  virtual void Close() { std::cout << "os win Close" << std::endl; };
};

class osFactory : public GUIFactory {
 public:
  virtual shared_ptr<PushButton> CreateButton() { return std::make_shared<osButton>();
  }
  virtual shared_ptr<MainWindow> CreateWindow() { return std::make_shared<osWin>(); }
};