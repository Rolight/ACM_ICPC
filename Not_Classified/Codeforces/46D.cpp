#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid + 1,r
typedef long long LL;
const int maxn = 1e5 + 10;
const int maxm = 1e3;
int lmax[maxn << 2], rmax[maxn << 2], mmax[maxn << 2], lazy[maxn << 2];
int spos[maxm], epos[maxm];

void pushup(int rt, int l, int r) {
	int lc = rt << 1, rc = rt << 1 | 1, mid = (l + r) >> 1;
	int Llen = mid - l + 1, Rlen = r - mid;
	lmax[rt] = lmax[lc]; rmax[rt] = rmax[rc];
	mmax[rt] = max(mmax[lc], mmax[rc]);
	if (rmax[lc] != 0 && lmax[rc] != 0) {
		if (lmax[lc] == Llen) lmax[rt] += lmax[rc];
		if (rmax[rc] == Rlen) rmax[rt] += rmax[lc];
		mmax[rt] = max(mmax[rt], rmax[lc] + lmax[rc]);
		mmax[rt] = max(mmax[rt], max(lmax[rt], rmax[rt]));
	}
}

void pushdown(int rt, int l, int r) {
	if (lazy[rt] == -1) return;
	int lc = rt << 1, rc = rt << 1 | 1, mid = (l + r) >> 1;
	int Llen = mid - l + 1, Rlen = r - mid;
	lazy[lc] = lazy[rc] = lazy[rt];
	lmax[lc] = rmax[lc] = mmax[lc] = lazy[rt] ? 0 : Llen;
	lmax[rc] = rmax[rc] = mmax[rc] = lazy[rt] ? 0 : Rlen;
	lazy[rt] = -1;
}

void build(int rt, int l, int r) {
	if (l == r) {
		lmax[rt] = rmax[rt] = mmax[rt] = 1;
		lazy[rt] = -1;
	}
	else {
		int mid = (l + r) >> 1;
		build(lson); build(rson);
		lazy[rt] = -1;
		pushup(rt, l, r);
	}
}

void update(int rt, int l, int r, int ql, int qr, int Val) {
	if (ql <= l && qr >= r) {
		lazy[rt] = Val;
		lmax[rt] = rmax[rt] = mmax[rt] = Val ? 0 : r - l + 1;
	}
	else {
		pushdown(rt, l, r);
		int mid = (l + r) >> 1;
		if (ql <= mid) update(lson, ql, qr, Val);
		if (qr > mid) update(rson, ql, qr, Val);
		pushup(rt, l, r);
	}
}

int query(int rt, int l, int r, int D) {
	int mid = (l + r) >> 1;
	if (lmax[rt] >= D) return l;
	pushdown(rt, l, r);
	if (mmax[rt << 1] >= D) return query(lson, D);
	if (rmax[rt << 1] + lmax[rt << 1 | 1] >= D) return mid - rmax[rt << 1] + 1;
	return query(rson, D);
}

int N, b, f, M;

int main() {
	int cnt = 1, ccnt = 0;
	scanf("%d%d%d%d", &N, &b, &f, &M);
	build(1, 1, N);
	for (int i = 1; i <= M; i++) {
		int cmd, x; scanf("%d%d", &cmd, &x);
		if (cmd == 1) {
            int s,e,rt = 1;
            bool flag = false;
            if(ccnt == 0) {
                //如果当前没有车，可以不考虑空位的问题
                if(lmax[rt] >= x) {
                    s = 1; e = x; flag = true;
                }
            }
            else {
                //先尝试停在左边界上
                if(lmax[rt] >= x + f) {
                    s = 1; e = x; flag = true;
                }
                else if(mmax[rt] >= x + b + f) {
                    //尝试停在中间
                    int ret = query(1,1,N,x + b + f);
                    s = ret + b; e = ret + b + x - 1; flag = true;
                }
                else if(rmax[rt] >= x + b) {
                    //尝试停在最后边界
                    s = N - rmax[rt] + 1 + b; e = s + x - 1; flag = true;
                }
            }
            if(flag) {
                ccnt++;
                printf("%d\n",s - 1);
                update(1,1,N,s,e,1);
                spos[i] = s; epos[i] = e;
            }
            else puts("-1");
		}
		else  {
			update(1, 1, N, spos[x], epos[x], 0);
			ccnt--;
		}
	}
	return 0;
}

