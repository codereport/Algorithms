// code_report
// https://youtu.be/Mclo4og_7fE

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

template<typename T>
void print(T t) {
   for (auto e : t) cout << e << ' ';
   cout << '\n';
}

void example1() {
   vector v = { 1, 2, 2, 3, 3, 1, 2, 2 };
   v.erase(unique(begin(v), end(v)), end(v));
   print(v);
}

void example2() {
   vector v = { 1, 2, 2, 3, 3, 1, 2, 2 };
   vector<int> u;
   unique_copy(begin(v), end(v), back_inserter(u));
   print(u);
}

void example3() {
   vector v = { 1, 2, 2, 3, 3, 1, 2, 2 };
   v.erase(unique(begin(v), end(v), greater<>()), end(v));
   print(v);
}

void example4() {
   vector v = { 1, 2, 2, 3, 3, 1, 2, 2 };
   v.erase(unique(begin(v), end(v), less<>()), end(v));
   print(v);
}

template<typename F>
auto my_unique(F f, F l) {
   auto comp_with_prev = [prev = *f](auto e) mutable {
      auto p = prev; prev = e; return e == p;
   };
   return remove_if(next(f), l, comp_with_prev);
}

void example5() {
   vector v = { 1, 2, 2, 3, 3, 1, 2, 2 };
   vector u = v;

   v.erase(unique(begin(v), end(v)), end(v));
   u.erase(my_unique(begin(u), end(u)), end(u));

   print(v);
   print(u);
}

int main() {

   example1();
   example2();
   example3();
   example4();
   example5();

   return 0;
}
