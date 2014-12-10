#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
const int maxn = 30000 + 5;
const int maxlen = 40;
const int maxnode = maxn * maxlen;
const int sigma_size = 52;
int n, m;
int cnt[maxn];
int ch[maxnode][sigma_size], sid[maxnode], sz;
char buf[maxn][maxlen];
char str[maxlen];

void clear() {
	memset(ch[0], 0, sizeof(ch[0]));
	sz = 1;
}

inline int idx(char c) {
	if (c <= 'z' && c >= 'a') return c - 'a';
	return c - 'A' + 26;
}

void insert(char *str,int id) {
	int len = strlen(str), u = 0;
	for (int i = 0; i < len; i++) {
		int c = idx(str[i]);
		if (ch[u][c] == 0) {
			memset(ch[sz], 0, sizeof(ch[sz]));
			sid[sz] = -1;
			ch[u][c] = sz++;
		}
		u = ch[u][c];
	}
	sid[u] = id;
}

void increase(char *str, int val) {
	int len = strlen(str), u = 0;
	for (int i = 0; i < len; i++) {
		int c = idx(str[i]);
		u = ch[u][c];
	}
	cnt[sid[u]] += val;
}

int main() {
	while (scanf("%d", &n) != EOF) {
		int memid, tmp;
		clear();
		for (int i = 0; i < n; i++) {
			scanf("%s", buf[i]);
			cnt[i] = 0;
			if (strcmp(buf[i], "memory") == 0) {
				memid = i;
			}
			insert(buf[i], i);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d%s", &tmp, str);
				increase(str, tmp);
			}
			int rank = 1;
			for (int j = 0; j < n; j++) {
				if (cnt[j] > cnt[memid]) rank++;
			}
			printf("%d\n", rank);
		}
	}
	return 0;
}
