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
#define lson rt << 1,l,mid
#define rson rt << 1 | 1,mid + 1,r
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 1e5 + 10;

struct Plank {
    int h,l,r,power;
    Plank(int h,int l,int r,int power): h(h),l(l),r(r),power(power) {}
    bool operator < (const Plank &p) const {
        return h < p.h;
    }
};

vector<Plank> plank;
int n,Val[maxn << 2],lazy[maxn << 2];
LL f[maxn];

void pushdown(int rt) {
    if(lazy[rt] == -1) return;
    Val[rt << 1] = Val[rt << 1 | 1] = 
        lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
    lazy[rt] = -1;
}

void update(int rt,int l,int r,int ql,int qr,int v) {
    if(ql <= l && qr >= r) {
        Val[rt] = v; lazy[rt] = v;
    }
    else {
        int mid = (l + r) >> 1;
        pushdown(rt);
        if(ql <= mid) update(lson,ql,qr,v);
        if(qr > mid) update(rson,ql,qr,v);
    }
}

int query(int rt,int l,int r,int pos) {
    if(l == r) return Val[rt];
    pushdown(rt);
    int mid = (l + r) >> 1;
    if(pos <= mid) return query(lson,pos);
    else return query(rson,pos);
}


int main() {
    int h,l,r,power,rb;
    while(scanf("%d",&n) != EOF) {
        plank.clear(); rb = -1;
        memset(f,0,sizeof(f));
        memset(lazy,-1,sizeof(lazy));
        for(int i = 0;i < n;i++) {
            scanf("%d%d%d%d",&h,&l,&r,&power);
            plank.PB(Plank(h,l,r,power));
            rb = max(rb,r);
        }
        plank.PB(Plank(0,1,rb,0));
        sort(plank.begin(),plank.end());
        update(1,1,rb,1,rb,0);
        for(int i = 1;i <= n;i++) {
            int xl = query(1,1,rb,plank[i].l),
                xr = query(1,1,rb,plank[i].r);
            f[i] = max(f[xl],f[xr]) + plank[i].power;
            update(1,1,rb,plank[i].l,plank[i].r,i);
        }
        LL ans = f[n] + 100; ans = max(ans,-1LL);
        cout << ans << endl;
    }
    return 0;
}
