#include "Finder.h"
using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    for (size_t i = 1; i <= s2.size(); i++) {
        string prefix = s2.substr(0, i);
        size_t pos = s1.find(prefix);
        result.push_back(pos == string::npos ? -1 : (int)pos);
    }
    return result;
}
