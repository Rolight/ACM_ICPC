#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100001;
int f[maxn][11];

int main() {
	int n;
	while(scanf("%d",&n),n) {
		int a,b,maxt = 0;
		memset(f,0,sizeof(f));
		for(int i = 1;i <= n;i++) {
			scanf("%d%d",&a,&b);
			f[b][a]++;
			if(b > maxt) maxt = b;
		}
		
		for(int i = 1;i <= 4;i++)
			for(int j = 0;j <= 10;j++) 
				if(j < 5 - i || j > 5 + i)
					f[i][j] = 0;
	
		for(int i = 1;i <= maxt;i++) {
			for(int j = 0;j <= 10;j++) {
				if(j == 0) 
					f[i][j] += max(f[i - 1][j],f[i - 1][j + 1]);
				else if(j == 10) 
					f[i][j] += max(f[i - 1][j],f[i - 1][j - 1]);
				else f[i][j] += max(f[i - 1][j],
					max(f[i - 1][j - 1],f[i - 1][j + 1]));
			}
		}
		int ans = 0;
		for(int i = 0;i <= 10;i++) ans = max(ans,f[maxt][i]);
		printf("%d\n",ans);
	}
	return 0;
}
