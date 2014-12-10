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

int n,k,ans;
char mp[10][10];
bool vis[10];

void dfs(int now,int nowk) {
	if(nowk == k) {
		ans++; return;
	}
	if(now == n + 1) return;
	for(int i = 1;i <= n;i++) {
		if(mp[now][i] == '#' && !vis[i]) {
			vis[i] = true;
			dfs(now + 1,nowk + 1);
			vis[i] = false;
		}
	}
	dfs(now + 1,nowk);
}

int main() {
	while(scanf("%d%d",&n,&k),~n) {
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				scanf(" %c",&mp[i][j]);
			}
		}
		memset(vis,0,sizeof(vis));
		ans = 0;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}


