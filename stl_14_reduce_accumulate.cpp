// code_report
// Video Link: https://youtu.be/Mcjrc2uxbKI

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

namespace my {
   template<class I, class T>
   auto count(I f, I l, const T& val) {
      return std::reduce(f, l, 0,
         [val](auto a, auto b) { return a + (b == val); });
   }

   template<class I, class P>
   auto any_of(I f, I l, P p) {
      return std::reduce(f, l, false,
         [p](auto a, auto b) { return a || p(b); });
   }
}

void example1() {
   vector v = { 1, 2, 3, 4 };

   auto x = accumulate(begin(v), end(v), 0);
   auto y = accumulate(begin(v), end(v), 1, multiplies<>());
}

void example2() {
   vector v = { 1, 2, 3, 4 };

   auto x = reduce(begin(v), end(v));
   auto y = reduce(begin(v), end(v), 0, plus<>());
   auto z = reduce(begin(v), end(v), 1, multiplies<>());
}

void example3() {
   vector v = { 1, 2, 3, 1, 2 };

   auto x =  my::count(begin(v), end(v), 1);
   auto y = std::count(begin(v), end(v), 1);
}

void example4() {
   vector v = { 1, 2, 3 };

   auto x =  my::any_of(begin(v), end(v), [](auto e) { return e == 3; });
   auto y = std::any_of(begin(v), end(v), [](auto e) { return e == 3; });
}

int main() {
   return 0;
}
