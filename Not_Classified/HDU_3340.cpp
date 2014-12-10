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
const int maxn = 25000 + 10;
const int maxv = maxn * 10;

VI numx;
vector<pii> rpoint[maxn];
char cmd[maxn];
int ql[maxn],qr[maxn],n,cnt[maxn];
double lbd[maxv << 2], rbd[maxv << 2], sum[maxv << 2];
int len[maxv << 2],knumx;

int getID(int Val) {
    return lower_bound(numx.begin(),numx.end(),Val) - numx.begin();
}

void input() {
    int nx,ny;
    numx.clear();
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf(" %c",&cmd[i]);
        if(cmd[i] == 'Q') {
            scanf("%d%d",&ql[i],&qr[i]);
            numx.PB(ql[i]); numx.PB(qr[i]);
        }
        else {
            scanf("%d",&cnt[i]);
            rpoint[i].clear();
            for(int j = 0;j < cnt[i];j++) {
                scanf("%d%d",&nx,&ny);
                rpoint[i].PB(MP(nx,ny));
                numx.PB(nx);
            }
        }
    }
    sort(numx.begin(),numx.end());
    numx.erase(unique(numx.begin(),numx.end()),numx.end());
}

void pushup(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void pushdown(int rt) {
    int lc = rt << 1, rc = rt << 1 | 1;
    double mid = lbd[rt] + (rbd[rt] - lbd[rt]) * len[lc] / len[rt];
    lbd[lc] += lbd[rt]; rbd[lc] += mid;
    lbd[rc] += mid; rbd[rc] += rbd[rt];
    sum[lc] += (lbd[rt] + mid) * len[lc] / 2;
    sum[rc] += (mid + rbd[rt]) * len[rc] / 2;
    lbd[rt] = rbd[rt] = 0;
}

void build(int rt,int l,int r) {
    len[rt] = numx[r + 1] - numx[l];
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(lson); build(rson);
}

void update(int rt,int l,int r,int ql,int qr,double ld,double rd) {
    if(ql == l && qr == r) {
        lbd[rt] += ld; rbd[rt] += rd; sum[rt] += (ld + rd) * len[rt] / 2;
    }
    else {
        pushdown(rt);
        int mid = (l + r) >> 1;
        if(qr <= mid) update(lson,ql,qr,ld,rd);
        else if(ql > mid) update(rson,ql,qr,ld,rd);
        else {
            double midv = ld + (rd - ld) * (numx[mid + 1] - numx[ql]) / (numx[qr + 1] - numx[ql]);
            update(lson,ql,mid,ld,midv);
            update(rson,mid + 1,qr,midv,rd);
        }
        pushup(rt);
    }
}

double query(int rt,int l,int r,int ql,int qr) {
    if(ql <= l && qr >= r) return sum[rt];
    else {
        int mid = (l + r) >> 1; double ret = 0;
        pushdown(rt);
        if(ql <= mid) ret += query(lson,ql,qr);
        if(qr > mid) ret += query(rson,ql,qr);
        return ret;
    }
}

void Handle(vector<pii> &sp,int cnt) {
    sp.PB(sp[0]);
    for(int i = 0;i < cnt;i++) {
        pii now = sp[i], nxt = sp[i + 1];
        if(now.first < nxt.first) {
            int x1 = getID(now.first), x2 = getID(nxt.first) - 1;
            update(1,0,knumx - 1,x1,x2,-now.second,-nxt.second);
        }
        if(now.first > nxt.first) {
            int x1 = getID(nxt.first), x2 = getID(now.first) - 1;
            update(1,0,knumx - 1,x1,x2,nxt.second,now.second);
        }
    }
}

void solve() {
    knumx = numx.size() - 1;
    build(1,0,knumx - 1);
    memset(lbd,0,sizeof(lbd));
    memset(rbd,0,sizeof(rbd));
    memset(sum,0,sizeof(sum));
    for(int i = 1;i <= n;i++) {
        if(cmd[i] == 'Q') {
            int x1 = getID(ql[i]), x2 = getID(qr[i]) - 1;
            printf("%.3f\n",query(1,0,knumx - 1,x1,x2));
        }
        else Handle(rpoint[i],cnt[i]);
    }
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        input();
        solve();
    }
    return 0;
}
