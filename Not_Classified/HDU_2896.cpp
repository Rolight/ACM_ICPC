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

const int maxn = 505;
const int maxlen = 205;
const int maxnode = maxn * maxlen;
const int maxTlen = 10000 + 5;
const int sigma_size = 128;

struct AC_automation {
	int ch[maxnode][sigma_size];
	int sz,fail[maxnode];
	int exist[maxnode];

	inline int idx(char c) {
		return c;
	}

	void init() {
		sz = 1; memset(ch[0],0,sizeof(ch[0]));
		fail[0] = exist[0] = 0;
	}

	void insert(char str[],int id) {
		int len = strlen(str),u = 0;
		for(int i = 0;i < len;i++) {
			int c = idx(str[i]);
			if(ch[u][c] == 0) {
				memset(ch[sz],0,sizeof(ch[0]));
				fail[sz] = exist[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		exist[u] = id;
	}

	void construct() {
		int u = 0;
		queue<int> q;
		for(int i = 0;i < sigma_size;i++) if(ch[u][i]) {
			q.push(ch[u][i]); fail[ch[u][i]] = 0;
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

	void query(char *str,vector<int> &ans) {
		int len = strlen(str), u = 0;
		ans.clear();
		for(int i = 0;i < len;i++) {
			int c = idx(str[i]);
			u = ch[u][c];
			int v = u;
			while(v && exist[v]) {
				ans.push_back(exist[v]);
				v = fail[v];
			}
		}
		sort(ans.begin(),ans.end());
		vector<int>::iterator iter = unique(ans.begin(),ans.end());
		ans.erase(iter,ans.end());
	}
};

AC_automation ac;
char word[maxlen],T[maxTlen];
vector<int> ans;

int main() {
	int n,m;
	while(~scanf("%d",&n)) {
		getchar();
		ac.init();
		int total = 0;
		for(int i = 0;i < n;i++) {
			gets(word);
			ac.insert(word,i + 1);
		}
		ac.construct();
		scanf("%d",&m);
		getchar();
		for(int i = 1;i <= m;i++) {
			gets(T);
			ac.query(T,ans);
			if(ans.size() != 0) {
				printf("web %d:",i);
				total++;
			}
			for(vector<int>::iterator iter = ans.begin();iter != ans.end();++iter) {
				printf(" %d",*iter);
			}
			if(ans.size() != 0) putchar('\n');
		}
		printf("total: %d\n",total);
	}
	return 0;
}


