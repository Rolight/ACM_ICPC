#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 1004;
char mat[maxn][maxn];
int n,m,lb[maxn],rb[maxn],h[maxn];

int main() {
	int t; scanf("%d",&t);
	while(t--) {
		memset(h,0,sizeof(h));
		int ans = 0;
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i++) {
			h[0] = h[m + 1] = -1;
			for(int j = 1;j <= m;j++) {
				scanf(" %c",&mat[i][j]);
				lb[j] = rb[j] = j;
				if(mat[i][j] == 'F') h[j]++;
				else h[j] = 0;
			}
			for(int j = 1;j <= m;j++) {
				int k = m - j + 1;
				while(h[lb[j] - 1] >= h[j]) lb[j] = lb[lb[j] - 1];
				while(h[rb[k] + 1] >= h[k]) rb[k] = rb[rb[k] + 1];
			}
			for(int j = 1;j <= m;j++) ans = max(ans,h[j] * (rb[j] - lb[j] + 1));
		}
		printf("%d\n",ans * 3);
	}
	return 0;
}
