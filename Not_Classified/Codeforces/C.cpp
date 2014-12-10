#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 200001;
int f[maxn],sum[maxn],num[maxn];

int main() {
	int n;
	while(~scanf("%d",&n)) {
		memset(f,0,sizeof(f));
		memset(sum,0,sizeof(sum));
		for(int i = 1;i <= n;i++) {
			scanf("%d",num + i);
			sum[i] = sum[i - 1] + num[i];
			f[i] = sum[i - 1] + f[i - 1];
		}
		printf("%d\n",f[n]);
	}
	return 0;
}
