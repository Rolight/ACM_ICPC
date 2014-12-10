#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 1001;
int v[maxn],w[maxn],f[maxn];

using namespace std;

int main() {
	int T,N,V;
	scanf("%d",&T);
	while(T--) {
		memset(f,0,sizeof(f));
		scanf("%d%d",&N,&V);
		for(int i = 1;i <= N;i++) scanf("%d",w + i);
		for(int i = 1;i <= N;i++) scanf("%d",v + i);
		for(int i = 1;i <= N;i++) 
			for(int j = V;j >= v[i];j--)
				f[j] = max(f[j - v[i]] + w[i],f[j]);
		printf("%d\n",f[V]);
	}
	return 0;
}
