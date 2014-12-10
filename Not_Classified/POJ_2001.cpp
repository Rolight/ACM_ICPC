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
const int maxlen = 25;
const int sigma_size = 26;
const int maxnode = maxn * maxlen;

struct Trie_Node {
	int val,next[sigma_size];
};

char dict[maxn][maxlen];
Trie_Node node[maxnode];
int sz;

void init() {
	sz = 1;
	memset(&node[0],0,sizeof(Trie_Node));
}

void insert(char *str) {
	int len = strlen(str);
	int u = 0;
	for(int i = 0;i < len;i++) {
		int c = str[i] - 'a';
		if(node[u].next[c] == 0) {
			memset(&node[sz],0,sizeof(Trie_Node));
			node[sz].val = 0;
			node[u].next[c] = sz;
			sz++;
		}
		node[u].val++;
		u = node[u].next[c];
	}
	node[u].val++;
}

void find_prefix(char *str) {
	int len = strlen(str);
	int u = 0;
	for(int i = 0;i < len;i++) {
		int c = str[i] - 'a';
		if(node[u].val == 1) {
			for(int j = 0;j < i;j++) putchar(str[j]);
			putchar('\n');
			return;
		}
		u = node[u].next[c];
	}
	printf("%s\n",str);
}


int main() {
	init();
	int cnt = 0;
	while(~scanf("%s",dict[cnt])) {
		insert(dict[cnt]);
		cnt++;
	}
	for(int i = 0;i < cnt;i++) {
		printf("%s ",dict[i]);
		find_prefix(dict[i]);
	}
	return 0;
}


