#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const int maxn = 1e6 + 5;
const int maxm = 2e6 + 10;
const int hash_mod = 99997;
int n, m;
int head[hash_mod], nxt[maxm], cnt[maxm], val[maxm], sz;

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

inline void printf_(int x) {
    if (x>9) printf_(x / 10);
    putchar(x % 10 + '0');
}

inline void insert(int v) {
	int pos = v % hash_mod;
	for(int i = head[pos]; ~i; i = nxt[i]) {
		if(val[i] == v) {
			cnt[i]++;
			return;
		}
	}
	cnt[sz] = 1; val[sz] = v;
	nxt[sz] = head[pos];
	head[pos] = sz++;
}

inline int get(int v) {
	int pos = v % hash_mod, ret = 0;
	for(int i = head[pos]; ~i; i = nxt[i]) {
		if(val[i] == v) {
			ret = cnt[i];
			cnt[i] = 0;
			break;
		}
	}
	return ret;
}

int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		int tmp;
		sz = 0;
		memset(head, -1, sizeof(head));
		for(int i = 1; i <= n; i++) {
			scanf_(tmp);
			insert(tmp);
		}
		for(int i = 1; i <= m; i++) {
			scanf_(tmp);
			printf_(get(tmp));
			putchar('\n');
		}
	}
	return 0;
}
