#include <cstdio>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <map>
#include <cctype>
#include <ctime>
#include <set>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <string>
#include <list>

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

#define max(a,b) (((a)>(b))?(a):(b))

const int maxn = 100005;
int f[maxn],val[105];
int ans = 0;

void ZeroOnePack(int C,int W,int V) {
	for(int i = V;i >= C;i--) {
		f[i] = max(f[i],f[i-C]+W);
	}
}

void CompletePack(int C,int W,int V) {
	for(int i = C;i <= V;i++) {
		f[i] = max(f[i],f[i-C]+W);
	}
}

void MultiPack(int C,int W,int V,int M) {
	if(M * C >= V) {
		CompletePack(C,W,V);
	} else {
		int k = 1;
		while(M >= k) {
			ZeroOnePack(C * k,W * k,V);
			M -= k;
			k <<= 1;
		}
		ZeroOnePack(M * C,M * W,V);
	}
}

int main() {
    //freopen("in.txt","r",stdin);
	int n,m,vv;
	while(scanf("%d%d",&n,&m) != EOF) {
		memset(f,0,sizeof(f));
		for(int i = 1;i <= n;i++) {
			scanf("%d",&val[i]);
		}
		for(int i = 1;i <= n;i++) {
			scanf("%d",&vv);
			MultiPack(val[i],val[i],m,vv);
		}
		int ans = 0;
		for(int i = 1;i <= m;i++) {
			if(f[i] == i) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}


