#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxv = 200001,maxn = 201;

int f[maxv],V;

void ZeroOnePack(int C,int W) {
	for(int i = V;i >= C;i--) f[i] = max(f[i],f[i - C] + W);
}

void CompletePack(int C,int W) {
	for(int i = C;i <= V;i++) f[i] = max(f[i],f[i - C] + W);
}

void MultiplePack(int C,int W,int M) {
	if(C * M >= V) CompletePack(C,W);
	else {
		int k = 1;
		while(k < M) {
			ZeroOnePack(C * k,W * k);
			M -= k; k *= 2;
		}
		ZeroOnePack(C * M,W * M);
	}
}

int main() {
	int n;
	scanf("%d%d",&n,&V);
	for(int i = 0;i < n;i++) {
		int C,W,M;
		scanf("%d%d%d",&C,&W,&M);
		if(M == -1) CompletePack(C,W);
		else MultiplePack(C,W,M);
	}
	printf("%d\n",f[V]);
	return 0;
}
