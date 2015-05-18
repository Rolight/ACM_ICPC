#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 45;
int cover[maxn], n;

struct Grid {
	bool m[4];
	inline void add(int a, int b, int c, int d) {
		m[0] |= a; m[1] |= b; m[2] |= c; m[3] |= d;
	}
	inline double gp() {
		double ret = 0;
		for(int i = 0; i < 4; i++) if(m[i]) ret += 0.25;
		return ret;
	}
};

struct Tri {
	int x, y, w, pcnt;
	double p;
	Tri(int x = 0, int y = 0, int w = 0):
		x(x), y(y), w(w) {
	}

};

Grid grid[42][21];
Tri tt[maxn];

inline void add_grid(Tri t) {
	int x = t.x, y = t.y;
	for(int i = 1; i <= y; i++) {
		int bdc = y - i + 1, lbd = x - bdc + 1, rbd = x + bdc;
		for(int j = lbd; j <= rbd; j++) {
			if(j == lbd) grid[i][j].add(0, 0, 1, 1);
			else if(j == rbd) grid[i][j].add(0, 1, 1, 0);
			else grid[i][j].add(1, 1, 1, 1);
		}
	}
}

double gao() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		tt[i] = Tri(x + 21, y, w);
	}
	double ans = 0;
	for(int i = (1 << n) - 1; i >= 0; i--) {
		double nowp = 0, nowcost = 0;
		for(int j = 0; j < n; j++) if(i & (1 << j)) nowp += tt[j].w;
		if(nowp <= ans) continue;
		memset(grid, 0, sizeof(grid));
		for(int j = 0; j < n; j++) if(i & (1 << j)) add_grid(tt[j]);
		for(int j = 0; j < 42; j++) {
			for(int k = 0; k < 21; k++) {
				nowcost += grid[j][k].gp();
				//printf("%.2f ", grid[j][k].gp());
			}
			//puts("");
		}
		//printf("%.2f %.2f\n", nowp, nowcost);
		ans = max(ans, nowp - nowcost);
	}
	return ans;
}

int main() {
	//freopen("out.txt", "w", stdout);
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		printf("Case #%d: %.2f\n", kase, gao());
	}
}
