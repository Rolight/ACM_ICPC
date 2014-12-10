#include<stdio.h>
#include<string.h>

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"


void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

#define max(a,b) (((a)>(b))?(a):(b))
int val[105];
char f[105][100005];
int ans = 0;

int main() {
	int n,m,vv;
	while(scanf("%d%d",&n,&m),n&&m) {
		memset(f,-1,sizeof(f));
		f[0][0] = 0;
		int i;
		for(i = 1;i <= n;i++) {
			scanf("%d",&val[i]);
		}
		for(i = 1;i <= n;i++) {
			scanf("%d",&vv);
			for(int j = 0;j <= m;j++) {
				if(f[i-1][j] >= 0) f[i][j] = vv;
				if(f[i][j] > 0 && j+val[i] <= m) f[i][j+val[i]] = f[i][j]-1;
			}
		}
		int ans = 0;
		for(int i = 1;i <= m;i++) {
			if(f[n][i] != -1) ans++; 
		}
		printf("%d\n",ans);
	}
	return 0;
}


