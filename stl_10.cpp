// code_report
// https://youtu.be/kf67rbbR6nk

#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>

template<typename T>
void print(T t) {
   for (const auto& e : t) std::cout << e << ' ';
   std::cout << '\n';
}

void example1() {
   std::vector<int> v(10);
   std::iota(begin(v), end(v), 1);
   print(v);
   auto is_even = [](auto e) { return e % 2 == 0; };
   std::partition(begin(v), end(v), is_even);
   print(v);
}

void example2() {
   std::vector<int> v(10);
   std::iota(begin(v), end(v), 1);
   print(v);
   auto is_even = [](auto e) { return e % 2 == 0; };
   std::stable_partition(begin(v), end(v), is_even);
   print(v);
}

void example3() {
   std::vector<int> v(10);
   std::iota(begin(v), end(v), 1);
   print(v);
   auto is_odd = [](auto e) { return e % 2 != 0; };
   std::remove_if(begin(v), end(v), is_odd);
   print(v);
}

void example4() {
   std::vector<int> v(10);
   std::iota(begin(v), end(v), 1);
   print(v);
   auto is_odd = [](auto e) { return e % 2 != 0; };
   v.erase(std::remove_if(begin(v), end(v), is_odd), end(v));
   print(v);
}

int main () {
   example1();
   example2();
   example3();
   example4();
   return 0;
}
