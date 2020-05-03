// code_report Solution
// https://youtu.be/Mf90cdF2N-o

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

template<typename T>
void print (T t) {
   for (const auto& e : t) cout << e << " ";
   cout << endl;
}

int main ()
{
   vector<int> a (5), b (5), c (5);

   iota (a.begin (), a.end (), 1);
   partial_sum (a.begin (), a.end (), b.begin ()); // by default plus<> ()
   partial_sum (a.begin (), a.end (), c.begin (), multiplies<> ());

   print (a);
   print (b);
   print (c);

   return 0;
}
