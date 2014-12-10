#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
const int maxn = 1005;
const int mod = 1000007;
typedef long long LL;

int head[mod], nxt[mod * 10], sz;
LL A[mod * 10], B[mod * 10];
LL val[mod * 10];
int n, S[maxn];

void clear() {
	memset(head, -1, sizeof(head));
	sz = 0;
}

LL mabs(LL x) {
	return x < 0 ? -x : x;
}

int get_hash(LL x) {
	return mabs(x) % mod;
}

void insert(LL x, LL a, LL b) {
	int pos = get_hash(x);
	A[sz] = a; B[sz] = b; nxt[sz] = head[pos];
	val[sz] = x; head[pos] = sz++;
}

bool check(LL x, LL a, LL b) {
	int pos = get_hash(x);
	for (int i = head[pos]; ~i; i = nxt[i]) {
		if (val[i] == x && A[i] != a && A[i] != b &&
			B[i] != a && B[i] != b) {
			return true;
		}
	}
	return false;
}

int main() {
	while (scanf("%d", &n), n) {
		clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &S[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) if(S[i] != S[j]) {
				insert(S[i] + S[j], S[i], S[j]);
			}
		}

		LL ans = -1e17; bool ok = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) if (S[i] != S[j]) {
				if (check(S[i] - S[j], S[i], S[j])) {
					ans = max(ans,(LL)S[i]); ok = true;
				}
			}
		}

		if (ok) cout << ans << endl;
		else cout << "no solution" << endl;
	}
	return 0;
}
