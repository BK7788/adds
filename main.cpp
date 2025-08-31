#include "Finder.h"
#include <iostream>
using namespace std;

int main() {
    Finder f;
    string s1 = "abcde";
    string s2 = "ace";

    vector<int> res = f.findSubstrings(s1, s2);

    for (int pos : res) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}
