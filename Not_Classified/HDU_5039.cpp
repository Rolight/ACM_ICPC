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
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 3e4 + 10;
int head[maxn], nxt[maxn << 1], v[maxn << 1], w[maxn << 1], sz;
int n, m, pval[maxn], lbound[maxn], rbound[maxn], ncnt;
int sum[maxn << 2], lazy[maxn << 2];
map<string, int> name_id;
char buf1[1024], buf2[1024];
bool vis[maxn];
PII edge[maxn];

void adde(int uu, int vv, int ww) {
    w[sz] = ww; v[sz] = vv; nxt[sz] = head[uu]; head[uu] = sz++;
}

void dfs(int now, int val) {
    vis[now] = true;
    pval[++ncnt] = val; lbound[now] = ncnt;
    for(int i = head[now]; ~i; i = nxt[i]) if(!vis[v[i]]) {
        dfs(v[i], val ^ w[i]);
    }
    rbound[now] = ncnt;
}

int calc(int cnt) {
    return cnt * (n - cnt) * 2;
}

void pushup(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void seg_xor(int rt, int l, int r) {
    lazy[rt] ^= 1;
    sum[rt] = r - l + 1 - sum[rt];
}

void pushdown(int rt, int l, int r) {
    if(lazy[rt]) {
        int mid = (l + r) >> 1;
        seg_xor(lson); seg_xor(rson);
        lazy[rt] = 0;
    }
}

void build(int rt, int l, int r) {
    int mid = (l + r) >> 1;
    lazy[rt] = 0;
    if(l == r) sum[rt] = pval[l];
    else {
        build(lson); build(rson);
        pushup(rt);
    }
}

void update(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) seg_xor(rt, l, r);
    else {
        int mid = (l + r) >> 1;
        pushdown(rt, l, r);
        if(ql <= mid) update(lson, ql, qr);
        if(qr > mid) update(rson, ql, qr);
        pushup(rt);
    }
}


int main() {
    int T; scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        name_id.clear();
        sz = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%s", buf1);
            name_id[string(buf1)] = i;
            head[i] = -1;
        }
        for(int i = 1;i < n;i++) {
            int u, v, w;
            scanf("%s%s%d", buf1, buf2, &w);
            u = name_id[string(buf1)];
            v = name_id[string(buf2)];
            adde(u, v, w);
            adde(v, u, w);
            edge[i] = MP(u, v);
        }
        memset(vis, 0, sizeof(vis));
        ncnt = 0; dfs(1, 0); build(1, 1, n);
        scanf("%d", &m);
        printf("Case #%d:\n", kase);
        for(int i = 0; i < m; i++) {
            char cmd; scanf(" %c", &cmd);
            if(cmd == 'Q') printf("%d\n", calc(sum[1]));
            else {
                int eid; scanf("%d", &eid);
                int u = edge[eid].first, v = edge[eid].second;
                if(lbound[u] < lbound[v]) swap(u, v);
                int ql = lbound[u], qr = rbound[u];
                update(1, 1, n, ql, qr);
            }
        }
    }
    return 0;
}
