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
const int maxn = 1e5 + 10;
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid + 1,r
LL sum[maxn << 2],lazy[maxn << 2],val[maxn];
int N,Q;

void build(int rt,int l,int r) {
    if(l == r) sum[rt] = val[l];
    else {
        int mid = (l + r) >> 1;
        build(lson); build(rson);
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    }
}

inline void pushdown(int rt,int l,int r) {
    int lc = rt<<1,rc = rt<<1|1,mid = (l + r) / 2;
    lazy[lc] += lazy[rt]; lazy[rc] += lazy[rt];
    sum[lc] += lazy[rt] * (mid - l + 1); sum[rc] += lazy[rt] * (r - mid); 
    lazy[rt] = 0;
}

void update(int rt,int l,int r,int ql,int qr,LL v) {
    int lc = rt<<1,rc = rt<<1|1;
    if(ql <= l && qr >= r) {
        lazy[rt] += v; sum[rt] += v * (r - l + 1);
    }
    else {
        int mid = (l + r) >> 1;
        if(lazy[rt] != 0) pushdown(rt,l,r);
        if(ql <= mid) update(lson,ql,qr,v);
        if(qr > mid) update(rson,ql,qr,v);
        sum[rt] = sum[lc] + sum[rc];
    }
}

LL query(int rt,int l,int r,int ql,int qr) {
    int lc = rt<<1,rc = rt<<1|1,mid = (l + r) >> 1;
    if(ql <= l && qr >= r) return sum[rt];
    LL ret = 0;
    if(lazy[rt] != 0) pushdown(rt,l,r);
    if(ql <= mid) ret += query(lson,ql,qr);
    if(qr > mid) ret += query(rson,ql,qr);
    return ret;
}

int main() {
    while(scanf("%d%d",&N,&Q) != EOF) {
        memset(lazy,0,sizeof(lazy));
        for(int i = 1;i <= N;i++) scanf("%lld",&val[i]);
        build(1,1,N);
        char cmd[5]; LL a,b,c;
        for(int i = 0;i < Q;i++) {
            scanf("%s%lld%lld",cmd,&a,&b);
            if(cmd[0] == 'Q') cout << query(1,1,N,a,b) << endl;
            else {
                scanf("%lld",&c);
                update(1,1,N,a,b,c);
            }
        }
    }
    return 0;
}
