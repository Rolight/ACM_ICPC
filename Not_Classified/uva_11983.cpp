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
const int maxn = 3e4 + 20;

struct Seg {
    int x,l,r,cover;
    Seg(int x,int l,int r,int cover): x(x),l(l),r(r),cover(cover) {}
    bool operator < (const Seg &s) const {
        return x < s.x;
    }
};

int cnt[maxn << 4],sum[maxn << 4][11];
VI numy;
vector<Seg> seg;
int n,k;

void pushup(int rt,int l,int r) {
    int lc = rt << 1, rc = rt << 1 | 1;
    if(cnt[rt] >= k) {
        sum[rt][k] = numy[r + 1] - numy[l];
        for(int i = 1;i < k;i++) sum[rt][i] = 0;
    }
    else if(cnt[rt] == 0) {
        for(int i = 1;i <= k;i++) sum[rt][i] = sum[lc][i] + sum[rc][i];
    }
    else {
        int nowsum = 0;
        for(int i = k;i >= 1;i--) {
            if(i < cnt[rt]) sum[rt][i] = 0;
            else if(i == cnt[rt]) sum[rt][i] = numy[r + 1] - numy[l] - nowsum;
            else {
                sum[rt][i] = 0;
                for(int j = 1;j <= i;j++) if(j + cnt[rt] >= i) {
                    if(i == k) sum[rt][i] += sum[lc][j] + sum[rc][j];
                    else if(j + cnt[rt] == i) sum[rt][i] += sum[lc][j] + sum[rc][j];
                }
                nowsum += sum[rt][i];
            }
        }
    }
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

int getID(int Val) {
    return lower_bound(numy.begin(),numy.end(),Val) - numy.begin();
}

int main() {
    int T,x1,y1,x2,y2; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        scanf("%d%d",&n,&k);
        numy.clear(); seg.clear();
        for(int i = 0;i < n;i++) {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            seg.PB(Seg(x1,y1,y2 + 1,1));
            seg.PB(Seg(x2 + 1,y1,y2 + 1,-1));
            numy.PB(y1); numy.PB(y2 + 1);
        }
        sort(numy.begin(),numy.end());
        sort(seg.begin(),seg.end());
        numy.erase(unique(numy.begin(),numy.end()),numy.end());
        int ks = seg.size(), ky = numy.size();
        LL ans = 0;
        for(int i = 0;i < ks;i++) {
            int ql = getID(seg[i].l), qr = getID(seg[i].r) - 1;
            update(1,0,ky - 1,ql,qr,seg[i].cover);
            if(i < ks - 1) {
                ans += 1LL * (seg[i + 1].x - seg[i].x) * sum[1][k];
            }
        }
        cout << "Case " << kase << ": " << ans << endl;
    }
    return 0;
}
