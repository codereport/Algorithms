// code_report
// https://youtu.be/oNnatJtPWjI

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <iterator>

using namespace std;

template <typename T>
void print (const T& a) {
   for (const auto& e : a) cout << e << ' ';
   cout << endl;
}

template <typename T>
void print_map (const T& m) {
   for (const auto& e : m) cout << e.first << "," << e.second << ' ';
   cout << endl;
}

   void example_vector () 
   {
      vector<int> v1 = { 0, 1, 2, 3, 4, 5 };
      vector<int> v2 = {             4, 5, 6, 7 ,8 ,9 };

      vector<int> v3, v4, v5, v6;

      set_union                (v1.begin (), v1.end (), v2.begin (), v2.end (), back_inserter (v3));
      set_intersection         (v1.begin (), v1.end (), v2.begin (), v2.end (), back_inserter (v4));
      set_difference           (v1.begin (), v1.end (), v2.begin (), v2.end (), back_inserter (v5));
      set_symmetric_difference (v1.begin (), v1.end (), v2.begin (), v2.end (), back_inserter (v6));

      cout << "set_union:                "; print (v3);
      cout << "set_intersection:         "; print (v4);
      cout << "set_difference:           "; print (v5);
      cout << "set_symmetric_difference: "; print (v6);
      cout << endl;
   }

void example_set () 
{
   set<int> s1 = { 0, 1, 2, 3, 4, 5 };
   set<int> s2 = {             4, 5, 6, 7 ,8 ,9 };

   set<int> s3, s4, s5, s6;

   set_union                (s1.begin (), s1.end (), s2.begin (), s2.end (), inserter (s3, s3.end ()));
   set_intersection         (s1.begin (), s1.end (), s2.begin (), s2.end (), inserter (s4, s4.end ()));
   set_difference           (s1.begin (), s1.end (), s2.begin (), s2.end (), inserter (s5, s5.end ()));
   set_symmetric_difference (s1.begin (), s1.end (), s2.begin (), s2.end (), inserter (s6, s6.end ()));

   cout << "set_union:                "; print (s3);
   cout << "set_intersection:         "; print (s4);
   cout << "set_difference:           "; print (s5);
   cout << "set_symmetric_difference: "; print (s6);
   cout << endl;
}

void example_map ()
{
   map<int, int> m1 = { { 1, 1 }, { 2, 2 }, { 3, 3 } };
   map<int, int> m2 = { { 1, 2 }, { 2, 4 }, { 3, 3 } };

   map<int, int> m3, m4, m5, m6;

   set_union                (m1.begin (), m1.end (), m2.begin (), m2.end (), inserter (m3, m3.end ()));
   set_intersection         (m1.begin (), m1.end (), m2.begin (), m2.end (), inserter (m4, m4.end ()));
   set_difference           (m1.begin (), m1.end (), m2.begin (), m2.end (), inserter (m5, m5.end ()));
   set_symmetric_difference (m1.begin (), m1.end (), m2.begin (), m2.end (), inserter (m6, m6.end ()));

   cout << "set_union:                "; print_map (m3);
   cout << "set_intersection:         "; print_map (m4);
   cout << "set_difference:           "; print_map (m5);
   cout << "set_symmetric_difference: "; print_map (m6);
   cout << endl;
}

int main () {

   example_vector ();
   example_set ();
   example_map ();

   return 0;
}
