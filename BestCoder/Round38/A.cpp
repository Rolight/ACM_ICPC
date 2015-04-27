#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long LL;

struct Point {
	LL x, y, z;
	Point(LL x = 0, LL y = 0, LL z = 0): x(x), y(y), z(z) {}
	bool operator < (const Point &p) const {
		if(x == p.x) {
			if(y == p.y) return z < p.z;
			return y < p.y;
		}
		return x < p.x;
	}
};

Point p[4];

Point operator-(Point a, Point b) {
	return Point(a.x - b.x, a.y - b.y, a.z - b.z);
}

LL len(Point p) {
	return p.x * p.x + p.y * p.y + p.z * p.z;
}

bool g(Point p1, Point p2) {
	if(p1.x * p2.x + p1.y * p2.y + p1.z * p2.z == 0) return true;
	return false;
}


bool gao() {
	Point p1 = p[0] - p[1], p2 = p[1] - p[2], p3 = p[2] - p[3], p4 = p[3] - p[0];
	if(len(p1) == len(p2) && len(p1) == len(p3) && len(p1) == len(p4)) {
		if(g(p1, p2) && g(p2, p3) && g(p3, p4) && g(p4, p1)) {
			return true;
		}
	}
	return false;
}

int main() {
	int x, y, z;
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		for(int i = 0; i < 4; i++) {
			scanf("%d%d%d", &x, &y, &z);
			p[i] = Point(x, y, z);
		}
		bool ok = false;
		do {
			ok |= gao();
		} while(next_permutation(p, p + 4));
		printf("Case #%d: %s\n", kase, ok ? "Yes" : "No");
	}
}
