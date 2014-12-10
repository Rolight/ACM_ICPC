#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define lson rt<<1,l,mid
#define rson rt<<1|1,mid + 1,r
using namespace std;
const int maxn = 4004;

struct Seg {
	double l, r, x;
	int cover;
	Seg(double l, double r, double x, int cover) :l(l), r(r), x(x), cover(cover) {}
	//排序大小按照x轴的坐标大小
	bool operator < (const Seg &tmp) const {
		return x < tmp.x;
	}
};

int n, cnt[maxn << 2];
double len[maxn << 2];
vector<double> dy;
vector<Seg> seg;

int GetID(double Val) {
	//二分查找点的坐标，离散化
	return lower_bound(dy.begin(), dy.end(), Val) - dy.begin();
}

void pushup(int rt, int l, int r) {
	int lc = rt << 1, rc = rt << 1 | 1;
	//如果当前线段存在，更新坐标
	//这里r+1是因为长度为x的线段有x+1个点，所以最后一个点是r+1
	if (cnt[rt]) len[rt] = dy[r + 1] - dy[l];
	else if (r == l) len[rt] = 0;
	else len[rt] = len[lc] + len[rc];
}

void update(int rt, int l, int r, int ql, int qr, int Val) {
	int lc = rt << 1, rc = rt << 1 | 1, mid = (l + r) >> 1;
	if (ql <= l && qr >= r) {
		//累加当前线段的值
		cnt[rt] += Val;
		pushup(rt, l, r);
	}
	else {
		//标记不需要下放，因为当前线段的增减和子线段没有关系
		//而且每条线段必定增加一次，减少一次
		if (ql <= mid) update(lson, ql, qr, Val);
		if (qr > mid) update(rson, ql, qr, Val);
		pushup(rt, l, r);
	}
}

int main() {
	int kase = 1;
	while (scanf("%d", &n), n != 0) {
		//初始化线段树
		dy.clear(); seg.clear();
		memset(cnt, 0, sizeof(cnt));
		memset(len, 0, sizeof(len));
		//读入数据
		for (int i = 1; i <= n; i++) {
			double x1, x2, y1, y2; scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			//将每个矩形抽象成两条线段
			seg.push_back(Seg(y1, y2, x1, 1));
			seg.push_back(Seg(y1, y2, x2, -1));
			//存储每个坐标的值
			dy.push_back(y1); dy.push_back(y2);
		}
		//将浮点坐标离散化
		sort(dy.begin(), dy.end());
		dy.erase(unique(dy.begin(), dy.end()), dy.end());
		//将线段排序
		sort(seg.begin(), seg.end());
		int msize = seg.size(), k = dy.size();
		double ret = 0;
		for (int i = 0; i < msize - 1; i++) {
			//这里的qr为什么要减一？ 是因为我线段树每个节点存的是l,r之间的线段，而不是点集，把每个线段当成点来看的话，
			//每个[l,r]的点构成的线段编号应该是[l,r-1]
			int ql = GetID(seg[i].l), qr = GetID(seg[i].r) - 1;
			//更新值
			update(1, 0, k - 1, ql, qr, seg[i].cover);
			//累加当前扫描线扫过的面积
			ret += len[1] * (seg[i + 1].x - seg[i].x);
		}
		printf("Test case #%d\nTotal explored area: %.2lf\n\n", kase++, ret);
	}
	return 0;
}