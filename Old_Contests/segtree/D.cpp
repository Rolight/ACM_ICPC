#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 200001

int maxv[maxn << 2],w[maxn],H,W,N;

int max(int a,int b) {
	return (a > b) ? a : b;
}

void build(int o,int L,int R) {
	if(L == R) maxv[o] = W;
	else {
		int M = (L + R) / 2;
		build(o * 2,L,M);
		build(o * 2 + 1,M + 1,R);
		maxv[o] = W;
	}
}

void update(int o,int tar,int val,int L,int R) {
	if(L == R) maxv[o] = val;
	else {
		int M = (L + R) / 2;
		if(tar <= M) update(o * 2,tar,val,L,M);
		else update(o * 2 + 1,tar,val,M + 1,R);
		maxv[o] = max(maxv[o * 2],maxv[o * 2 + 1]);
	}
}

/*
int query(int o,int L,int R,int ql,int qr) {
	int ans = 0,M = (L + R) / 2;
	if(ql <= L && qr >= R) return maxv[o];
	if(ql <= M) ans = max(ans,query(o * 2,L,M,ql,qr));
	if(qr > M) ans = max(ans,query(o * 2 + 1,M + 1,R,ql,qr));
	return ans;
}
*/

void insert(int val) {
	int L = 1,R = H,o = 1;
	while(L <= R) {
		if(L == R) {
			if(maxv[o] >= val) {
				update(1,L,maxv[o] - val,1,H);
				printf("%d\n",L);
			} else
				printf("-1\n");
			return;
		} else {
			int M = (L + R) / 2;
			if(maxv[o * 2] >= val) R = M,o *= 2;
			else L = M + 1,o = o * 2 + 1;
		}
	}
	printf("-1\n");
}

int main() {
	while(scanf("%d%d%d",&H,&W,&N) == 3){
		if(H >= N) H = N;
		build(1,1,H);
		while(N--) {
			int now;
			scanf("%d",&now);
			insert(now);
		}
	}
	return 0;
}
