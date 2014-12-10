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
const unsigned int INF = (unsigned int)INT_MAX + 5;
const int maxn = 4000000;
const int BIT = 31;
typedef unsigned int uint;
uint note[35];

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

struct Trie {
	int ch[maxn][2],sz;
	uint nn[maxn];
	void init() {
		memset(ch[0],0,sizeof(ch[0]));
		sz = 1;
		nn[0] = INF;
	}
	void insert(uint num) {
		int u = 0;
		for(int i = BIT;i >= 0;i--) {
			int c = ((num & note[i]) != 0LL);
			if(ch[u][c] == 0) {
				ch[sz][0] = ch[sz][1] = 0;
				nn[sz] = INF;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		nn[u] = num;
	}
	uint find(uint num) {
		num = ~num;
		int u = 0;
		uint ret = 0;
		for(int i = BIT;i >= 0;i--) {
			if(nn[u] != INF) ret = nn[u];
			if(ch[u][0] == ch[u][1] && ch[u][0] == 0) {
				return ret;
			}
			int c = ((num & note[i]) != 0LL);
			if(ch[u][c] != 0) {
				u = ch[u][c];
			} else u = ch[u][c^1];
		}
		return nn[u];
	}
};

Trie trie;

int main() {
	for(int i = 0;i <= 33;i++) note[i] = (1 << i);
	int T,N,M; scanf("%d",&T);
	for(int kase = 1;kase <= T;kase++) {
		scanf("%d%d",&N,&M);
		printf("Case #%d:\n",kase);
		trie.init();
		uint tmp;
		for(int i = 0;i < N;i++) {
			scanf("%u",&tmp);
			trie.insert(tmp);
		}
		for(int i = 0;i < M;i++) {
			scanf("%u",&tmp);
			printf("%u\n",trie.find(tmp));
		}
	}
	return 0;
}


