#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>

#define lson rt<<1,l,mid
#define rson rt<<1|1,mid + 1,r

using namespace std;

typedef long long LL;
const int maxn = 100000 + 5;

int sum[maxn << 2],lazy[maxn << 2];

void build(int rt,int l,int r) {
    if(l == r) {
        lazy[rt] = 0; sum[rt] = 1;
    } else {
        int mid = (l + r) >> 1;
        build(lson); build(rson);
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
        lazy[rt] = 0;
    }
}

void update(int rt,int l,int r,int ql,int qr,int x) {
    if(ql <= l && qr >= r) {
        lazy[rt] = x;
        sum[rt] = (r - l + 1) * x;
    } else {
        int mid = (l + r) >> 1;
        if(lazy[rt]) {
            lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
            sum[rt<<1] = lazy[rt<<1] * (mid - l + 1);
            sum[rt<<1|1] = lazy[rt<<1|1] * (r - mid);
            lazy[rt] = 0;
        }
        if(qr <= mid) update(lson,ql,qr,x);
        else if(ql > mid) update(rson,ql,qr,x);
        else update(lson,ql,qr,x),update(rson,ql,qr,x);
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    }
}


int main() {
    int T,N,X; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        scanf("%d%d",&N,&X);
        build(1,1,N);
        for(int i = 1;i <= X;i++) {
            int ql,qr,x; scanf("%d%d%d",&ql,&qr,&x);
            update(1,1,N,ql,qr,x);
        }
        printf("Case %d: The total value of the hook is %d.\n",kase,sum[1]);
    }
    return 0;
}
