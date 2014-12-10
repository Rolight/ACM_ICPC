#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

long long work(unsigned int b,unsigned int x,unsigned int t,unsigned int c) {

	return 0;
}

int main() {
#define int unsigned int
	int a,b,w,x,c,t;
	while(~scanf("%u%u%u%u%u",&a,&b,&w,&x,&c)) {
		long long ans = 0;
		t = w - x;
		if(b > c) {
			printf("0\n"); continue;
		}
		if(b >= x) {
			ans += (b / x) + 1;
			c -= (b / x) + 1; b %= x;
		}
		ans += work(b,x,t,c);
		printf("%d\n",ans);
	}
#undef int
	return 0;
}
