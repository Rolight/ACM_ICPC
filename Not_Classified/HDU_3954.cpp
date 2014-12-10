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
const int maxn = 1e4 + 50;
const int maxk = 15;

int lazy[maxn << 2], min_need[maxn << 2], max_exp[maxn << 2], max_level[maxn << 2];
int need_exp[maxk], N, M, K;

int count_exp(int exp,int level) {
    int tar = need_exp[level + 1],ret = (tar - exp) / level;
    if((tar - exp) % level != 0) ret++;
    return ret;
}

void pushup(int rt) {
    int lc = rt << 1, rc = rt << 1 | 1;
    max_level[rt] = max(max_level[lc], max_level[rc]);
    max_exp[rt] = max(max_exp[lc], max_exp[rc]);
    min_need[rt] = min(min_need[lc], min_need[rc]);
}

void pushdown(int rt) {
    if(lazy[rt] == 0) return;
    int lc = rt << 1, rc = rt << 1 | 1;
    lazy[lc] += lazy[rt]; lazy[rc] += lazy[rt];
    min_need[lc] -= lazy[rt]; min_need[rc] -= lazy[rt];
    max_exp[lc] += lazy[rt] * max_level[lc];
    max_exp[rc] += lazy[rt] * max_level[rc];
    lazy[rt] = 0;
}

void build(int rt,int l,int r) {
    lazy[rt] = 0;
    if(l == r) {
        max_exp[rt] = 0;
        max_level[rt] = 1;
        min_need[rt] = need_exp[2];
    }
    else {
        int mid = (l + r) >> 1;
        build(lson); build(rson);
        pushup(rt);
    }
}

//升级操作
void level_up(int rt) {
    while(max_exp[rt] >= need_exp[max_level[rt] + 1]) max_level[rt]++;
    min_need[rt] = count_exp(max_exp[rt],max_level[rt]);
}

void update(int rt,int l,int r,int ql,int qr,int Val) {
    int mid = (l + r) >> 1;
    if(ql <= l && qr >= r) {
        lazy[rt] += Val; min_need[rt] -= Val;
        max_exp[rt] += max_level[rt] * Val;
        if(min_need[rt] <= 0) {
            if(l == r) level_up(rt);
            else {
                pushdown(rt);
                update(lson,ql,qr,0);
                update(rson,ql,qr,0);
                pushup(rt);
            }
        }
    }
    else {
        pushdown(rt);
        if(ql <= mid) update(lson,ql,qr,Val);
        if(qr > mid) update(rson,ql,qr,Val);
        pushup(rt);
    }
}

int query(int rt,int l,int r,int ql,int qr) {
    if(ql <= l && qr >= r) return max_exp[rt];
    int mid = (l + r) >> 1, ret = -1;
    pushdown(rt);
    if(ql <= mid) ret = max(ret, query(lson, ql, qr));
    if(qr > mid) ret = max(ret, query(rson, ql, qr));
    return ret;
}


int main() {
    int T; scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        char cmd[3];
        int l,r,val;
        printf("Case %d:\n",kase);
        scanf("%d%d%d",&N,&K,&M);
        for(int i = 2;i <= K;i++) scanf("%d",&need_exp[i]);
        need_exp[K + 1] = INT_MAX;
        build(1,1,N);
        for(int i = 1;i <= M;i++) {
            scanf("%s",cmd);
            if(cmd[0] == 'W') {
                scanf("%d%d%d", &l, &r, &val);
                update(1, 1, N, l, r, val);
            }
            else {
                scanf("%d%d",&l,&r);
                printf("%d\n",query(1, 1, N, l, r));
            }
        }
        puts("");
    }
    return 0;
}
