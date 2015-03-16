#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

const LL MOD = 1e9 + 7;

//³Ë·¨ÄæÔª
LL ex_gcd(LL a, LL b, LL &x, LL &y)
{
	if (a == 0 && b == 0) return -1;
	if (b == 0) { x = 1; y = 0; return a; }
	LL d = ex_gcd(b, a%b, y, x);
	y -= a / b*x;
	return d;
}
LL Get_inv(LL a, LL n = MOD)
{
	LL x, y, d = ex_gcd(a, n, x, y);
	if (d == 1) return (x%n + n) % n;
	else return -1;
}

const int maxn = 3e4 + 10;

LL nowcnt[maxn], a[maxn], n, m;
LL ans[maxn], unit_size, inv[maxn];

struct Q {
	int l, r, id;
	bool operator < (const Q &x) const {
		if (l / unit_size == x.l / unit_size) return r < x.r;
		return l / unit_size < x.l / unit_size;
	}
};

Q q[maxn];

void gao() {
	LL nowl = q[1].l, nowr = q[1].r;
	LL nowval = 1, nowc = 0;
	for (int i = nowl; i <= nowr; i++) {
		nowc++; nowcnt[a[i]]++;
		nowval = (nowval * nowc) % MOD;
		nowval = (nowval * inv[nowcnt[a[i]]]) % MOD;
	}
	ans[q[1].id] = nowval;
	for (int i = 2; i <= m; i++) {
		while (nowl > q[i].l) {
			nowl--; nowc++;
			nowcnt[a[nowl]]++;
			nowval = (nowval * nowc) % MOD;
			nowval = (nowval * inv[nowcnt[a[nowl]]]) % MOD;
		}
		while (nowr < q[i].r) {
			nowr++; nowc++;
			nowcnt[a[nowr]]++;
			nowval = (nowval * nowc) % MOD;
			nowval = (nowval * inv[nowcnt[a[nowr]]]) % MOD;
		}
		while (nowr > q[i].r) {
			nowval = (nowval * inv[nowc]) % MOD;
			nowval = (nowval * nowcnt[a[nowr]]) % MOD;
			nowcnt[a[nowr]]--;
			nowr--; nowc--;
		}
		while (nowl < q[i].l) {
			nowval = (nowval * inv[nowc]) % MOD;
			nowval = (nowval * nowcnt[a[nowl]]) % MOD;
			nowcnt[a[nowl]]--;
			nowl++; nowc--;
		}
		ans[q[i].id] = nowval;
	}
}


int main() {
	for (int i = 1; i <= 30000; i++) inv[i] = Get_inv(i) % MOD;
	int T; scanf("%d", &T);
	while (T--) {
		memset(nowcnt, 0, sizeof(nowcnt));
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &q[i].l, &q[i].r);
			q[i].id = i;
		}
		unit_size = (int)sqrt((double)(n));
		if (unit_size <= 0) unit_size = 1;
		sort(q + 1, q + 1 + m);
		gao();
		for (int i = 1; i <= m; i++) {
			printf("%I64d\n", ans[i]);
		}
	}
	return 0;
}