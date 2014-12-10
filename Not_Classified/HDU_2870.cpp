#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1005;

int h[maxn],lb[maxn],rb[maxn];
char mat[maxn][maxn],ori[maxn][maxn];
char mapping[3][3] = {'a','w','y','b','w','x','c','x','y'};

void trans(int n,int m,char x) {
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			bool can = ori[i][j] == 'z';
			for(int k = 0;k < 3;k++) {
				if(ori[i][j] == mapping[x - 'a'][k]) can = true;
			}
			mat[i][j] = can ? x : ori[i][j];
		}
	}
}

int main() {
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		int ans = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				scanf(" %c",&ori[i][j]);
			}
		}
		for(char alph = 'a';alph <= 'c';alph++) {
			trans(n,m,alph);
			int ret = 0;
			memset(h,0,sizeof(h));
			h[0] = h[m + 1] = -1;
			for(int i = 1;i <= n;i++) {
				for(int j = 1;j <= m;j++) {
					lb[j] = rb[j] = j;
					if(mat[i][j] == alph) h[j]++;
					else h[j] = 0;
				}
				for(int j = 1;j <= m;j++) {
					int k = m - j + 1;
					while(h[lb[j] - 1] >= h[j]) lb[j] = lb[lb[j] - 1];
					while(h[rb[k] + 1] >= h[k]) rb[k] = rb[rb[k] + 1];
				}
				for(int j = 1;j <= m;j++) {
					ret = max(ret,h[j] * (rb[j] - lb[j] + 1));
				}
			}
			ans = max(ans,ret);
		}
		printf("%d\n",ans);
	}
}
