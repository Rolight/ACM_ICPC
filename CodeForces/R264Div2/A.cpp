#include <cstdio>
#include <algorithm>

using namespace std;


int main() {
	int n,s; scanf("%d%d",&n,&s);
	s *= 100;
	int ans = -1;
	for(int i =  0;i < n;i++) {
		int d,c; scanf("%d%d",&d,&c);
		int jj = d * 100 + c, jja = (d + (int)(c > 0)) * 100, jj1 = jja - jj;
		if(s >= jja) {
			ans = max(ans,s / jja * (jj1 % 100));
		}
	}
	printf("%d\n",ans);
	return 0;
}
