// code_report
// https://youtu.be/pYa18zlOQsc

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main () 
{
   vector<string> words = { "Cat", "Dog", "123" };

   for (const auto& word : words) {
      cout << word << " is "
           << (all_of (word.begin (), word.end (), isdigit) ? "" : "NOT ") 
           << "a number.\n";
   }

    /*DON'T DO THIS:

   vector<int> v = { 1, 2, 3 };

   bool none_even = true;
   for (auto e : v) {
      if (e % 2 == 0) {
         none_even = false;
         break;
      }
   } */

   // DO THIS:

   vector<int> v = { 1, 2, 3 };

   auto is_even = [](auto n) { return n % 2 == 0; };
   bool none_even = none_of (v.begin (), v.end (), is_even);

   return 0;
}

