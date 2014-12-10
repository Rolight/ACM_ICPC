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
const int INF = INT_MAX / 4;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

const int maxn = 155;
struct Node {
	int cnt,ch[maxn],p,cc;
};

Node node[maxn];
int N,P,dp[maxn][maxn];

void dfs(int now,int sz) {
	dp[now][1] = 0;
	for(int i = 0;i < node[now].cnt;i++) {
		int chid = node[now].ch[i];
		dfs(chid,sz);
		for(int j = sz;j >= 1;j--) {
			int nret = INF;
			dp[now][j] = dp[now][j] + 1;
			for(int k = j-1;k >= 1;k--) {
				nret = min(dp[chid][k] + dp[now][j-k],nret);
			}
			dp[now][j] = min(nret,dp[now][j]);
		}
	}
} 

int main() {
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&N,&P) != EOF) {
		memset(node,0,sizeof(node));
		for(int i = 0;i < N - 1;i++) {
			int a,b; scanf("%d%d",&a,&b);
			node[a].ch[node[a].cnt++] = b;
			node[b].p = a;
		}
		int root = 0;
		for(int i = 1;i <= N;i++) {
			for(int j = 1;j <= N;j++) {
				dp[i][j] = INF;
			}
		}
		for(int i = 1;i <= N;i++) {
			if(node[i].p == 0) {
				root = i; break;
			}
		}
		dfs(root,P);
		int ans = dp[root][P];
		for(int i = 1;i <= N;i++) {
			if(i != root) {
				if(dp[i][P] + 1 < ans) {
					ans = dp[i][P] + 1;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
