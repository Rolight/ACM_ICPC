#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <ctime>
#include <cstdlib>

typedef long long LL;
const int maxn = 2048;

struct Line {
	int x0, y0, x1, y1;
	Line(int a, int b, int c, int d):
		x0(a), y0(b), x1(c), y1(d) {}
};

std::vector<Line> h, v;
int n;

int ok(Line h1, Line h2, Line v1, Line v2) {
	if(h1.y0 == h2.y0 || v1.x0 == v2.x0) return 0;
	if(h1.x0 >= h2.x1 || h2.x0 >= h1.x1) return 0;
	if(v1.y0 >= v2.y1 || v2.y0 >= v1.y1) return 0;
	if(v1.y0 <= h1.y0 && v1.y0 <= h2.y0 && v1.y1 >= h1.y0 && v1.y1 >= h2.y0 &&
	   v2.y0 <= h1.y0 && v2.y0 <= h2.y0 && v2.y1 >= h1.y0 && v2.y1 >= h2.y0 &&
	   h1.x0 <= v1.x0 && h1.x1 >= v1.x0 && h1.x0 <= v2.x0 && h1.x1 >= v2.x0 &&
	   h2.x0 <= v1.x0 && h2.x1 >= v1.x0 && h2.x0 <= v2.x0 && h2.x1 >= v2.x0)
		return 1;
	return 0;

}

int gao() {
	int ans = 0;
	for(int i = 0; i < h.size(); i++) {
		for(int j = i + 1; j < h.size(); j++) {
			for(int k = 0; k < v.size(); k++) {
				for(int l = k + 1; l < v.size(); l++) {
					ans += ok(h[i], h[j], v[k], v[l]);
				}
			}
		}
	}
	return ans;
}

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase) {
		scanf("%d", &n);
		h.clear(); v.clear();
		int a, b, c, d;
		for(int i = 1; i <= n; i++) {
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if(a > c || b > d) {
				std::swap(a, c);
				std::swap(b, d);
			}
			if(a == c) {
				v.push_back(Line(a, b, c, d));
			}
			else {
				h.push_back(Line(a, b, c, d));
			}
		}
		printf("Case #%d:\n%d\n", kase, gao());
	}
	return 0;
}
