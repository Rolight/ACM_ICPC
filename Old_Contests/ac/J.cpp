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
const int maxn = 1e6 + 10;

struct Block {
    int pos,t;
    bool operator < (const Block &x) const {
        return t < x.t;
    }
};

struct Query {
    int id,t,ans;
};

bool cmpq1(Query q1,Query q2) {
    return q1.id < q2.id;
}

bool cmpq2(Query q1,Query q2) {
    return q1.t < q2.t;
}

int n,m,ret[maxn];
Block block[maxn];
Query q[maxn];
bool lb[maxn << 2], rb[maxn << 2];
int numseg[maxn << 2];

void build(int rt,int l,int r) {
    lb[rt] = rb[rt] = numseg[rt] = 1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(lson); build(rson);
}

void pushup(int rt,int l,int r) {
    int lc = rt << 1, rc = rt << 1 | 1;
    lb[rt] = lb[lc]; rb[rt] = rb[rc];
    numseg[rt] = numseg[lc] + numseg[rc];
    if(rb[lc] && lb[rc]) {
        numseg[rt]--;
    }
}

void update(int rt,int l,int r,int pos) {
    if(l == r) {
        lb[rt] = rb[rt] = 0;
        numseg[rt] = 0;
    }
    else {
        int mid = (l + r) >> 1;
        if(pos <= mid) update(lson,pos);
        else update(rson,pos);
        pushup(rt,l,r);
    }
} 

int main() {
    int T,kase = 1; scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        build(1,1,n);
        for(int i = 1;i <= n;i++) {
            scanf("%d",&block[i].t);
            block[i].pos = i;
        }
        for(int i = 1;i <= m;i++) {
            scanf("%d",&q[i].t);
            q[i].id = i;
        }
        sort(block + 1, block + 1 + n);
        sort(q + 1,q + 1 + m,cmpq2);
        for(int i = 1, j = 1;i <= m;i++) {
            while(block[j].t <= q[i].t && j <= n) {
                update(1,1,n,block[j].pos);
                j++;
            }
            q[i].ans = numseg[1];
        }
        sort(q + 1,q + 1 + m,cmpq1);
        printf("Case #%d:",kase++);
        for(int i = 1;i <= m;i++) {
            printf(" %d",q[i].ans);
        }
        puts("");
    }
    return 0;
}
