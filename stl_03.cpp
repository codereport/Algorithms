// code_report
// https://youtu.be/ENg-CXKXzKM

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void print (T t) {
	for (const auto& e : t) cout << e << " ";
	cout << endl;
}

void reverse_example () {
	vector<int> v = { 1, 2, 3 };

	print (v); // outputs 1 2 3
	reverse (v.begin (), v.end ());
	print (v); // outputs 3 2 1

	vector<int> u (3);
	print (u); // outputs 0 0 0
	reverse_copy (v.begin (), v.end (), u.begin ());
	print (u); // outputs 1 2 3
}

void rotate_example () {
	vector<int> v = { 1, 2, 3, 4, 5 };

	print (v); // outputs 1 2 3 4 5
	rotate (v.begin (), v.begin () + 2, v.end ());
	print (v); // outputs 3 4 5 1 2

	vector<int> u (5);
	print (u); // outputs 0 0 0 0 0
	rotate_copy (v.begin (), v.begin () + 2, v.end (), u.begin ());
	print (u); // outputs 5 1 2 3 4
}

int main ()
{
	reverse_example ();
	rotate_example ();

	return 0;
}
