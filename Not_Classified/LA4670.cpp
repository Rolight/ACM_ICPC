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

const int maxn = 155;
const int maxlen = 71;
const int maxtlen = 1000000 + 5;
const int maxnode = maxn * maxlen;
const int sigma_size = 26;

struct AC_automation {
	int ch[maxnode][sigma_size],val[maxnode],fail[maxnode];
	int sz;

	void init() {
		sz = 1; memset(ch[0],0,sizeof(ch[0]));
	}

	inline int idx(char c) {
		return c - 'a';
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
		if(!val[u]) val[u] = id;
	}

	void construct() {
		queue<int> q;
		int u = 0;
		for(int i = 0;i < sigma_size;i++) if(ch[u][i]) q.push(ch[u][i]);
		while(!q.empty()) {
			u = q.front(); q.pop();
			for(int i = 0;i < sigma_size;i++) {
				int &v = ch[u][i];
				if(v) {
					fail[v] = ch[fail[u]][i];
					q.push(v);
				} else v = ch[fail[u]][i];
			}
		}
	}

	void work(char *str,int cnt[]) {
		int len = strlen(str),u = 0;
		for(int i = 0;i < len;i++) {
			int c = idx(str[i]);
			u = ch[u][c];
			int v = u;
			while(v && val[v]) {
				cnt[val[v]]++;
				v = fail[v];
			}
		}
	}
};

int cnt[maxn];
char buf[maxn][maxlen],t[maxtlen];
AC_automation ac;

int main() {
	int n;
	while(scanf("%d",&n),n) {
		ac.init();
		for(int i = 1;i <= n;i++) {
			scanf("%s",buf[i]);
			ac.insert(buf[i],i);
		}
		ac.construct();
		memset(cnt,0,sizeof(cnt));
		scanf("%s",t);
		ac.work(t,cnt);
		int best = 0;
		for(int i = 1;i <= n;i++) best = max(best,cnt[i]);
		printf("%d\n",best);
		for(int i = 1;i <= n;i++) if(cnt[i] == best) puts(buf[i]);
	}
	return 0;
}


