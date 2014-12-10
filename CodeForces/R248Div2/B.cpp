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
const int maxn = 100000 + 5;
LL u[maxn],v[maxn];
LL Cu[maxn],Cv[maxn];
int n;

inline int lowbit(int x) {
    return x & -x;
}

inline void add(int x,int v,LL *C) {
    while(x <= n) {
        C[x] += v;
        x += lowbit(x);
    }
}

inline LL query(int x,LL *C)  {
    LL ret = 0;
    while(x > 0) {
        ret += C[x]; x -= lowbit(x);
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i = 1;i <= n;i++) {
        scanf("%d",&v[i]);
        u[i] = v[i];
    }
    sort(u + 1,u + 1 + n);
    for(int i = 1;i <= n;i++) {
        add(i,u[i],Cu);
        add(i,v[i],Cv);
    }
    int m;
    cin >> m;
    for(int i = 1;i <= m;i++) {
        int cmd,l,r;
        scanf("%d%d%d",&cmd,&l,&r);
        if(cmd == 1) cout << (query(r,Cv) - query(l - 1,Cv)) << endl;
        else cout << (query(r,Cu) - query(l - 1,Cu)) << endl;
    }
    return 0;
}
