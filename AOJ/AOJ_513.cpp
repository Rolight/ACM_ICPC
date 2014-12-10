#include <cstdio>

using namespace std;

inline int min(long long a,long long b) {
	return (a < b) ? a : b;
}

int main() {
	int co,cx,mo,mx;
	while(scanf("%d%d%d%d",&co,&cx,&mo,&mx) != EOF) {
		long long ans = 0,so,sx;
		if(mo >= co) mo = co;
		if(mo == 0) co = 0;
		if(mx >= cx) mx = cx;
		if(mx == 0) cx = 0;
		ans += min(co,cx) * 2;
		if(co - min(co,cx)) 
			ans += min((long long)(mo - 1) * cx + mo,(long long)co - min(co,cx));
		if(cx - min(co,cx)) 
			ans += min((long long)(mx - 1) * co + mx,(long long)cx - min(co,cx));
		printf("%d\n",ans);
	}
	return 0;
}
