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

const int maxlens = 300005;
const int maxlen = 105;
const int maxn = 4005;
const int maxnode = maxn * maxlen;
const int sigma_size = 26;
const int MOD = 20071027;

struct tnode {
	int next[sigma_size];
	bool exist;
};

tnode node[maxnode];
int sz;
int d[maxlens];
char buf[maxlens],tmp[maxlen];

void init() {
	sz = 1; memset(&node[0],0,sizeof(tnode));
}

inline int idx(char c) {
	return c - 'a';
}

void insert(char *str) {
	int u = 0,len = strlen(str);
	for(int i = 0;i < len;i++) {
		int c = idx(str[i]);
		if(node[u].next[c] == 0) {
			memset(&node[sz],0,sizeof(tnode));
			node[u].next[c] = sz++;
		}
		u = node[u].next[c];
	}
	node[u].exist = true;
}

int main() {
	int kase = 1;
	while(~scanf("%s",buf)) {
		memset(d,0,sizeof(d));
		init();
		int n; scanf("%d",&n);
		for(int i = 0;i < n;i++) {
			scanf("%s",tmp);
			insert(tmp);
		}
		int len = strlen(buf);
		d[len] = 1;
		for(int i = len - 1;i >= 0;i--) {
			int u = 0;
			for(int j = i;j < len;j++) {
				int c = idx(buf[j]);
				if(node[u].next[c] == 0) break;
				u = node[u].next[c];
				if(node[u].exist) {
					d[i] = (d[i] + d[j + 1]) % MOD;
				}
			}
		}
		printf("Case %d: %d\n",kase++,d[0]);
	}
	return 0;
}


