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



const int maxn = 4002;
const int maxlen = 1001;
const int maxnode = maxn * maxlen;

struct Trie {
	int head[maxnode];	//左儿子的编号
	int next[maxnode];	//右兄弟的编号
	int cnt[maxnode];	//节点出现过的次数
	char ch[maxnode];	//节点的字符
	int sz;
	LL ans;

	//初始化字典树
	void init() {
		sz = 1; head[0] = next[0] = cnt[0] = 0;
	}

	//插入字符串，一边插入一边更新ans值
	void insert(char *str) {
		int len = strlen(str),u = 0,v;	//一开始在根节点在
		cnt[0]++;
		for(int i = 0;i <= len;i++) {
			char c = str[i];
			//查找兄弟中有没有出现这个节点
			bool found = false;
			for(v = head[u];v != 0;v = next[v]) {
				if(ch[v] == c) {	//找到了
					found = true;
					break;
				}
			}
			//如果没有找到这个节点，则添加这个节点
			if(!found) {
				v = sz++;
				cnt[v] = 0;
				ch[v] = c;
				head[v] = 0;
				next[v] = head[u];
				head[u] = v;
			}
			u = v;
			cnt[u]++;
		}
	}

	void getans() {
		ans = 0;
		stack<int> s;
		int u = 0;
		s.push(u);
		while(!s.empty()) {
			u = s.top(); s.pop();
			LL sum = 0;
			for(int v = head[u];v != 0;v = next[v]) {
				sum += cnt[v] * (cnt[u] - cnt[v]);
				ans += cnt[v] * (cnt[v] - 1);
				if(head[v]) s.push(v);
			}
			ans += sum / 2;
		}
	}
};

char buf[maxlen];
Trie trie;

int main() {
	int kase = 1,n;
	while(scanf("%d",&n),n) {
		trie.init();
		for(int i = 0;i < n;i++) {
			scanf("%s",buf);
			if(i == 1) trie.ans = 0;
			trie.insert(buf);
		}
		trie.getans();
		printf("Case %d: %lld\n",kase++,trie.ans);
	}
	return 0;
}
