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

const int maxn = 205;
const int maxk = 35;

inline int abs(int a) {
	return (a < 0) ? -a : a;
}

int f[maxn][maxk];
int cost[maxn][maxn];
int dis[maxn],sum[maxn];

int main() {
	int n,K,kase = 1;
	while(scanf("%d%d",&n,&K),n || K) {
		for(int i = 1;i <= n;i++) {
			scanf("%d",&dis[i]);
		}
		memset(cost,0,sizeof(cost));
		memset(f,0,sizeof(f));
		for(int i = 1;i <= n;i++) {
			for(int j = i + 1;j <= n;j++) {
				int pos = dis[(i + j) / 2];
				for(int k = i;k <= j;k++) {
					cost[i][j] += abs(pos - dis[k]);
				}
			}
		}
		for(int i = 1;i <= n;i++) {
			for(int k = 1;k <= min(K,i);k++) {
				int minv = INF;
				if(k == 1) {
					f[i][k] = cost[1][i];
					continue;
				}
				for(int j = i;j >= k;j--) {
					minv = min(f[j - 1][k - 1] + cost[j][i],minv);
				}
				f[i][k] = minv;
			}
		}
		printf("Chain %d\nTotal distance sum = %d\n\n",kase++,f[n][K]);
	}
	return 0;
}


