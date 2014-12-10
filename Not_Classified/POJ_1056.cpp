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

const int maxn = 105;
const int maxlen = 205;
const int maxnode = maxn * maxlen + 5;
const int sigma_size = 2;
char dict[maxn][maxlen];
bool dok = true;


struct Trie {
	int ch[maxnode][sigma_size],val[maxnode * sigma_size],sz;
	Trie() {
		sz = 1; memset(ch[0],0,sizeof(ch[0]));
	}

	void clear() {
		sz = 1; memset(ch,0,sizeof(ch));
		memset(val,0,sizeof(val));
	}

	inline int idx(char c) {
		return c - '0';
	}
	
	void insert(char *str) {
		int len = strlen(str);
		int u = 0;
		for(int i = 0;i < len;i++) {
			int c = idx(str[i]);
			if(ch[u][c] == 0) {
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		if(val[u] == 0) {
			val[u] = 1;
		} else dok = false;
	}

	bool query(char *str) {
		int len = strlen(str);
		int u = 0;
		for(int i = 0;i < len;i++) {
			int c = idx(str[i]);
			if(val[u] == 1) return false;
			u = ch[u][c];
		}
		return true;
	}
};

Trie trie;

int main() {
	int kase = 1,cnt = 0;
	while(~scanf("%s",dict[cnt++])) {
		if(dict[cnt - 1][0] != '9') {
			trie.insert(dict[cnt - 1]);
		} else {
			bool ok = true;
			for(int i = 0;i < cnt - 1 && ok;i++) {
				ok = ok && trie.query(dict[i]);
			}
			if(ok && dok) {
				printf("Set %d is immediately decodable\n",kase++);
			} else {
				printf("Set %d is not immediately decodable\n",kase++);
			}
			dok = true;
			trie.clear();
			cnt = 0;
		}
	}
	return 0;
}


