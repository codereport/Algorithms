// code_report
// https://youtu.be/UN_twk5w0RM

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional> 

using namespace std;

void example1 () 
{
   vector<int> v = { 0, 5, 2, 2, 3, 1, 4, 4 };

   auto it = adjacent_find (v.begin (), v.end ());

   cout << "Value: " << *it << endl;
   cout << "Index: " << distance (v.begin (), it) << endl;
}

void example2 ()
{
   vector<int> v = { 0, 5, 2, 2, 3, 1, 4, 4 };

   auto it = adjacent_find (v.begin (), v.end (), greater<> ());

   cout << "Value: " << *it << endl;
   cout << "Index: " << distance (v.begin (), it) << endl;
}

void example3 ()
{
   vector<int> v = { 0, 5, 2, 2, 3, 1, 4, 4 };

   auto it = adjacent_find (v.begin (), v.end (), less<> ());

   cout << "Value: " << *it << endl;
   cout << "Index: " << distance (v.begin (), it) << endl;
}

template <typename FwdIt>
auto adjacent_count (FwdIt first, FwdIt last) {
   auto c = 0;
   while (true) {
      first = adjacent_find (first, last);
      if (first == last) return c; 
      ++c, ++first;
   }
   return c;
}

void example4 ()
{
   vector<int> v = { 0, 5, 2, 2, 3, 1, 4, 4 };

   cout << "Count: " << adjacent_count (v.begin (), v.end ()) << endl;
}

int main () {

   example1 ();
   example2 ();
   example3 ();
   example4 ();

   return 0;
}
