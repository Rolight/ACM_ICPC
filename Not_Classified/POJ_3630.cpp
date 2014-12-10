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
const int maxlen = 11;
const int maxnode = maxn * maxlen;
const int sigma_size = 10;

char dict[maxn][maxlen];

struct Trie_Node {
	int next[sigma_size],val;
};

Trie_Node node[maxnode];
int trie_sz;

void init() {
	trie_sz = 1;
	memset(&node[0],0,sizeof(Trie_Node));
}

inline int idx(char c) {
	return c - '0';
}

bool insert(char *str) {
	int len = strlen(str);
	int u = 0;
	for(int i = 0;i < len;i++) {
		int c = idx(str[i]);
		if(node[u].next[c] == 0) {
			memset(&node[trie_sz],0,sizeof(Trie_Node));
			node[u].next[c] = trie_sz;
			node[trie_sz].val = 0;
			trie_sz++;
		}
		u = node[u].next[c];
	}
	if(node[u].val == 0) node[u].val = 1;
	else return false;
	return true;
}

bool query(char *str) {
	int len = strlen(str);
	int u = 0;
	for(int i = 0;i < len;i++) {
		int c = idx(str[i]);
		if(node[u].val == 1) return false;
		u = node[u].next[c];
	}
	return true;
}

int main() {
	int t,n; scanf("%d",&t);
	while(t--) {
		init();
		scanf("%d",&n);
		bool ok = true;
		for(int i = 0;i < n;i++) {
			scanf("%s",dict[i]);
			ok = ok && insert(dict[i]);
		}
		for(int i = 0;i < n;i++) {
			ok = ok && query(dict[i]);
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}


