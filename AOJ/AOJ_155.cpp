#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 1e5;
bool vis1[maxn];
int pnum[maxn * 10], pcnt = 0;

void init() {
	for (int i = 2; i < 1e5; i++) if (!vis1[i]) {
		pnum[pcnt++] = i;
		for (int j = i + i; j < 1e5; j += i) {
			vis1[j] = true;
		}
	}
}

bool isprime(int num) {
	if (num == 1) return false;
	int n = sqrt(num);
	for (int i = 0; pnum[i] <= n; i++) {
		if (num % pnum[i] == 0) return false;
	}
	return true;
}

int x[10], n, vis[10], cnt = 0;
int tmp[10], cc = 0;

void printnum(int num) {
	while (num) {
		tmp[cc++] = num % 10; num /= 10;
	}
	if (cc == 0) {
		puts("0"); return;
	}
	while (cc) {
		cc--; putchar('0' + tmp[cc]);
	}
	puts("");
}

void dfs(int pos, int num) {
	if (pos == n) {
		if (isprime(num)) printnum(num), cnt++;
		return;
	}
	for (int i = 0; i < n; i++) if (!vis[i]) {
		vis[i] = true;
		dfs(pos + 1, num * 10 + x[i]);
		vis[i] = false;
	}
}

int main() {
	init();
	while (~scanf("%d", &n) && n) {
		cnt = 0;
		for (int i = 0; i < n; i++) scanf("%d", &x[i]);
		if (n == 9) {
			puts("NONE\n"); continue;
		}
		sort(x, x + n);
		dfs(0, 0);
		if (!cnt) puts("NONE");
		puts("");
	}
	return 0;
}