#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

typedef long long LL;
using namespace std;
#define lson rt << 1,l,mid
#define rson rt << 1 | 1,mid + 1,r
const int maxn = 5e4 + 10;

struct Seg {
	int l, r, x, cover;
	Seg(int x, int l, int r, int cover) :l(l), r(r), x(x), cover(cover) {}
	bool operator < (const Seg &seg) const {
		return x < seg.x;
	}
};

LL cnt[maxn << 2], len[maxn << 2], n;
vector<Seg> seg;

void pushup(int rt, int l, int r) {
	if (cnt[rt] > 0) len[rt] = r - l + 1;
	else if (l == r) len[rt] = 0;
	else len[rt] = len[rt << 1] + len[rt << 1 | 1];
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
	int x1, y1, x2, y2, x3, y3, x4, y4, maxval = -1;
	while (scanf("%I64d", &n), n != 0) {
		seg.clear();
		memset(cnt, 0, sizeof(cnt));
		memset(len, 0, sizeof(len));
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
			seg.push_back(Seg(x1, y1, y2, 1));
			seg.push_back(Seg(x3, y1, y2, -1));

			seg.push_back(Seg(x4, y1, y2, 1));
			seg.push_back(Seg(x2, y1, y2, -1));

			seg.push_back(Seg(x3, y1, y3, 1));
			seg.push_back(Seg(x4, y1, y3, -1));

			seg.push_back(Seg(x3, y4, y2, 1));
			seg.push_back(Seg(x4, y4, y2, -1));
			maxval = max(maxval, max(max(y1, y2), max(y3, y4)));
		}
		sort(seg.begin(), seg.end());
		int msize = seg.size();
		LL ret = 0;
		for (int i = 0; i < msize - 1; i++) {
			//printf("now is %d %d %d\n", seg[i].l, seg[i].r, seg[i].cover);
			if (seg[i].l < seg[i].r) {
				update(1, 0, maxval, seg[i].l, seg[i].r - 1, seg[i].cover);
			}
			ret += (seg[i + 1].x - seg[i].x) * len[1];
			//printf("%d add %d\n", i, (seg[i + 1].x - seg[i].x) * len[1]);
		}
		printf("%I64d\n", ret);
	}
	return 0;
}