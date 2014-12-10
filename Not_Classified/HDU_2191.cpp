#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int f[200];

inline void ZeroOnePack(int C,int W,int V) {
	for(int i = V;i >= C;i--) {
		f[i] = max(f[i],f[i - C] + W);
	}
}

inline void CompletePack(int C,int W,int V) {
	for(int i = C;i <= W;i++) {
		f[i] = max(f[i],f[i - C] + W);
	}
}

inline void MultiPack(int C,int W,int V,int M) {
	if(C * M >= V) {
		CompletePack(C,W,V);
	} else {
		int k = 1;
		while(k < M) {
			ZeroOnePack(C * k,W * k,V);
			M -= k; k *= 2;
		}
		ZeroOnePack(C * M,W * M,V);
	}
}

int main() {
	int C,p,h,c,V,n;
	scanf("%d",&C);
	while(C--) {
		scanf("%d%d",&V,&n);
		memset(f,0,sizeof(f));
		for(int i = 0;i < n;i++) {
			scanf("%d%d%d",&p,&h,&c);
			MultiPack(p,h,V,c);
		}
		printf("%d\n",f[V]);
	}
	return 0;
}
