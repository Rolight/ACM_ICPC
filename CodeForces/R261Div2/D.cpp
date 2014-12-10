#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <climits>
#include <iostream>

using namespace std;

typedef long long LL;
const int maxn = 1e6 + 10;
map<int,int> mp;
vector< pair<int,int> > gp;
int f[maxn],g[maxn],n,a[maxn];
LL C[maxn];

inline LL lowbit(LL x) {
    return x & -x;
}

void addv(LL pos,int x) {
    while(pos <= n) {
        C[pos] += x;
        pos += lowbit(pos);
    }
}

LL query(int pos) {
    LL ret = 0;
    while(pos > 0) {
        ret += C[pos]; pos -= lowbit(pos);
    }
    return ret;
}

int main() {
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    for(int i = 1;i <= n;i++) {
        mp[a[i]]++;
        f[i] = mp[a[i]];
    }
    mp.clear();
    for(int j = n;j >= 1;j--) {
        mp[a[j]]++;
        g[j] = mp[a[j]];
    }
    LL ans = 0;
    for(int i = 1;i <= n;i++) addv(g[i],1);
    for(int i = 1;i <= n;i++) {
        addv(g[i],-1);
        if(f[i] - 1 > 0) ans += query(f[i] - 1);
    }
    cout << ans << endl;
    return 0;
}


