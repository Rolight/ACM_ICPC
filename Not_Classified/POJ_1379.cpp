#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int maxn = 1005;
const double eps = 1e-8;
const double r = 0.99;
const int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
const int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int px[maxn], py[maxn];
int X, Y, M;

double sq(double x) {
	return x * x;
}

double dis(double x, double y) {
	double ret = 1e90;
	for (int i = 0; i < M; i++) {
		ret = min(ret, sqrt(sq(x - px[i]) + sq(y - py[i])));
	}
	return ret;
}

double solve(double &x, double &y) {
	double nowdis = dis(x, y);
	double step = max(X, Y);
	while (step > eps) {
		for (int i = 0; i < 8; i++) {
			double nx = x + dx[i] * step,
				ny = y + dy[i] * step,
				ndis = dis(nx, ny);
			if (nx > X || nx < 0 || ny > Y || ny < 0) continue;
			if (ndis > nowdis) {
				x = nx; y = ny; nowdis = ndis;
			}
		}
		step *= r;
	}
	return nowdis;
}

int main() {
	int T; scanf("%d", &T);
	srand(time(NULL));
	while (T--) {
		scanf("%d%d%d", &X, &Y, &M);
		for (int i = 0; i < M; i++) scanf("%d%d", &px[i], &py[i]);
		double nowdis = 0, x, y;
		for (int i = 0; i < 5; i++) {
			double tx = rand() % (X), ty = rand() % (Y);
			double ret = solve(tx, ty);
			if (ret > nowdis) {
				nowdis = ret;
				x = tx; y = ty;
			}
		}
		printf("The safest point is (%.1f, %.1f).\n",
			x, y);
	}
	return 0;
}
