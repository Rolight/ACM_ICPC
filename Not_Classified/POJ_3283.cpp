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

const int sigma_size = 134;

inline int tail_idx(char c) {
	switch(c) {
		case 'C': return 0;
		case 'D': return 1;
		case 'H': return 2;
		case 'S': return 3;
	}
	return 0;
}

inline int idx(char *str) {
	int len = strlen(str);
	if(len == 3) return 100 + tail_idx(str[2]);
	int ans = 0,pre = -1;
	char cpre;
	sscanf(str,"%d",&pre);
	if(pre != -1) return pre * 10 + tail_idx(str[1]);
	sscanf(str,"%c",&cpre);
	switch(cpre) {
		case 'A': ans = 1; break;
		case 'J': ans = 11; break;
		case 'Q': ans = 12; break;
		case 'K': ans = 13; break;
	}
	return ans * 10 + tail_idx(str[1]);
}

const int maxn = 100005;

struct Trie {
	int next[sigma_size];
} node[maxn];

char buf[maxn],now[15];
int sz;

void init() {
	sz = 1;
	memset(&node[0],0,sizeof(node));
}

void insert() {
	int len = strlen(buf);
	int pos = len - 1,u = 0;
	while(buf[pos] == ' ') pos--;
	while(buf[pos] != ' ' && pos >= 0) pos--;
	while(pos >= 0) {
		sscanf(buf + pos,"%s",now);
		int c = idx(now);
		if(node[u].next[c] == 0) {
			memset(&node[sz],0,sizeof(Trie));
			node[u].next[c] = sz;
			sz++;
		}
		pos--;
		while(buf[pos] != ' ' && pos >= 0) pos--;
		u = node[u].next[c];
	}
}

int main() {
	int n;
	while(scanf("%d",&n),n) {
		init();
		for(int i = 0;i < n;i++) {
			int ll; scanf("%d",&ll);
			gets(buf);
			insert();
		}
		printf("%d\n",sz - 1);
	}
	return 0;
}


