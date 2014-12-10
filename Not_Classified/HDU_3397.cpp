#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define lson rt<<1,l,mid
#define rson rt<<1|1,mid + 1,r
const int maxn = 1e5 + 10;
int lmax[maxn << 2][2], rmax[maxn << 2][2], mmax[maxn << 2][2];
int lazy_xor[maxn << 2], lazy_cover[maxn << 2], sum[maxn << 2];
int N, M, val[maxn];

void swap(int &a, int &b) {
	int t = a; a = b; b = t;
}

void change_xor(int rt, int l, int r) {
	swap(lmax[rt][0], lmax[rt][1]);
	swap(rmax[rt][0], rmax[rt][1]);
	swap(mmax[rt][0], mmax[rt][1]);
	sum[rt] = r - l + 1 - sum[rt];
}

void change_cover(int rt, int l, int r, int Val) {
	for (int i = 0; i < 2; i++) 
		lmax[rt][i] = rmax[rt][i] = mmax[rt][i] =
			Val == i ? r - l + 1 : 0;
	sum[rt] = Val * (r - l + 1);
}

void pushup(int rt, int l, int r) {
	int lc = rt << 1, rc = rt << 1 | 1, mid = (l + r) >> 1;
	int Llen = mid - l + 1, Rlen = r - mid;
    for (int i = 0; i < 2; i++) {
        lmax[rt][i] = lmax[lc][i];  rmax[rt][i] = rmax[rc][i];
        mmax[rt][i] = max(mmax[lc][i], mmax[rc][i]);
        if (lmax[lc][i] == Llen) lmax[rt][i] += lmax[rc][i];
        if (rmax[rc][i] == Rlen) rmax[rt][i] += rmax[lc][i];
        mmax[rt][i] = max(mmax[rt][i], rmax[lc][i] + lmax[rc][i]);
    }
    sum[rt] = sum[lc] + sum[rc];
}

void pushdown_cover(int rt, int l, int r) {
    int lc = rt << 1, rc = rt << 1 | 1, mid = (l + r) >> 1;
    lazy_cover[lc] = lazy_cover[rc] = lazy_cover[rt];
    lazy_xor[lc] = lazy_xor[rc] = 0;
    change_cover(lson, lazy_cover[rt]);
    change_cover(rson, lazy_cover[rt]);
    lazy_cover[rt] = -1;
}

void pushdown_xor(int rt, int l, int r) {
    int lc = rt << 1, rc = rt << 1 | 1, mid = (l + r) >> 1;
    if (lazy_cover[lc] == -1) lazy_xor[lc] ^= 1, change_xor(lson);
    else lazy_cover[lc] ^= 1, change_cover(lson,lazy_cover[lc]);
    if (lazy_cover[rc] == -1) lazy_xor[rc] ^= 1, change_xor(rson);
    else lazy_cover[rc] ^= 1, change_cover(rson, lazy_cover[rc]);
    lazy_xor[rt] = 0;
}

void pushdown(int rt, int l, int r) {
    if (lazy_cover[rt] != -1) pushdown_cover(rt, l, r);
    if (lazy_xor[rt] != 0) pushdown_xor(rt, l, r);
}

void build(int rt, int l, int r) {
    int mid = (l + r) >> 1;
    if (l == r) {
        change_cover(rt, l, r, val[l]);
        lazy_cover[rt] = -1; lazy_xor[rt] = 0;
        sum[rt] = val[l];
    }
    else {
        lazy_cover[rt] = -1; lazy_xor[rt] = 0;
        build(lson); build(rson);
        pushup(rt, l, r);
    }
}

void update(int rt, int l, int r, int ql, int qr, int Val) {
    if (ql <= l && qr >= r) {
        if (Val == 2) {
            if (lazy_cover[rt] == -1) {
                change_xor(rt, l, r); lazy_xor[rt] ^= 1;
            }
            else {
                lazy_cover[rt] ^= 1;
                change_cover(rt,l,r,lazy_cover[rt]);
            }
        }
        else {
            lazy_cover[rt] = Val; lazy_xor[rt] = 0;
            change_cover(rt, l, r, lazy_cover[rt]);
        }
    }
    else {
        int mid = (l + r) >> 1;
        pushdown(rt, l, r);
        if (ql <= mid) update(lson, ql, qr, Val);
        if (qr > mid) update(rson, ql, qr, Val);
        pushup(rt, l, r);
    }
}

int query_sum(int rt, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) return sum[rt];
    pushdown(rt, l, r);
    int mid = (l + r) >> 1, ret = 0;
    if (ql <= mid) ret += query_sum(lson, ql, qr);
    if (qr > mid) ret += query_sum(rson, ql, qr);
    return ret;
}

int query_len(int rt, int l, int r, int ql, int qr) {
    int mid = (l + r) >> 1, lc = rt << 1, rc = rt << 1 | 1;
    if (ql <= l && qr >= r) return mmax[rt][1];
    pushdown(rt, l, r);
    if (ql > mid) return query_len(rson, ql, qr);
    if (qr <= mid) return query_len(lson, ql, qr);
    int Lmax = query_len(lson, ql, mid), Rmax = query_len(rson, mid + 1, qr);
    int Lpos, Rpos, Mmax;
    Lpos = max(ql, mid - rmax[lc][1] + 1);
    Rpos = min(qr, mid + lmax[rc][1]);
    Mmax = Rpos - Lpos + 1;
    return max(Mmax, max(Lmax, Rmax));
}

void Handle(int cmd, int a, int b) {
	if (cmd == 0 || cmd == 1 || cmd == 2) update(1, 1, N, a, b, cmd);
	if (cmd == 3) printf("%d\n", query_sum(1, 1, N, a, b));
	if (cmd == 4) printf("%d\n", query_len(1, 1, N, a, b));
}

int main() {
	int T; scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++) {
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; i++) scanf("%d", &val[i]);
		build(1, 1, N);
		for (int i = 0; i < M; i++) {
			int cmd, a, b;
			scanf("%d%d%d", &cmd, &a, &b);
			Handle(cmd, a + 1, b + 1);
		}
	}
	return 0;
}
