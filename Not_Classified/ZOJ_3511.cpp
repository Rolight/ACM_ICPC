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
typedef pair<int,int> PII;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 1e4 + 10;

int sum[maxn << 2],n,m;
PII Q[maxn];

void build(int rt,int l,int r) {
    int mid = (l + r) >> 1;
    if(l == r) sum[rt] = 1;
    else {
        build(lson); build(rson);
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }
}

void update(int rt,int l,int r,int ql,int qr) {
    if(ql <= l && qr >= r) sum[rt] = 0;
    else {
        int mid = (l + r) >> 1, lc = rt << 1, rc = rt << 1 | 1;
        if(sum[rt] == 0) {
            sum[lc] = sum[rc] = 0;
            return;
        }
        if(ql <= mid) update(lson,ql,qr);
        if(qr > mid) update(rson,ql,qr);
        sum[rt] = sum[lc] + sum[rc];
    }
}

int query(int rt,int l,int r,int ql,int qr) {
    if(ql <= l && qr >= r) return sum[rt];
    int mid = (l + r) >> 1,ret = 0;
    if(sum[rt] == 0) return 0;
    if(ql <= mid) ret += query(lson,ql,qr);
    if(qr > mid) ret += query(rson,ql,qr);
    return ret;
} 

bool cmp(const PII &a, const PII &b) {
    return abs(a.first - a.second) < abs(b.first - b.second);
}


int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        build(1,1,n);
        int ans = 0;
        for(int i = 0;i < m;i++) {
            scanf("%d%d",&Q[i].first,&Q[i].second);
        }
        sort(Q, Q + m, cmp);
        for(int i = 0;i < m;i++) {
            int l = Q[i].first, r = Q[i].second;
            if(l > r) swap(l,r);
            ans = max(query(1,1,n,l,r),ans);
            update(1,1,n,l + 1,r - 1);
        }
        ans = max(ans,query(1,1,n,1,n));
        printf("%d\n",ans);
    }
    return 0;
}
