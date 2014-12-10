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

const int maxn = 25;
const int maxlen = 105;
const int sigma_size = 26 + 26 + 10;
const int maxnode = maxn * maxlen;

inline int idx(char c) {
	if(c >= 'a' && c <= 'z') return c - 'a';
	if(c >= 'A' && c <= 'Z') return c - 'A' + 26;
	return c - '0' + 26 + 26;
}

double p[sigma_size];
double note[maxnode][105];
bool vis[maxnode][105];
int S;

struct AC_automation {
	int ch[maxnode][sigma_size],fail[maxnode],val[maxnode];
	int sz;

	void init() {
		memset(ch[0],0,sizeof(ch[0]));
		sz = 1;
		fail[0] = 0;
	}

	void insert(char *str) {
		int len = strlen(str),u = 0;
		for(int i = 0;i < len;i++) {
			int c = idx(str[i]);
			if(ch[u][c] == 0) {
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		val[u] = 1;
	}

	void construct() {
		queue<int> q;
		int u = 0;
		for(int i = 0;i < sigma_size;i++) {
			if(ch[u][i] != 0) {
				q.push(ch[u][i]); fail[ch[u][i]] = 0;
			}
		}

		while(!q.empty()) {
			u = q.front(); q.pop();
			for(int i = 0;i < sigma_size;i++) {
				int &v = ch[u][i];
				if(v != 0) {
					fail[v] = ch[fail[u]][i];
					q.push(v);
					int tmp = v;
					while(tmp) {
						val[v] |= val[tmp];
						tmp = fail[tmp];
					}
				} else {
					v = ch[fail[u]][i];
				}
			}
		}
	}

	double work(int u,int deep) {
		double ans = 0;
		if(deep == S + 1) return 1;
		if(val[u] == 1) return 0;
		if(vis[u][deep]) return note[u][deep];
		vis[u][deep] = true;
		for(int i = 0;i < sigma_size;i++) {
			if(p[i] > 0) {
				ans += p[i] * work(ch[u][i],deep + 1);
			}
		}
		return note[u][deep] = ans;
	}

	
};

AC_automation ac;
char word[maxlen];

int main() {
	int T,n,kase = 1; scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		ac.init();
		memset(vis,0,sizeof(vis));
		for(int i = 0;i < sigma_size;i++) p[i] = -INF;
		for(int i = 0;i < n;i++) {
			scanf("%s",word);
			ac.insert(word);
		}
		scanf("%d",&n);
		for(int i = 0;i < n;i++) {
			char c; scanf(" %c",&c);
			scanf("%lf",&p[idx(c)]);
		}
		scanf("%d",&S);	
		ac.construct();
		printf("Case #%d: %lf\n",kase++,ac.work(0,0));
	}
	return 0;
}


