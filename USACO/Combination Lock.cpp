/*
ID: flsnnx1
LANG: C++
TASK: combo
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;

int n;

bool dis(int a, int b) {
	if (a > b) swap(a, b);
	return (b - a) <= 2 || (a + n - b <= 2);
}

bool dis(int a1, int b1, int c1, int a2, int b2, int c2) {
	return dis(a1, a2) && dis(b1, b2) && dis(c1, c2);
}

int main() {
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
	int a[3], b[3];
	scanf("%d", &n);
	for (int i = 0; i < 3; i++) scanf("%d", &a[i]);
	for (int i = 0; i < 3; i++) scanf("%d", &b[i]);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dis(i, j, k, a[0], a[1], a[2]) || dis(i, j, k, b[0], b[1], b[2])) {
					ans++;
				}
			}
		}
	}
	printf("%d\n", ans);
	//system("pause");
    return 0;
}
