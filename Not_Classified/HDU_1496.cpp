#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

#define sq(x) ((x)*(x))

using namespace std;
const int mod = 100007;

struct Hash_Table {
	int head[mod], nxt[mod * 10], val[mod * 10], cnt[mod * 10];
	int sz;

	void clear() {
		memset(head, -1, sizeof(head));
		sz = 0;
	}

	Hash_Table() {
		clear();
	}

	int &operator[] (int pid) {
		int pos = abs(pid) % mod;
		for (int i = head[pos]; ~i; i = nxt[i]) {
			if (val[i] == pid) return cnt[i];
		}
		val[sz] = pid; cnt[sz] = 0;
		nxt[sz] = head[pos]; head[pos] = sz++;
		return cnt[sz - 1];
	}
};

Hash_Table mp;
int a, b, c, d;

int main() {
	while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
		mp.clear();
		if ((a > 0 && b > 0 && c > 0 && d > 0) ||
			(a < 0 && b < 0 && c < 0 && d < 0)) {
			puts("0"); continue;
		}
		long long ans = 0;
		for (int x1 = -100; x1 <= 100; x1++) if(x1) {
			for (int x2 = -100; x2 <= 100; x2++) if(x2) {
				mp[a * sq(x1) + b * sq(x2)]++;
			}
		}
		for (int x3 = -100; x3 <= 100; x3++) if(x3) {
			for (int x4 = -100; x4 <= 100; x4++) if(x4) {
				ans += mp[-(c * sq(x3) + d * sq(x4))];
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
