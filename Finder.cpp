#include "Finder.h"
using namespace std;

static vector<int> prefix_function(const string& s){
    int n = (int)s.size();
    vector<int> pi(n,0);
    for(int i=1;i<n;i++){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j]) j = pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi;
}

vector<int> Finder::findSubstrings(string s1, string s2) {
    int n = (int)s1.size(), m = (int)s2.size();
    vector<int> ans(m, -1);
    if(m==0) return ans;
    vector<int> pi = prefix_function(s2);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s1[i] != s2[j]) j = pi[j-1];
        if (s1[i] == s2[j]) j++;
        int t = j;
        while (t > 0 && ans[t-1] == -1) {
            ans[t-1] = i - t + 1;
            t = pi[t-1];
        }
        if (j == m) j = pi[j-1];
    }
    return ans;
}
