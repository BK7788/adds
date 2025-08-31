#include "Finder.h"
using std::string; using std::vector;

static vector<int> zfunc(const string& s){
    int n=(int)s.size(); vector<int> z(n); int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i<=r) z[i]=std::min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
        if(i+z[i]-1>r){ l=i; r=i+z[i]-1; }
    }
    return z;
}

struct DSU {
    vector<int> p;
    DSU(int n):p(n+2){ for(int i=0;i<=n+1;i++) p[i]=i; }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    void erase(int x){ p[x]=x+1; }
};

std::vector<int> Finder::findSubstrings(const string& s1, const string& s2) {
    int n=(int)s1.size(), m=(int)s2.size();
    vector<int> ans(m,-1);
    if(n==0 || m==0) return ans;

    string comb; comb.reserve(m+1+n);
    comb.append(s2); comb.push_back('\1'); comb.append(s1);
    vector<int> z = zfunc(comb);

    DSU dsu(m);
    int off = m+1;
    for(int i=0;i<n;i++){
        int L = z[off+i];
        if(L<=0) continue;
        int k = dsu.find(1);
        while(k<=L){
            ans[k-1]=i;
            dsu.erase(k);
            k = dsu.find(k);
        }
        if(dsu.find(1)>m) break;
    }
    return ans;
}
