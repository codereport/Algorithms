// code_report
// https://youtu.be/BN9lYrtZsVM

#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <iostream>

using namespace std;

void example1_trivial() {
   cout << "Min of 1 and 2: " << min(1, 2) << endl;
   cout << "Max of 1 and 2: " << max(1, 2) << endl;
}

void example1() {
   auto i = { 1, 2, 3 }; // initializer list
   cout << "Min is " << min(i) << endl;
   cout << "Max is " << max(i) << endl;
}

void example2a() {
   // Before C++11
   int a = 2;
   int b = 1;
   pair<int, int> p = minmax(a, b);
   cout << "Min is " << p.first  << endl;
   cout << "Max is " << p.second << endl;
}

void example2b() {
   // C++11 
   int a = 2;
   int b = 1;
   auto p = minmax(a, b);
   cout << "Min is " << p.first  << endl;
   cout << "Max is " << p.second << endl;
}

void example2c() {
   // C++11 
   int a = 2;
   int b = 1;
   tie(a, b) = minmax(a, b); // BUG
   cout << "Min is " << a << endl;
   cout << "Max is " << b << endl;
}

template<typename T>
auto minmax_copy(const T& a, const T& b) {
   return (b < a) ? std::pair<const T, const T>(b, a)
                  : std::pair<const T, const T>(a, b);
}

void example2d() {
   // C++11 
   int a = 2;
   int b = 1;
   tie(a, b) = minmax_copy(a, b);
   cout << "Min is " << a << endl;
   cout << "Max is " << b << endl;
}

void example2e() {
   // C++17 Structured Bindings
   int a = 2;
   int b = 1;
   auto [min_, max_] = minmax(a, b);
   cout << "Min is " << min_ << endl;
   cout << "Max is " << max_ << endl;
   // min_ = 0; // compile error: assignment of read-only reference ‘min_’
}

void example2f() {
   // C++17 Structured Bindings
   auto i = { 1, 2, 3 };
   auto [min_, max_] = minmax(i);
   cout << "Min is " << min_ << endl;
   cout << "Max is " << max_ << endl;
}


void example3() {
   vector<int> v = { 3, 1, 5, 4, 2 };
   auto min_ = *min_element(begin(v), end(v));
   cout << "Min is " << min_ << endl;
}

void example4() {
   vector<int> v = { 3, 1, 5, 4, 2 };
   auto max_ = *max_element(begin(v), end(v));
   cout << "Max is " << max_ << endl;
}

void example5() {
   vector<int> v = { 3, 1, 5, 4, 2 };
   auto[min_, max_] = minmax_element(begin(v), end(v));
   cout << "Min is " << *min_ << endl;
   cout << "Max is " << *max_ << endl;
}

int main() {

   example1_trivial();
   example1();
   example2a();
   example2b();
   example2c();
   example2d();
   example2e();
   example2f();
   example3();
   example4();
   example5();

   return 0;
}
