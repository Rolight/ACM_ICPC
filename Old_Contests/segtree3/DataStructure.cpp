#include <cstdio>

using namespace std;

#define M ((L+R)>>1)
#define lson rt<<1,L,M
#define rson rt<<1|1,M+1,R

const int maxn = 262145;
const int size = maxn << 2;

int sumv[size],tar;

void build(int rt,int L,int R) {
	if(L == R) sumv[rt] = 1;
	else {
		build(lson); build(rson);
		sumv[rt] = sumv[rt<<1] + sumv[rt<<1|1];
	}
}

void update(int rt,int L,int R) {
	if(L == R) sumv[rt] = 0;
	else {
		if(tar <= M) update(lson);
		else update(rson);
		sumv[rt] = sumv[rt<<1] + sumv[rt<<1|1];
	}
}

int query(int t,int N) {
	int rt = 1,L = 1,R = N;
	while(L <= R) {
		if(L == R) return L;
		if(t <= sumv[rt<<1]) {
			R = M; rt = rt << 1;
		}
		else {
			L = M + 1; rt = rt<<1|1; t -= sumv[rt - 1];
		}
	}
}

int main() {
	int T,N,K;
	scanf("%d",&T);
	for(int c = 1;c <= T;c++) {
		unsigned long long sum = 0;
		scanf("%d%d",&N,&K);
		build(1,1,N);
		for(int i = 1;i <= K;i++) {
			scanf("%d",&tar);
			tar = query(tar,N);
			sum += tar;
			update(1,1,N);
		}
		printf("Case %d: %I64d\n",c,sum);
	}
	return 0;
}
