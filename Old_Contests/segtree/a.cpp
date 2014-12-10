#include <cstdio>

#define maxn 50001
#define d(i) ((i)<<1)
#define dv(i) ((i)>>1)

using namespace std;

int T,N,p[maxn],sum[maxn * 4];

void build(int o,int L,int R) {
	if(L == R) sum[o] = p[L];
	else {
		int M = dv(L + R);
		build(d(o),L,M);
		build(d(o) + 1,M + 1,R);
		sum[o] = sum[d(o)] + sum[d(o) + 1];
	}
}

int query(int o,int ql,int qr,int L,int R) {
	int ans = 0,M = dv(L + R);
	if(ql <= L && qr >= R) return sum[o];
	if(ql <= M) ans += query(d(o),ql,qr,L,M);
	if(qr > M) ans += query(d(o) + 1,ql,qr,M + 1,R);
	return ans;
}

void update(int o,int tar,int val,int L,int R) {
	if(L == R) sum[o] = val;
	else {
		int M = dv(L + R);
		if(tar <= M) update(d(o),tar,val,L,M);
		else update(d(o) + 1,tar,val,M + 1,R);
		sum[o] = sum[d(o)] + sum[d(o) + 1];
	}
}

int main() {
	char cmd[50];
	int a,b,count;
	scanf("%d",&T);
	for(int count = 1;count <= T;count++) {
		printf("Case %d:\n",count);
		scanf("%d",&N);
		for(int i = 1;i <= N;i++) scanf("%d",p + i);
		build(1,1,N);
		while(1) {
			scanf("%s",cmd);
			if(cmd[0] == 'E') break;
			scanf("%d%d",&a,&b);
			switch(cmd[0]) {
				case 'Q': printf("%d\n",query(1,a,b,1,N)); break;
				case 'S': p[a] -= b; update(1,a,p[a],1,N); break;
				case 'A': p[a] += b; update(1,a,p[a],1,N); break;
			}
		}
	}
	return 0;
}
