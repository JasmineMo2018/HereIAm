#pragma once
#include <iostream>
class Retional final {
 public:
  // 三个构造
  Retional(int num = 0, int den = 1) : numerator_(num), denominator_(den){}
  Retional(const Retional& other) : numerator_(other.numerator_), denominator_(other.denominator_) {}
  Retional(Retional&& other)
      : numerator_(other.numerator_),
        denominator_(other.denominator_){
    other.numerator_ = 0;
    other.denominator_ = 1;
  }

  // 两个赋值 = 重载
  Retional& operator=(const Retional& other) {
    if (this != &other) {
      numerator_ = other.numerator_;
      denominator_ = other.denominator_;
    }

    return *this;
  }

  Retional& operator=(Retional&& other) {
    if (this != &other) {
      numerator_ = other.numerator_;
      denominator_ = other.denominator_;
      other.numerator_ = 0;
      other.denominator_ = 1;
    }
    return *this;
  }

  // 一个析构
  ~Retional() {}

  // operator overload + - * / += -= *= /= <<
  Retional operator+(const Retional& other) {
    return Retional(numerator_ * other.denominator_ + other.numerator_ * denominator_,
                    denominator_ * other.denominator_);
  }

  Retional& operator+=(const Retional& other) { 
    return *this = *this + other;
  }

  Retional operator-(const Retional& other) {
    return Retional(numerator_ * other.denominator_ - other.numerator_ * denominator_,
                    denominator_ * other.denominator_);
  }

  Retional& operator-=(const Retional& other) { return *this = *this - other; }

  Retional operator*(const Retional& other) {
    return Retional(numerator_ * other.numerator_,
                    denominator_ * other.denominator_);
  }

  Retional& operator*=(const Retional& other) { return *this = *this * other; }

  Retional operator/(const Retional& other) {
    return Retional(numerator_ * other.denominator_, denominator_ * other.numerator_);
  }

  Retional& operator/=(const Retional& other) { return *this = *this / other; }

  friend std::ostream& operator<<(std::ostream& os, const Retional& r) {
    os << r.numerator_ << "/" << r.denominator_;
  }

  bool operator==(const Retional& other) const {
    return numerator_ == other.numerator_ && denominator_ == other.denominator_;
  }

  bool operator!=(const Retional& other) const { return !(*this == other);
  }

  private:
  int numerator_; // 分子
   int denominator_; // 分母
};
