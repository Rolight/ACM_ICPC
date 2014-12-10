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
	//�����С����x��������С
	bool operator < (const Seg &tmp) const {
		return x < tmp.x;
	}
};

int n, cnt[maxn << 2];
double len[maxn << 2];
vector<double> dy;
vector<Seg> seg;

int GetID(double Val) {
	//���ֲ��ҵ�����꣬��ɢ��
	return lower_bound(dy.begin(), dy.end(), Val) - dy.begin();
}

void pushup(int rt, int l, int r) {
	int lc = rt << 1, rc = rt << 1 | 1;
	//�����ǰ�߶δ��ڣ���������
	//����r+1����Ϊ����Ϊx���߶���x+1���㣬�������һ������r+1
	if (cnt[rt]) len[rt] = dy[r + 1] - dy[l];
	else if (r == l) len[rt] = 0;
	else len[rt] = len[lc] + len[rc];
}

void update(int rt, int l, int r, int ql, int qr, int Val) {
	int lc = rt << 1, rc = rt << 1 | 1, mid = (l + r) >> 1;
	if (ql <= l && qr >= r) {
		//�ۼӵ�ǰ�߶ε�ֵ
		cnt[rt] += Val;
		pushup(rt, l, r);
	}
	else {
		//��ǲ���Ҫ�·ţ���Ϊ��ǰ�߶ε����������߶�û�й�ϵ
		//����ÿ���߶αض�����һ�Σ�����һ��
		if (ql <= mid) update(lson, ql, qr, Val);
		if (qr > mid) update(rson, ql, qr, Val);
		pushup(rt, l, r);
	}
}

int main() {
	int kase = 1;
	while (scanf("%d", &n), n != 0) {
		//��ʼ���߶���
		dy.clear(); seg.clear();
		memset(cnt, 0, sizeof(cnt));
		memset(len, 0, sizeof(len));
		//��������
		for (int i = 1; i <= n; i++) {
			double x1, x2, y1, y2; scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			//��ÿ�����γ���������߶�
			seg.push_back(Seg(y1, y2, x1, 1));
			seg.push_back(Seg(y1, y2, x2, -1));
			//�洢ÿ�������ֵ
			dy.push_back(y1); dy.push_back(y2);
		}
		//������������ɢ��
		sort(dy.begin(), dy.end());
		dy.erase(unique(dy.begin(), dy.end()), dy.end());
		//���߶�����
		sort(seg.begin(), seg.end());
		int msize = seg.size(), k = dy.size();
		double ret = 0;
		for (int i = 0; i < msize - 1; i++) {
			//�����qrΪʲôҪ��һ�� ����Ϊ���߶���ÿ���ڵ�����l,r֮����߶Σ������ǵ㼯����ÿ���߶ε��ɵ������Ļ���
			//ÿ��[l,r]�ĵ㹹�ɵ��߶α��Ӧ����[l,r-1]
			int ql = GetID(seg[i].l), qr = GetID(seg[i].r) - 1;
			//����ֵ
			update(1, 0, k - 1, ql, qr, seg[i].cover);
			//�ۼӵ�ǰɨ����ɨ�������
			ret += len[1] * (seg[i + 1].x - seg[i].x);
		}
		printf("Test case #%d\nTotal explored area: %.2lf\n\n", kase++, ret);
	}
	return 0;
}