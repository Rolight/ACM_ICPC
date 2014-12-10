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
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 1e5 + 10;
const int maxP = 11;

int n;
LL sum[maxn << 2],maxv[maxn << 2],val[maxn << 2];

void pushup(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    maxv[rt] = max(maxv[rt << 1],maxv[rt << 1 | 1]);
}

void build(int rt,int l,int r) {
    int mid = (l + r) >> 1;
    if(l == r) {
        sum[rt] = maxv[rt] = val[l];
    }
    else {
        build(lson); build(rson);
        pushup(rt);
    }
}

void update(int rt,int l,int r,int ql,int qr) {
    if(l == r || (ql <= l && qr >= r && maxv[rt] == 1)) {
        if(maxv[rt] == 1) return;
        sum[rt] = sqrt((double)sum[rt]);
        maxv[rt] = sum[rt];
    }
    else {
        int mid = (l + r) >> 1;
        if(ql <= mid) update(lson,ql,qr);
        if(qr > mid) update(rson,ql,qr);
        pushup(rt);
    }
}

LL query(int rt,int l,int r,int ql,int qr) {
    if(ql <= l && qr >= r) return sum[rt];
    int mid = (l + r) >> 1;
    LL ret = 0;
    if(ql <= mid) ret += query(lson,ql,qr);
    if(qr > mid) ret += query(rson,ql,qr);
    return ret;
}


int main() {
//    freopen("/tmp/input","r",stdin);
//    freopen("/tmp/output","w",stdout);
    int kase = 1;
    while(scanf("%d",&n) != EOF) {
        cout << "Case #" << kase++ << ":" << endl;
        for(int i = 1;i <= n;i++) {
            //cin >> val[i];
            scanf("%I64d",&val[i]);
        }
        build(1,1,n);
        int cmd,l,r,Q; cin >> Q;
        for(int i = 0;i < Q;i++) {
            //cin >> cmd >> l >> r;
            scanf("%d%d%d",&cmd,&l,&r);
            if(l > r) swap(l,r);
            if(cmd == 0) update(1,1,n,l,r);
            //else cout << query(1,1,n,l,r) << endl;
            else printf("%I64d\n",query(1,1,n,l,r));
        }
        printf("\n");
    }
    return 0;
}
