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
const int maxn = 50000 + 10;
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid + 1,r
int lmax[maxn << 2],rmax[maxn << 2],lazy[maxn << 2],mmax[maxn << 2];

inline void pushup(int rt,int l,int r) {
    int lc = rt << 1,rc = rt << 1 | 1,mid = (l + r) >> 1;
    int Llen = mid - l + 1,Rlen = r - mid;
    lmax[rt] = lmax[lc]; rmax[rt] = rmax[rc];
    mmax[rt] = max(mmax[lc],mmax[rc]);
    if(rmax[lc] != 0 && lmax[rc] != 0) {
        //如果中间是连接的
        if(lmax[lc] == Llen) lmax[rt] = lmax[lc] + lmax[rc];
        if(lmax[rc] == Rlen) rmax[rt] = rmax[rc] + rmax[lc];
        mmax[rt] = max(mmax[rt],rmax[lc] + lmax[rc]);
        mmax[rt] = max(mmax[rt],lmax[rt]);
        mmax[rt] = max(mmax[rt],rmax[rt]);
    }
} 

inline void pushdown(int rt,int l,int r) {
    if(lazy[rt] == -1) return;
    int lc = rt << 1,rc = rt << 1 | 1,mid = (l + r) >> 1;
    int Llen = mid - l + 1,Rlen = r - mid;
    lazy[lc] = lazy[rc] = lazy[rt];
    lmax[lc] = rmax[lc] = mmax[lc] = lazy[rt] ? 0 : Llen;
    lmax[rc] = rmax[rc] = mmax[rc] = lazy[rt] ? 0 : Rlen;
    lazy[rt] = -1;
}

void build(int rt,int l,int r) {
    if(l == r) {
        lazy[rt] = -1;
        lmax[rt] = rmax[rt] = mmax[rt] = 1;
    }
    else {
        int mid = (l + r) >> 1;
        lazy[rt] = -1;
        build(lson); build(rson);
        pushup(rt,l,r);
    }
}

void update(int rt,int l,int r,int ql,int qr,int v) {
    int lc = rt << 1,rc = rt << 1 | 1,mid = (l + r) >> 1;
    int Llen = mid - l + 1,Rlen = r - mid;
    if(ql <= l && qr >= r) {
        lazy[rt] = v;
        lmax[rt] = rmax[rt] = mmax[rt] = v ? 0 : (r - l + 1);
    }
    else {
        pushdown(rt,l,r);
        if(ql <= mid) update(lson,ql,qr,v);
        if(qr > mid) update(rson,ql,qr,v);
        pushup(rt,l,r);
    }
}

int query(int rt,int l,int r,int D) {
    int lc = rt << 1,rc = rt << 1 | 1,mid = (l + r) >> 1;
    pushdown(rt,l,r);
    if(lmax[rt] >= D) return l;
    if(mmax[lc] >= D) return query(lson,D);
    if(rmax[lc] + lmax[rc] >= D) return mid - rmax[lc] + 1;
    return query(rson,D);
}

int main() {
    int N,M,X,D,cmd,a,b;
    while(scanf("%d%d",&N,&M) != EOF) {
        build(1,1,N);
        for(int i = 0;i < M;i++) {
            scanf("%d",&cmd);
            if(cmd == 1) {
                scanf("%d",&D);
                if(mmax[1] < D) puts("0");
                else {
                    int ret = query(1,1,N,D);
                    update(1,1,N,ret,ret + D - 1,1);
                    printf("%d\n",ret);
                }
            }
            else {
                scanf("%d%d",&a,&b);
                int r = a + b - 1; r = min(r,N);
                update(1,1,N,a,r,0);
            }
        }
    }
    return 0;
}
