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
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 300000 + 5;
int lazy[maxn << 2];
int l[maxn],r[maxn],x[maxn];

void update(int rt,int l,int r,int ql,int qr,int v) {
    if(ql <= l && qr >= r) {
        lazy[rt] = v; return;
    }
    int mid = (l + r) / 2;
    if(lazy[rt] != -1) lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt],lazy[rt] = -1;
    if(ql <= mid) update(rt<<1,l,mid,ql,qr,v);
    if(qr > mid) update(rt<<1|1,mid + 1,r,ql,qr,v);
}

int query(int rt,int l,int r,int q) {
    if(l == r) return lazy[rt];
    int mid = (l + r) / 2;
    if(lazy[rt] != -1) lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt],lazy[rt] = -1;
    if(q <= mid) return query(rt<<1,l,mid,q);
    else return query(rt<<1|1,mid + 1,r,q);
}

int main() {
    memset(lazy,-1,sizeof(lazy));
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++) scanf("%d%d%d",&l[i],&r[i],&x[i]);
    for(int i = m - 1;i >= 0;i--) {
        if(x[i] > l[i]) update(1,1,n,l[i],x[i] - 1,x[i]);
        if(x[i] < r[i]) update(1,1,n,x[i] + 1,r[i],x[i]);
    }
    for(int i = 1;i <= n;i++) {
        if(i > 1) putchar(' ');
        int ret = query(1,1,n,i);
        if(ret == -1) printf("0");
        else printf("%d",ret);
    }
    putchar('\n');
    return 0;
}
