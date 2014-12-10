#include <cstring>
#include <cstdio>
#include <algorithm>

const int maxn = 1001;
int f[maxn],num[maxn];

using namespace std;

int main() {
	int N;
	while(scanf("%d",&N),N) {
		int ans = 0;
		memset(f,0,sizeof(f));
		for(int i = 1;i <= N;i++) scanf("%d",num + i);
		for(int i = 1;i <= N;i++) {
			f[i] = num[i];
			for(int j = i - 1;j >= 1;j--) {
				if(num[j] < num[i]) {
					f[i] = max(f[i],f[j] + num[i]);
				}
			}
			if(f[i] > ans) ans = f[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
