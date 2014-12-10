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
const double eps = 1e-4;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 1e5 + 5;

struct Seg {
    double x,l,r;
    int cover;
    Seg(double x,double l,double r,int cover): x(x),l(l),r(r),cover(cover) {}
    bool operator < (const Seg &s) const {
        return x < s.x;
    }
};

vector<Seg> s;
vector<double> numy;
LL lazy[maxn << 2],maxv[maxn << 2];
int W,H,n;

void add_line(int x,int y,int cover) {
    double x1 = x - W + eps, x2 = x - eps, y1 = y - H + eps, y2 = y - eps;
    s.PB(Seg(x1,y1,y2,cover));
    s.PB(Seg(x2,y1,y2,-cover));
    numy.PB(y1); numy.PB(y2);
}

int getID(double Val) {
    return lower_bound(numy.begin(),numy.end(),Val) - numy.begin();
}

void pushdown(int rt,int l,int r) {
    if(lazy[rt] == 0) return;
    int lc = rt << 1,rc = rt << 1 | 1;
    lazy[lc] += lazy[rt]; lazy[rc] += lazy[rt];
    maxv[lc] += lazy[rt]; maxv[rc] += lazy[rt];
    lazy[rt] = 0;
}

void pushup(int rt,int l,int r) {
    maxv[rt] = max(maxv[rt << 1] ,maxv[rt << 1 | 1]);
}

void update(int rt,int l,int r,int ql,int qr,int Val) {
    if(ql <= l && qr >= r) {
        lazy[rt] += Val;  maxv[rt] += Val;
    }
    else {
        pushdown(rt,l,r);
        int mid = (l + r) >> 1;
        if(ql <= mid) update(lson,ql,qr,Val);
        if(qr > mid) update(rson,ql,qr,Val);
        pushup(rt,l,r);
    }
}

void solve() {
    sort(numy.begin(),numy.end());
    sort(s.begin(),s.end());
    int ks = s.size(), ky = numy.size();
    LL ans = 0;
    for(int i = 0;i < ks;i++) {
        int ql = getID(s[i].l),qr = getID(s[i].r);
        update(1,0,ky - 1,ql,qr,s[i].cover);
        ans = max(ans,maxv[1]);
    }
    cout << ans << endl;
}

int main() {
    while(scanf("%d%d%d",&n,&W,&H) != EOF) {
        numy.clear(); s.clear();
        for(int i = 0;i < n;i++) {
            int x,y,cover; scanf("%d%d%d",&x,&y,&cover);
            add_line(x,y,cover);
        }
        solve();
    }
    return 0;
}
