#include <cstdio>
#include <cstring>
#include <cmath>
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

using namespace std;

typedef long long LL;
const int maxn = (1 << 19) + 5;
int val[maxn],dep[maxn],N;

int update(int rt,int l,int r,int p,int b,int d) {
    if(l == r) {
        val[rt] = b;
        return val[rt];
    }
    int mid = (l + r) >> 1,left,right;
    if(p <= mid) left = update(rt << 1,l,mid,p,b,d - 1),right = val[rt<<1|1];
    else right = update(rt<<1|1,mid + 1,r,p,b,d - 1),left = val[rt<<1];
    if(d % 2 == 1) val[rt] = left | right;
    else val[rt] = left ^ right;
    return val[rt];
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    N = (1 << n);
    for(int i = 1;i <= N;i++) {
        int tmp; scanf("%d",&tmp);
        update(1,1,N,i,tmp,n);
    }
    for(int i = 1;i <= m;i++) {
        int pp,bb;
        scanf("%d%d",&pp,&bb);
        printf("%d\n",update(1,1,N,pp,bb,n));
    }
    return 0;
}
