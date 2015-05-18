#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const int maxn = 1024;
const int inf = INT_MAX / 3;

int gx[maxn], gy[maxn], w[maxn];
int n, T, id[maxn];
double f[maxn];

bool cmp(int a, int b) {
	return gx[a] + gy[a] < gx[b] + gy[b];
}

inline double fc(double l, double r) {
	return (r - l) * (r - l) / 4;
}

int main() {
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d%d%d", &gx[i], &gy[i], &w[i]);
			id[i] = i;
			f[i] = 0;
		}
		f[0] = w[id[0]] - fc(gx[id[0]] - gy[id[0]], gx[id[0]] + gy[id[0]]);
		f[0] = max(f[0], (double)0);
		double ans = max((double)0, f[0]);
		for(int p = 1; p < n; p++) {
			int i = id[p];
			printf("%d\n", gx[i] + gy[i])
			double nowc = w[i] - fc(gx[i] - gy[i], gx[i] + gy[i]);
			f[p] = max(f[p], nowc);
			for(int q = 0; q < p; q++) {
				int j = id[q];
				f[p] = max(f[p], f[q]);
				if(gx[j] + gy[j] <= gx[i] - gy[i]) {
					f[p] = max(f[p], nowc + f[q]);
				}
				else if(gx[i] - gy[i] >= gx[j] - gy[j]) {
					f[p] = max(f[p], nowc + f[q] + fc(gx[i] - gy[i], gx[j] + gy[j]));
				}
				else {
					f[p] = max
				}
			}
			ans = max(ans, f[p]);
		}
		printf("Case #%d: %.2f\n", kase, ans);
	}
	return 0;
}
