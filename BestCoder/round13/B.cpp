#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
const LL mod = 1e9 + 7;
int n, m;
LL a[maxn];
int o[maxn];

LL mypow(LL a, LL b) {
	for (int i = 1; i <= b; i++) a = (a * a) % mod;
	return a;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		char cmd = 0;
		int ocnt = 0, oid;
		for (int i = 0; i < m; i++) {
			scanf(" %c", &cmd);
			if (cmd == 'O') {
				scanf("%d", &oid);
				o[ocnt++] = oid;
			}
			else {
				scanf("%d", &oid);
				int pp = 0;
				for (int j = ocnt - 1; j >= 0; j--) {
					if (o[j] == 2) {
						oid = n - oid + 1;
					}
					else if (o[j] == 1) {
						if (oid <= (n + 1) / 2) oid = oid * 2 - 1;
						else oid = (oid - (n + 1) / 2) * 2;
					}
					else pp++;
				}
				printf("%I64d\n", mypow(oid, pp));
			}
		}
	}
	return 0;
}