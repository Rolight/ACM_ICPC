/*
ID: flsnnx1
LANG: C++
TASK: skidesign
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1e3 + 5;
const int maxv = 1e2 + 5;
const int inf = 1e9;
int h[maxn], n;

inline int sq(int x) {
	return x * x;
}

int main() {
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}
	int ans = 1e9;
	for(int i = 0; i <= 100 - 17; i++) {
		int nowans = 0;
		for(int j = 1; j <= n; j++) {
			if(h[j] < i) {
				nowans += sq(i - h[j]);
			}
			else if(h[j] > i + 17) {
				nowans += sq(h[j] - i - 17);
			}
		}
		ans = min(nowans, ans);
	}
	printf("%d\n", ans);
	return 0;
}

