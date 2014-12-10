#include <cstdio>

#define lson rt<<1,L,M
#define rson rt<<1|1,M + 1,R

using namespace std;

const int maxn = 50001;
int sum[maxn << 2],ql,qr,val[maxn],v,tar;

inline void pushup(int rt) {
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int rt,int L,int R) {
	if(L == R) sum[rt] = val[L];
	else {
		int M = (L + R) >> 1;
		build(lson); build(rson);
		pushup(rt);
	}
}

void update(int rt,int L,int R) {
	if(L == R) sum[rt] += v;
	else {
		int M = (L + R) >> 1;
		if(tar <= M) update(lson);
		if(tar > M) update(rson);
		pushup(rt);
	}
}

int query(int rt,int L,int R) {
	if(ql <= L && qr >= R) return sum[rt];
	int M = (L + R) >> 1,ans = 0;
	if(ql <= M) ans += query(lson);
	if(qr > M) ans += query(rson);
	return ans;
}

int main() {
	int c,N;
	char cmd[10];
	scanf("%d",&c);
	for(int k = 1;k <= c;k++) {
		printf("Case %d:\n",k);
		scanf("%d",&N);
		for(int i = 1;i <= N;i++) scanf("%d",val + i);
		build(1,1,N);
		while(scanf("%s",cmd),cmd[0] != 'E') {
			if(cmd[0] == 'Q') {
				scanf("%d%d",&ql,&qr);
				printf("%d\n",query(1,1,N));
			} else {
				scanf("%d%d",&tar,&v);
				if(cmd[0] == 'S') v = -v;
				update(1,1,N);
			}
		}
	}
	return 0;
}
