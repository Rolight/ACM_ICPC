#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 200001;
int f[maxn],v[maxn],v1[maxn];

int maxbsum(int A[],int n) {
	int maxt = 0,ans = 0;
	memset(f,0,sizeof(int) * n);
	for(int i = 0;i < n;i++) {
		f[i] = maxt + A[i];
		if(i > 0) maxt = max(maxt,f[i - 1]);
		ans = max(ans,f[i]);
	}
	return ans;
}

int main() {
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				scanf("%d",&v[j]);
			}
			v1[i] = maxbsum(v,m);
		}
		printf("%d\n",maxbsum(v1,n));
	}
	return 0;
}
