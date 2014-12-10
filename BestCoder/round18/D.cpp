#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
const int maxn = 3e4 + 100;
const int inf = 1e9 + 100;

struct Node {
    int val[12];
    Node() {
        for(int i = 1; i <= 11; i++) val[i] = inf;
    }
    void Megre(int val1[12]) {
        int tar[22];
		for(int i = 1; i <= 10; i++) {
			tar[i] = val[i]; tar[i + 10] = val1[i];
		}
		sort(tar + 1, tar + 21);
        for(int i = 1; i <= 10; i++) val[i] = tar[i];
		val[11] = inf;
    }
	void Megre(int k) {
		val[11] = k;
		sort(val + 1, val + 12);
		val[11] = inf;
	}
	void print() {
		for(int i = 1; i <= 10; i++)  {
			printf("%d ", val[i]);
		}
		puts("");
	}
};

Node minv[maxn << 4];

void pushup(int rt) {
    minv[rt] = minv[rt << 1];
    minv[rt].Megre(minv[rt << 1 | 1].val);
}

void build(int rt, int l, int r) {
    if(l == r) minv[rt] = Node();
    else {
        int mid = (l + r) >> 1;
        build(lson); build(rson);
        pushup(rt);
    }
}

void update(int rt, int l, int r, int pos, int x) {
    if(l == r) minv[rt].Megre(x);
    else {
        int mid = (l + r) >> 1;
        if(pos <= mid) update(lson, pos, x);
        else update(rson, pos, x);
        pushup(rt);
    }
}

Node query(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) return minv[rt];
    else {
        int mid = (l + r) >> 1;
        Node ret = Node();
        if(ql <= mid) ret.Megre(query(lson, ql, qr).val);
        if(qr > mid) ret.Megre(query(rson, ql, qr).val);
		return ret;
    }
}

struct Point {
    int x, y, h, k;
    int id;
    bool isq;
    Point(int x, int y, int h, bool isq, int k = 0, int id = 0):
        x(x), y(y), h(h), isq(isq), k(k), id(id) {}
    bool operator < (const Point &p) const {
        if(y == p.y) return x < p.x;
        return y < p.y;
    }
};

int n, m, ans[maxn];
vector<int> vnum;
vector<Point> pp;

int getid(int val) {
    int ret = lower_bound(vnum.begin(), vnum.end(), val) - vnum.begin() + 1;
	return ret;
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        vnum.clear(); pp.clear();
        for(int i = 1; i <= n; i++) {
            int x, y, h; scanf("%d%d%d",&x, &y, &h);
            pp.push_back(Point(x, y, h, false));
            vnum.push_back(x);
        }
        for(int i = 1; i <= m; i++) {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            pp.push_back(Point(x, y, 0, true, k, i));
            vnum.push_back(x);
        }
        sort(vnum.begin(), vnum.end());
        sort(pp.begin(), pp.end());
        vnum.erase(unique(vnum.begin(), vnum.end()), vnum.end());
        int mm = pp.size(), nn = vnum.size();
        build(1, 1, nn);
        for(int i = 0; i < mm; i++) {
            if(pp[i].isq == false) {
                update(1, 1, nn, getid(pp[i].x), pp[i].h);
            }
            else {
                Node ret = query(1, 1, nn, 1, getid(pp[i].x));
                ans[pp[i].id] = ret.val[pp[i].k];
            }
        }
        for(int i = 1; i <= m; i++) {
            if(ans[i] == inf) ans[i] = -1;
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
