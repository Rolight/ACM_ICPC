#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 1e5 + 10;
int maxm;

int n, m, bid[maxn];
int nxt[maxn], jmp[maxn], cnt[maxn];

inline void calc(int i) {
	if(i + jmp[i] > n) {
		nxt[i] = i; cnt[i] = 0;
	}
	else if(bid[i + jmp[i]] == bid[i]) {
		cnt[i] = cnt[i + jmp[i]] + 1;
		nxt[i] = nxt[i + jmp[i]];
	}
	else {
		nxt[i] = i + jmp[i];
		cnt[i] = 1;
	}
}

void query(int a) {
	int oid = a, ct = 1;
	while(nxt[oid] != oid) {
		ct += cnt[oid];
		oid = nxt[oid];
	}
	printf("%d %d\n", oid, ct);
}

void update(int a, int b) {
	int l = a;
	while(l > 0 && bid[l] == bid[a]) l--;
	l++;
	jmp[a] = b;
	for(int i = a; i >= l; i--) calc(i);
}

int main() {
	scanf("%d%d", &n, &m);
	maxm = sqrt(n) + 1;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &jmp[i]);
		bid[i] = i / maxm + 1;
	}
	for(int i = n; i >= 1; i--) calc(i);
	int cmd, a, b;
	for(int i = 1; i <= m; i++) {
		scanf("%d", &cmd);
		if(cmd == 0) {
			scanf("%d%d", &a, &b);
			update(a, b);
		}
		else {
			scanf("%d", &a);
			query(a);
		}
	}
	return 0;
}
