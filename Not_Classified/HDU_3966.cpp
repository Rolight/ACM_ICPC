#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <algorithm>

#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

using namespace std;

const int maxn = 5e4 + 10;

int head[maxn], nxt[maxn << 1], v[maxn << 1], ecnt;
int N, M, P, sval[maxn], tcnt, Rank[maxn];
int siz[maxn], top[maxn], son[maxn], dep[maxn], tid[maxn], fa[maxn];
int lazy[maxn << 2], val[maxn << 2];

void init() {
    memset(head, -1, sizeof(head));
    ecnt = tcnt = 0;
}

void add_edge(int uu, int vv) {
    v[ecnt] = vv; nxt[ecnt] = head[uu]; head[uu] = ecnt++;
}

void dfs1(int now, int f, int now_dep) {
    siz[now] = 1; son[now] = -1; dep[now] = now_dep; fa[now] = f;
    for(int i = head[now]; ~i; i = nxt[i]) if(v[i] != f) {
        dfs1(v[i], now, now_dep + 1);
        siz[now] += siz[v[i]];
        if(son[now] == -1 || siz[v[i]] > siz[son[now]]) {
            son[now] = v[i];
        }
    }
}

//tp 是当前链顶点的编号
void dfs2(int now, int tp) {
    top[now] = tp; tid[now] = ++tcnt; Rank[tid[now]] = now;
    if(siz[now] == 1) return;
    dfs2(son[now], tp);
    for(int i = head[now]; ~i; i = nxt[i]) if(v[i] != fa[now] && v[i] != son[now]) {
        dfs2(v[i], v[i]);
    }
}

void pushup(int rt) {
    val[rt] = max(val[rt << 1], val[rt << 1 | 1]);
}

void pushdown(int rt, int l, int r) {
    if(lazy[rt] == 0) return;
    int mid = l + r >> 1, lc = rt << 1, rc = rt << 1 | 1;
    lazy[lc] += lazy[rt]; lazy[rc] += lazy[rt];
    val[lc] += lazy[rt] * (mid - l + 1);
    val[rc] += lazy[rt] * (r - mid);
    lazy[rt] = 0;
}

void build(int rt, int l, int r) {
    int mid = l + r >> 1;
    lazy[rt] = 0;
    if(l == r) val[rt] = sval[Rank[l]];
    else {
        build(lson); build(rson);
        pushup(rt);
    }
}

int query(int rt, int l, int r, int x) {
    if(l == r) return val[rt];
    int mid = l + r >> 1;
    pushdown(rt, l, r);
    if(x <= mid) return query(lson, x);
    else return query(rson, x);
}

void update(int rt, int l, int r, int ql, int qr, int Val) {
    if(ql <= l && qr >= r) {
        val[rt] += Val * (r - l + 1);
        lazy[rt] += Val;
    }
    else {
        int mid = l + r >> 1;
        pushdown(rt, l, r);
        if(ql <= mid) update(lson, ql, qr, Val);
        if(qr > mid) update(rson, ql, qr, Val);
        pushup(rt);
    }
}

//树链剖分 区间修改
void Change(int x, int y, int Val) {
    while(top[x] != top[y]) {
        //先更新深度大的链
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, 1, N, tid[top[x]], tid[x], Val);
        x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    update(1, 1, N, tid[x], tid[y], Val);
}

int main() {
    while(scanf("%d%d%d", &N, &M, &P) != EOF) {
        init();
        for(int i = 1; i <= N; i++) scanf("%d", &sval[i]);
        for(int i = 0; i < M; i++) {
            int a, b; scanf("%d%d", &a, &b);
            add_edge(a, b); add_edge(b, a);
        }
        dfs1(1, 1, 1); dfs2(1, 1); build(1, 1, N);
        for(int i = 0; i < P; i++) {
            char cmd; scanf(" %c", &cmd);
            if(cmd == 'Q') {
                int pos; scanf("%d", &pos);
                printf("%d\n", query(1, 1, N, tid[pos]));
            }
            else {
                int ql, qr, Val; scanf("%d%d%d", &ql, &qr, &Val);
                if(cmd == 'D') Val = -Val;
                Change(ql, qr, Val);
            }
        }
    }
    return 0;
}
