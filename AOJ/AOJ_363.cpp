#include <cstdio>

#define min(a,b) ((a<b)?a:b)

using namespace std;


int m,n,arr[20][20],ans;

void dfs(int x,int y,int val) {
	if(x == n && y == m) {
		if(val > 0 && val < ans) ans = val;
	} else {
		if(x + 1 <= n) dfs(x + 1,y,val + arr[x + 1][y]);
		if(y + 1 <= m) dfs(x,y + 1,val + arr[x][y + 1]);
	}
}

int main() {
	while(~scanf("%d%d",&n,&m)) {
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				scanf("%d",&arr[i][j]);
		ans = 210000000;
		dfs(1,1,arr[1][1]);
		if(ans == 210000000) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
