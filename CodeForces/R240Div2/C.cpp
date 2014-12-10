#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <sstream>
#include <numeric>
#include <fstream>
#include <functional>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
LL n,k,lim;
set<LL> st;
vector<LL> ans;
VI pm;
bool vis[3000000 + 5];

void init() {
    for(int i = 2;i <= 3000000;i++) if(!vis[i]) {
        pm.PB(i);
        for(int j = i + i;j <= 3000000;j += i) vis[j] = true;
    }
}

void solve() {
    if(n == 1) {
        if(k == 0) puts("1");
        else puts("-1"); 
        return;
    }
    int pos = 0;
    LL pp = k / lim,cc = k;
    cout << "pp:" << pp << endl;
    for(int i = 0;i < lim;i++) {
        if(i == lim - 1) pp = cc;
        LL a;
        while(st.count(a = pm[pos] * pp)) pos++;
        st.insert(a); ans.PB(a); pos++;
        while(st.count(a = pm[pos] * pp)) pos++;
        st.insert(a); ans.PB(a); pos++;
        cc -= pp;
    }
    if(n & 1) {
        while(st.count(pm[pos])) pos++;
        ans.PB(pm[pos]);
    }
    /*
    int mm = ans.size();
    for(int i = 0;i < mm;i++) {
        if(i) putchar(' ');
        cout << ans[i];
    }
    cout << endl;
    */
}

int main() {
    init();
    cin >> n >> k;
    lim = n / 2;
    if(k < lim) puts("-1");
    else {
        solve();
    }
    return 0;
}
