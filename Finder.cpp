#include "Finder.h"

static std::vector<int> prefix_function(const std::string& s){
    int n = (int)s.size();
    std::vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}


std::vector<int> Finder::findSubstrings(const std::string& s1, const std::string& s2) {
    const int n = (int)s1.size();
    const int m = (int)s2.size();
    std::vector<int> ans(m, -1);
    if (m == 0 || n == 0) return ans;

    std::vector<int> pi = prefix_function(s2);
    int j = 0;

    for (int i = 0; i < n; ++i) {
        while (j > 0 && s1[i] != s2[j]) j = pi[j - 1];
        if (s1[i] == s2[j]) ++j;

        
        int t = j;
        while (t > 0 && ans[t - 1] == -1) {
            ans[t - 1] = i - t + 1;
            t = pi[t - 1];
        }
        if (j == m) j = pi[j - 1];
    }
    return ans;
}
