#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <string>

using namespace std;

const int mod = 1e5 + 7;
const int maxn = 1e6 + 10;
typedef long long LL;

struct Hash_Map {
	int head[mod], nxt[maxn], cnt;
	LL val[maxn];
	
	void clear() {
		memset(head, -1, sizeof(head));
		cnt = 0;
	}
	
	void insert(LL v) {
		int pos = abs(v % mod), u;
		for (u = head[pos]; ~u; u = nxt[u]) ;
		val[cnt] = v;
		nxt[cnt] = head[pos];
		head[pos] = cnt++;
	}
	
	int count(LL v) {
		int pos = abs(v % mod), u;
		for(u = head[pos]; ~u && val[u] != v; u = nxt[u]);
		if(u == -1) return 0;
		return 1;
	}
};

int num[maxn];
LL sum0[maxn];
int n, k, kase = 1;
Hash_Map st0, st1; 


inline bool scanf_(int &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0; //EOF
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}

bool gao() {
	if(num[1] == k) return true;
	st0.clear(); st1.clear();
	for (int r = 1; r <= n; r++) {
		if(st0.count(sum0[r] + k) || st1.count(sum0[r] - k)) return 1;
		if(r & 1) st1.insert(sum0[r]);
		else st0.insert(sum0[r]);
	}
	return 0;
}

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d%d", &n, &k);
		int flag = -1;
		for (int i = 1; i <= n; i++) {
			scanf_(num[i]);
		}
		for (int i = 1; i <= n; i++) {
			sum0[i] = num[i] * flag + sum0[i - 1];
			flag *= -1;
		}
		printf("Case #%d: %s\n", kase, gao() ? "Yes." : "No.");
	}
	return 0;
}

