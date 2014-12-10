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
	freopen(INPUT_FILE, "r", stdin);
	freopen(OUTPUT_FILE, "w", stdout);
}
const int N = 205;
const int M = N;
struct ArcNode{
	int u, v;
}edge[M];
bool use[N],used[N];
int n, nxt, lp, mdeep;
int u, v,cantuse;

int dfs(int x, int deep){
	if (deep > mdeep){
		mdeep = deep;
		lp = x;
	}
	for (int i = 1; i < n; i++){
		if (i == cantuse)continue;
		if (edge[i].u == x && !use[edge[i].v]){
			use[edge[i].v] = true;
			dfs(edge[i].v, deep + 1);
			use[edge[i].v] = false;
		}
		if (edge[i].v == x && !use[edge[i].u]){
			use[edge[i].u] = true;
			dfs(edge[i].u, deep + 1);
			use[edge[i].u] = false;
		}
	}
}
int d(int st){
	lp = 0;
	mdeep = 0;
	memset(use, 0, sizeof(use));
	use[st] = true;
	dfs(st, 0);
	mdeep = 0;
	memset(use, 0, sizeof(use));
	use[lp] = true;
	dfs(lp, 0);
	return mdeep;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		edge[i].u = u;
		edge[i].v = v;
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		cantuse = i;
		ans = max(ans, d(edge[i].u) * d(edge[i].v));
	}
	printf("%d\n", ans);
}
