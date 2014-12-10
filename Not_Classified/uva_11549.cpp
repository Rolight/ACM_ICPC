#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int next(int k,int n) {
	long long s = (long long)n;
	s = s * s;
	int len = log10(s) + 1;
	while(k < len) {
		s /= 10;
		len--;
	}
	return s;
}

int main() {
	int T,n,k;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&k);
		int k1 = k,k2 = k,ans = k;
		do {
			k1 = next(n,k1);
			k2 = next(n,k2); if(k2 > ans) ans = k2;
			k2 = next(n,k2); if(k2 > ans) ans = k2;
		} while(k1 != k2);
		printf("%d\n",ans);
	}
	return 0;
}
