#include <cstdio>
#include <cstring>

#define M ((L+R)>>1)
#define lson rt<<1,L,M
#define rson rt<<1|1,M+1,R

using namespace std;

const int maxn = 100001;

int sumv[maxn << 2],setv[maxn << 2],l,r,v;

inline void pushup(int rt) {
	sumv[rt] = sumv[rt<<1] + sumv[rt<<1|1];
}

inline void pushdown(int rt,int L,int R) {
	if(~setv[rt]) {
		setv[rt<<1] = setv[rt<<1|1] = setv[rt];
		sumv[rt] = setv[rt] * (R - L + 1);
		setv[rt] = -1;
	}
}	

void build(int rt,int L,int R) {
	if(L == R) sumv[rt] = 1;
	else {
		build(lson); build(rson);
		pushup(rt);
	}
}

void update(int rt,int L,int R) {
	if(l <= L && r >= R) {
		setv[rt] = v;
		sumv[rt] = setv[rt] * (R - L + 1);
	} else {
		pushdown(rt,L,R);
		if(l <= M) update(lson);
		if(r > M) update(rson);
		pushup(rt);
	}
}

int main() {
	int T,N,Q;
	scanf("%d",&T);
	for(int c = 1;c <= T;c++) {
		scanf("%d%d",&N,&Q);
		memset(setv,-1,sizeof(setv));
		build(1,1,N);
		for(int i = 0;i < Q;i++) {
			scanf("%d%d%d",&l,&r,&v);
			update(1,1,N);
		}
		printf("%d\n",sumv[1]);
	}
	return 0;
}
