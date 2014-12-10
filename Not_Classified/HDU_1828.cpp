#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

const int maxn = 2e4 + 10;
#define lson rt << 1, l, mid
#define rson rt << 1 | 1,mid + 1,r
struct Seg {
	int l, r, x, cover;
	Seg(int l, int r, int x, int cover) :l(l), r(r), x(x), cover(cover) {}
	bool operator < (const Seg &seg) const {
		if (x == seg.x) return cover > seg.cover;
		return x < seg.x;
	}
};

vector<Seg> seg;
int n;
bool lbound[maxn << 2], rbound[maxn << 2];
int numseg[maxn << 2], len[maxn << 2], cnt[maxn << 2];
int minval, maxval;

void pushup(int rt, int l, int r) {
	int lc = rt << 1, rc = rt << 1 | 1;
	if (cnt[rt]) {
		lbound[rt] = rbound[rt] = true;
		//因为每一条线段的长度都等于1，第l条线段起始点是l，第r条线段的结束点是r + 1,长度是r + 1 - l
		len[rt] = r - l + 1;
		//因为横向必定有两条边，所以为2
		numseg[rt] = 2;
	}
	else if (l == r) {
		len[rt] = numseg[rt] = lbound[rt] = rbound[rt] = 0;
	}
	else {
		len[rt] = len[lc] + len[rc];
		lbound[rt] = lbound[lc];
		rbound[rt] = rbound[rc];
		numseg[rt] = numseg[lc] + numseg[rc];
		//如果在交点重合
		if (rbound[lc] && lbound[rc]) {
			numseg[rt] -= 2;
		}
	}
}

void update(int rt, int l, int r, int ql, int qr, int Val) {
	if (ql <= l && qr >= r) {
		cnt[rt] += Val;
		pushup(rt, l, r);
	}
	else {
		int mid = (l + r) >> 1;
		if (ql <= mid) update(lson, ql, qr, Val);
		if (qr > mid) update(rson, ql, qr, Val);
		pushup(rt, l, r);
	}
}

int main() {
	while (scanf("%d", &n) != EOF) {
		seg.clear();
		minval = INT_MAX; maxval = -1;
		for (int i = 1; i <= n; i++) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			seg.push_back(Seg(y1, y2, x1, 1));
			seg.push_back(Seg(y1, y2, x2, -1));
			minval = min(minval, min(y1, y2));
			maxval = max(maxval, max(y1, y2));
		}
		sort(seg.begin(), seg.end());
		int msize = seg.size(), ret = 0, last = 0;
		for (int i = 0; i < msize; i++) {
			if (seg[i].l < seg[i].r) update(1, minval, maxval, seg[i].l, seg[i].r - 1, seg[i].cover);
			//横向的长度
			if (i < msize - 1) ret += numseg[1] * (seg[i + 1].x - seg[i].x);
			//纵向的长度
			ret += abs(last - len[1]);
			last = len[1];
		}
		printf("%d\n", ret);
	}
	return 0;
}