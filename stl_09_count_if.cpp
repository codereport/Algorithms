// code_report
// https://youtu.be/-iw-wMzqG-Q

#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

void example1 () 
{
   using namespace std;

   vector<int> v = { 1, 2, 3, 1, 2 };

   cout << count (v.begin (), v.end (), 1) << endl; // 2
   cout << count (v.begin (), v.end (), 3) << endl; // 1
}

void example2 ()
{
   using namespace std;

   vector<int> v = { 1, 2, 3, 1, 2 };

   auto is_odd = [](auto e) { return e % 2 == 1; };
   cout << count_if (v.begin (), v.end (), is_odd) << endl; // 3
}

namespace my {
   template<class InIt, class T>
   auto count (InIt first, InIt last, const T& val) {
      return std::reduce (first, last, 0, [val](auto i, auto e) { return i + (e == val); });
   }
}

void example3 ()
{
   std::vector<int> v = { 1, 2, 3, 1, 2 };

   std::cout << my::count (v.begin (), v.end (), 1) << std::endl; // 2
   std::cout << my::count (v.begin (), v.end (), 3) << std::endl; // 1
}

int main ()
{
   example1 ();
   example2 ();
   example3 ();

   return 0;
}
