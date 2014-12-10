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
const int maxn = 5e4 + 10;
const int maxv = 1e6 + 10;
const int maxq = 2e5 + 10;

struct Seg {
    int l,r,id; LL ans;
    Seg(int l = 0,int r = 0,int id = 0): l(l),r(r),id(id) {}
};

int last[maxv],n,m,val[maxn];
LL C[maxn];
Seg q[maxq];

bool cmp(const Seg &a,const Seg &b) {
    if(a.r == b.r) return a.l < b.l;
    return a.r < b.r;
}

bool cmp1(const Seg &a,const Seg &b) {
    return a.id < b.id;
}

inline int lowbit(int x) {
    return x & -x;
}

inline void addv(int pos,LL v) {
    while(pos <= n) {
        C[pos] += v; pos += lowbit(pos);
    }
}

inline LL ask_(int pos) {
    LL ret = 0;
    while(pos > 0) {
        ret += C[pos]; pos -= lowbit(pos);
    }
    return ret;
}

inline LL ask(int l,int r) {
    return ask_(r) - ask_(l - 1);
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        memset(C,0,sizeof(C));
        memset(last,-1,sizeof(last));
        scanf("%d",&n);
        for(int i = 1;i <= n;i++) scanf("%d",&val[i]);
        scanf("%d",&m);
        for(int i = 0;i < m;i++) {
            scanf("%d%d",&q[i].l,&q[i].r);
            q[i].id = i;
        }
        sort(q,q + m,cmp);
        int npos = 1;
        for(int i = 0;i < m;i++) {
            while(npos <= q[i].r) {
                if(~last[val[npos]]) addv(last[val[npos]],-val[npos]);
                last[val[npos]] = npos;
                addv(npos,val[npos]);
                npos++;
            }
            q[i].ans = ask(q[i].l,q[i].r);
        }
        sort(q,q + m,cmp1);
        for(int i = 0;i < m;i++) {
            printf("%I64d\n",q[i].ans);
        }
    }
    return 0;
}
