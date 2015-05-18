#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const int maxn = 13;
const int maxlen = 51;
const int INF = INT_MAX;

string str[maxn], sstr[maxn][maxn];

struct Node {
	int sublen;
	string str;
	Node (int sublen = INF, string str = "~"): sublen(sublen), str(str) {}
	bool operator < (const Node &x) const {
		if(x.sublen == sublen) return str < x.str;
		return sublen < x.sublen;
	}
	Node operator + (const Node &x) {
		return Node(sublen + x.sublen, str + x.str);
	}
};

int n, g[maxn][maxn], len[maxn];
Node f[1 << maxn][maxn];
bool vis[1 << maxn][maxn];

int calc(int a, int b) {
	int ret = 0;
	for(int i = 0; i < len[a]; i++)  {
		int nowlen = 0, j;
		for(j = 0; j < len[b] && i + j < len[a]; j++) {
			if(str[a][i + j] == str[b][j]) {
				nowlen++;
			}
			else {
				nowlen = 0;
				break;
			}
		}
		if(i + j == len[a]) ret = max(ret, nowlen);
	}
	sstr[a][b] = str[b].substr(ret);
	return ret;
}

Node dfs(int state, int tail) {
	Node &note = f[state][tail], ret;
	if(state == (1 << n) - 1) return note = Node(0, "");
	if(vis[state][tail]) return note;
	for(int i = 0; i < n; i++) if(!(state & (1 << i))) {
		if(tail == n) {
			ret = min(ret, Node(len[i], str[i]) + dfs(state | (1 << i), i));
		}
		else {
			ret = min(ret, Node(len[i] - g[tail][i], 
				sstr[tail][i]) + dfs(state | (1 << i), i));
		}
	}
	vis[state][tail] = true;
	return note = ret;
}

void gao() {
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; i++) len[i] = str[i].size();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) g[i][j] = len[i];
			else g[i][j] = calc(i, j);
		}
	}
	Node ans = dfs(0, n);
	cout << ans.str << endl;
}


int main() {
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i++) {
			cin >> str[i];
		}
		gao();
	}
	return 0;
}
