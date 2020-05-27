// code_report
// https://youtu.be/Jr6e8oanDrg

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>

using namespace std;

const int N = 10;

template<typename T>
void print(T t) {
   for (auto e : t) cout << e << ' ';
   cout << endl;
}

void use_generate_abc() {
   vector<string> v(5);
   generate(begin(v), end(v), [s = ""s, c = '`']() mutable { ++c; s += c; return s; });
   print(v);
}

void use_generate_n_abc() {
   vector<string> v;
   generate_n(back_inserter(v), 5, [s = ""s, c = '`']() mutable { ++c; s += c; return s; });
   print(v);
}

void use_iota() {
   vector<int> v(N);
   iota(begin(v), end(v), 1);
   print(v);
}

void use_generate() {
   vector<int> v(N);
   generate(begin(v), end(v), [i = 0]() mutable { ++i; return i; });
   print(v);
}

void use_generate_n() {
   vector<int> v;
   generate_n(back_inserter(v), N, [i = 0]() mutable { ++i; return i; });
   print(v);
}

void use_generate_n_with_reserve() {
   vector<int> v;
   v.reserve(N);
   generate_n(back_inserter(v), N, [i = 0]() mutable { ++i; return i; });
   print(v);
}

void use_generate_n_with_reserve_with_resize() {
   vector<int> v;
   v.reserve(N);
   v.resize(N);
   generate_n(begin(v), N, [i = 0]() mutable { ++i; return i; });
   print(v);
}

int main () {
   
   use_generate_abc();
   use_generate_n_abc();

   use_iota();
   use_generate();
   use_generate_n();
   use_generate_n_with_reserve();
   use_generate_n_with_reserve_with_resize();

   return 0;
}
