// code_report
// https://youtu.be/_dC6Pvk0awA


#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template<typename T>
void print (T t) {
	for (const auto& e : t) cout << e << " ";
	cout << endl;
}

void example1 () {
	vector<int> v = { 2,3,4,1 };

	print (v); // outputs 2 3 4 1
	sort (v.begin (), v.end ());
	print (v); // outputs 1 2 3 4
}

void example2 () {
	vector<int> v = { 3,2,1,4 };

	print (v); // outputs 3 2 1 4
	sort (v.begin (), v.begin () + 2);
	print (v); // outputs 2 3 1 4 
}

void example3 () {
	vector<string> v = { "mouse", "dog", "cat", "ant", "moth", "elephant" };

	print (v); // outputs mouse dog cat ant moth elephant
	sort (v.begin (), v.end ());
	print (v); // outputs ant cat dog elephant moth mouse 
}

void example4 () {
	vector<string> v = { "mouse", "dog", "cat", "ant", "moth", "elephant" };

	auto sortByLength = [](const auto& a, const auto& b) { return a.size () < b.size (); };

	print (v); // outputs mouse dog cat ant moth elephant
	sort (v.begin (), v.end (), sortByLength);
	print (v); // outputs ant cat dog moth mouse elephant
}

void example5 () {
	vector<string> v = { "mouse", "dog", "cat", "ant", "moth", "elephant" };

	auto sortByLength = [](const auto& a, const auto& b) { return a.size () < b.size (); };

	print (v); // outputs mouse dog cat ant moth elephant
	stable_sort (v.begin (), v.end (), sortByLength);
	print (v); // outputs dog cat ant moth mouse elephant
}


void main () {

	example1 ();
	example2 ();
	example3 ();
	example4 ();
	example5 ();

	return;
}
