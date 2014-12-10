#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MP make_pair
#define PB push_back
#define lson rt << 1,l,mid
#define rson rt << 1 | 1,mid + 1,r
typedef long long LL;
typedef vector<int> VI;
const int maxn = 4004;


struct Seg {
    int x,l,r,cover;
    Seg(int x,int l,int r,int cover): x(x),l(l),r(r),cover(cover) {}
    bool operator < (const Seg &s) const {
        return x < s.x;
    }
};

VI numz,numy;
vector<Seg> s;
int n,x1[maxn],y1[maxn],z1[maxn],x2[maxn],y2[maxn],z2[maxn];
int once[maxn << 2],twice[maxn << 2],len[maxn << 2],cnt[maxn << 2];

void getPoint(int &x,int &y,int &z) {
    scanf("%d%d%d",&x,&y,&z);
}

int getID(int Val) {
    return lower_bound(numy.begin(),numy.end(),Val) - numy.begin();
}

void pushup(int rt,int l,int r) {
    int lc = rt << 1,rc = rt << 1 | 1;
    if(cnt[rt] == 0) {
        once[rt] = once[lc] + once[rc];
        twice[rt] = twice[lc] + twice[rc];
        len[rt] = len[lc] + len[rc];
    }
    else if(cnt[rt] == 1) {
        len[rt] = twice[lc] + twice[rc] + len[lc] + len[rc];
        twice[rt] = once[lc] + once[rc];
        once[rt] = numy[r + 1] - numy[l] - len[rt] - twice[rt];
    }
    else if(cnt[rt] == 2) {
        len[rt] = len[lc] + len[rc] + twice[lc] + twice[rc] + once[lc] + once[rc];
        once[rt] = 0;
        twice[rt] = numy[r + 1] - numy[l] - len[rt];
    }
    else {
        len[rt] = numy[r + 1] - numy[l];
        once[rt] = twice[rt] = 0;
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

LL solve() {
    LL ret = 0;
    int ky = numy.size(),kz = numz.size();
    for(int i = 0;i < kz - 1;i++) {
        s.clear();
        for(int j = 0;j < n;j++) if(z1[j] <= numz[i] && z2[j] >= numz[i + 1]) {
            s.PB(Seg(x1[j],y1[j],y2[j],1));
            s.PB(Seg(x2[j],y1[j],y2[j],-1));
        }
        sort(s.begin(),s.end());
        int ks = s.size(); LL nw = numz[i + 1] - numz[i];
        for(int j = 0;j < ks;j++) {
            int ql = getID(s[j].l), qr = getID(s[j].r) - 1;
            update(1,0,ky - 1,ql,qr,s[j].cover);
            if(j < ks - 1) ret += nw * (s[j + 1].x - s[j].x) * len[1];
        }
    }
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        numy.clear(); numz.clear();
        scanf("%d",&n);
        for(int i = 0;i < n;i++) {
            getPoint(x1[i],y1[i],z1[i]);
            getPoint(x2[i],y2[i],z2[i]);
            numz.PB(z1[i]); numz.PB(z2[i]);
            numy.PB(y1[i]); numy.PB(y2[i]);
        }
        sort(numz.begin(),numz.end());
        sort(numy.begin(),numy.end());
        numz.erase(unique(numz.begin(),numz.end()),numz.end());
        numy.erase(unique(numy.begin(),numy.end()),numy.end());
        printf("Case %d: ",kase);
        cout << solve() << endl;
    }
    return 0;
}
