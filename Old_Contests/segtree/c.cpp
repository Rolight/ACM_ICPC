#include <cstdio>
#include <cstring>
#define maxn 5001
using namespace std;
int a[maxn],seg[maxn << 2],inv;
void update(int o,int tar,int L,int R) {
	if(L == R) seg[o] = 1;
	else {
		int M = (L + R) / 2;
		if(tar <= M) update(o * 2,tar,L,M);
		else update(o * 2 + 1,tar,M + 1,R);
		seg[o] = seg[o * 2] + seg[o * 2 + 1];
	}
}
int query(int o,int ql,int qr,int L,int R) {
	int ans = 0,M = (L + R) / 2;
	if(ql <= L && qr >= R) return seg[o];
	if(ql <= M) ans += query(o * 2,ql,qr,L,M);
	if(qr > M) ans += query(o * 2 + 1,ql,qr,M + 1,R);
	return ans;
}
int main() {
	int N;
	while(scanf("%d",&N) == 1) {
		memset(seg,0,sizeof(seg));
		int ans = 0;
		for(int i = 1;i <= N;i++) {
			scanf("%d",a + i);
			a[i]++;
			ans += query(1,a[i],N,1,N);
			update(1,a[i],1,N);
		}
		inv = ans;
		for(int i = 1;i <= N;i++) {
			inv += N + 1 - 2 * a[i];
			if(inv < ans) ans = inv;
		}
		printf("%d\n",ans);
	}
	return 0;
}
