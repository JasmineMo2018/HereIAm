#pragma once

#include <vector>

int Add(int a, int b = 1);
double Add(double a, double b);

template <typename T>
T add(const std::vector<T> &v) {
  T result = 0.0;
  for (const T& value : v) {
    result += value;
  }
  return result;
}
