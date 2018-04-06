// code_report
// 

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

int main () {
    
    // How to find the anagrams of a word 

    unordered_set<string> dictionary = { "stop","pots","tops","opts","post","spot" };

    string word = "stop";

    sort (word.begin (), word.end ());

    do {
        cout << word << (dictionary.count (word) ? " IS A WORD!\n" : "\n");
    } while (next_permutation (word.begin (), word.end ()));

    return 0;
}
