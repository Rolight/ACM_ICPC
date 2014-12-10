#include <cstdio>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
#include <ctime>
#include <set>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <string>
#include <list>

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

const int maxn = 10000 + 5;
const int maxlen = 51;
const int maxtlen = 1000000 + 5;
const int maxnode = maxn * maxlen;
const int sigma_size = 26;

struct AC_automation {
	int sz;
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int fail[maxnode];

	void init() {
		memset(ch[0],0,sizeof(ch[0]));
		fail[0] = val[0] = 0;
		sz = 1;
	}

	inline int idx(char c) {
		return c - 'a';
	}

	void insert(char *str) {
		int len = strlen(str),u = 0;
		for(int i = 0;i < len;i++) {
			int c = idx(str[i]);
			if(ch[u][c] == 0) {
				memset(ch[sz],0,sizeof(ch[sz]));
				fail[sz] = val[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		val[u]++;
	}

	void construct() {
		queue<int> q;
		int u = 0;
		for(int i = 0;i < sigma_size;i++) if(ch[u][i]) {
			fail[ ch[u][i] ] = 0;
			q.push(ch[u][i]);
		}
		while(!q.empty()) {
			u = q.front(); q.pop();
			for(int i = 0;i < sigma_size;i++) {
				int &v = ch[u][i];
				if(v) {
					q.push(v);
					fail[v] = ch[ fail[u] ][i];
				} else {
					v = ch[ fail[u] ][i];
				}
			}
		}
	}

	int query(char *str) {
		int len = strlen(str),u = 0;
		int ans = 0;
		for(int i = 0;i < len;i++) {
			int c = idx(str[i]);
			u = ch[u][c];
			int v = u;
			while(v && val[v] != 0) {
				ans += val[v];
				val[v] = 0;
				v = fail[v];
			}
		}
		return ans;
	}
};

char word[maxlen],T[maxtlen];
AC_automation ac;

int main() {
	int kase; scanf("%d",&kase);
	while(kase--) {
		ac.init();
		int n; scanf("%d",&n);
		for(int i = 0;i < n;i++) {
			scanf("%s",word);
			ac.insert(word);
		}
		ac.construct();
		scanf("%s",T);
		printf("%d\n",ac.query(T));
	}
	return 0;
}


