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

const int maxn = 100000;
const int maxlen = 11;
const int maxnode = maxn * (maxlen - 1);
const int sigma_size = 26;

char buf[maxn + 1][maxlen];

struct tnode {
	int next[sigma_size],times,most,val,from;
	char letter;
};

tnode node[maxnode];
int path[15],top = 0;
int sz;


int main() {
	int n; scanf("%d",&n);
	//初始化trie树
	sz = 1;
	memset(&node[0],0,sizeof(tnode));
	node[0].from = -1;
	//处理输入
	for(int i = 1;i <= n;i++) {
		scanf("%s",buf[i]);
		//插入trie树
		int len = strlen(buf[i]),u = 0;
		top = 0;
		for(int j = 0;j < len;j++) {
			path[top++] = u;	//记录路径
			int c = buf[i][j] - 'a';
			if(node[u].next[c] == 0) {
				memset(&node[sz],0,sizeof(tnode));
				node[sz].letter = c;
				node[sz].from = -1;
				node[sz].most = sz;
				node[u].next[c] = sz++;
			}
			u = node[u].next[c];
		}
		if(node[u].times == 0) {
			node[u].val = i;
		}
		node[u].times++;
		//输出单词
		printf("%s\n",buf[node[node[u].most].val]);
		//更新节点自身
		if(node[u].times >= node[ node[u].most ].times) {
			node[u].most = u; node[u].from = -1;
		}
		while(top > 0) {
			//向上依次更新每一个经过的节点的最大子树
			int fa = path[--top];
			int fmost = node[fa].most;
			int umost = node[u].most;
			if(node[umost].times > node[fmost].times //子节点的最大频率值比父节点的大
					|| (node[umost].times == node[fmost].times && (node[u].letter <= node[fa].from))) //频率相等但是字典序靠前
			{
				node[fa].most = umost;
				node[fa].from = node[u].letter;
			} else break;
			u = fa;
		}
	}
	return 0;
}


