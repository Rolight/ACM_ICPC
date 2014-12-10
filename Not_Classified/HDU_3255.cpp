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
const int maxn = 3e4 + 10;

struct Seg {
    int x,l,r,cover;
    Seg(int x,int l,int r,int cover): x(x),l(l),r(r),cover(cover) {}
    bool operator < (const Seg &s) const {
        return x < s.x;
    }
};

int cnt[maxn << 4],len[maxn << 4],p[4];
vector<Seg> seg;
VI numy;
int n,m,px1[maxn],py1[maxn],px2[maxn],py2[maxn],pz[maxn];

int getID(int Val) {
    return lower_bound(numy.begin(),numy.end(),Val) - numy.begin();
}

void pushup(int rt,int l,int r) {
    if(cnt[rt]) len[rt] = numy[r + 1] - numy[l];
    else len[rt] = len[rt << 1] + len[rt << 1 | 1];
}

void update(int rt,int l,int r,int ql,int qr,int Val) {
    if(ql <= l && qr >= r) {
        cnt[rt] += Val; pushup(rt,l,r);
    }
    else {
        int mid = (l + r) >> 1;
        if(ql <= mid) update(lson,ql,qr,Val);
        if(qr > mid) update(rson,ql,qr,Val);
        pushup(rt,l,r);
    }
}

void solve() {
    LL ans = 0;
    int ky = numy.size();
    for(int i = 1;i <= m;i++) {
        seg.clear();
        for(int j = 0;j < n;j++) if(pz[j] > p[i - 1])  {
            seg.PB(Seg(px1[j],py1[j],py2[j],1));
            seg.PB(Seg(px2[j],py1[j],py2[j],-1));
        }
        sort(seg.begin(),seg.end());
        int ks = seg.size();
        for(int j = 0;j < ks;j++) {
            int ql = getID(seg[j].l), qr = getID(seg[j].r) - 1;
            update(1,0,ky - 1,ql,qr,seg[j].cover);
            if(j < ks - 1) ans += 1LL * (p[i] - p[i - 1]) * len[1] * (seg[j + 1].x - seg[j].x);
        }
    } 
    cout << ans << endl;
}

int main() {
    int T,kase = 1; scanf("%d",&T);
    while(T--) {
        int x1,y1,x2,y2,cover;
        numy.clear();
        scanf("%d%d",&n,&m);
        memset(p,0,sizeof(p));
        for(int i = 1;i <= m;i++) scanf("%d",&p[i]);
        for(int i = 0;i < n;i++) {
            scanf("%d%d%d%d%d",&px1[i],&py1[i],&px2[i],&py2[i],&pz[i]);
            pz[i] = p[pz[i]];
            numy.PB(py1[i]); numy.PB(py2[i]);
        }
        sort(numy.begin(),numy.end());
        sort(p + 1,p + 1 + m);
        numy.erase(unique(numy.begin(),numy.end()),numy.end());
        printf("Case %d: ",kase++);
        solve();
    }
    return 0;
}
