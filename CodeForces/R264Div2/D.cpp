#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 5;
const int maxk = 10;
int num[maxk][maxn];
int n,k;
bool ok[maxn],hou[maxn][maxn];
int f[maxn];

void calc(int num[maxn]) {
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j < i;j++) {
			hou[num[i]][num[j]] = false;
		}
	}
}

int main() {
	int ans = 0;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= k;i++) {
		for(int j = 1;j <= n;j++) {
			scanf("%d",&num[i][j]);
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = i + 1;j <= n;j++) {
			hou[num[1][i]][num[1][j]] = true;
		}
	}
	
	for(int kk = 2;kk <= k;kk++) {
		calc(num[kk]);
	}
	
	for(int i = 1;i <= n;i++) {
		f[i] = 1;
		for(int j = 1;j < i;j++) if(hou[num[1][j]][num[1][i]]) {
			f[i] = max(f[j] + 1,f[i]);
		}
		ans = max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}
