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

const int maxn = 1000 + 5;
const int maxlen = 55;
const int maxtlen = 2000000 + 5;
const int maxnode = maxn * maxlen;
const int sigma_size = 128;

int cnt[maxn];
char buf[maxn][maxlen];
char t[maxtlen];

struct AC_automation {
	int ch[maxnode][sigma_size],val[maxnode];
	int sz,fail[maxnode];
	
	void init() {
		sz = 1; memset(ch[0],0,sizeof(ch[0]));
	}

	inline int idx(char c) {
		return c;
	}

	void insert(char *str,int id) {
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
		val[u] = id;
	}

	void construct() {
		queue<int> q;
		int u = 0;
		for(int i = 0;i < sigma_size;i++) {
			if(ch[u][i]) {
				q.push(ch[u][i]);
				fail[ch[u][i]] = 0;
			}
		}

		while(!q.empty()) {
			u = q.front(); q.pop();
			for(int i = 0;i < sigma_size;i++) {
				int &v = ch[u][i];
				if(v) {
					fail[v] = ch[fail[u]][i];
					q.push(v);
				} else {
					v = ch[fail[u]][i];
				}
			}
		}
	}

	void query(char *str) {
		memset(cnt,0,sizeof(cnt));
		int len = strlen(str),u = 0;
		for(int i = 0;i < len;i++) {
			int c = idx(str[i]);
			u = ch[u][c];
			int v = u;
			while(v && val[v] != 0) {
				cnt[val[v]]++;
				v = fail[v];
			}
		}
	}
};

AC_automation ac;

int main() {
	int n;
	while(~scanf("%d",&n)) {
		getchar();
		ac.init();
		for(int i = 1;i <= n;i++) {
			gets(buf[i]);
			ac.insert(buf[i],i);
		}
		ac.construct();
		gets(t);
		ac.query(t);
		for(int i = 1;i <= n;i++) if(cnt[i]) {
			printf("%s: %d\n",buf[i],cnt[i]);
		}
	}
	return 0;
}


