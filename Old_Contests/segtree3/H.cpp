#include <cstdio>

#define M ((L+R)>>1)
#define lson rt<<1,L,M
#define rson rt<<1|1,M+1,R

using namespace std;

const int maxn = 100001;

int sumv[maxn << 4],pos[maxn],tar,v,ql,qr;
int T,N,m;

inline void pushup(int rt) {
	sumv[rt] = sumv[rt<<1] + sumv[rt<<1|1];
}

void build(int rt,int L,int R) {
	if(L == R) {
		if(L > N) sumv[rt] = 1;
	} else {
		build(lson); build(rson);
		pushup(rt);
	}
}

void update(int rt,int L,int R) {
	if(L == R) sumv[rt] = v;
	else {
		if(tar <= M) update(lson);
		else update(rson);
		pushup(rt);
	}
}

int query(int rt,int L,int R) {
	if(ql <= L && qr >= R) return sumv[rt];
	else {
		int ans = 0;
		if(ql <= M) ans += query(lson);
		if(qr > M) ans += query(rson);
		return ans;
	}
}

int main() {
	scanf("%d",&T);
	while(T--) {
		int id,ans;
		scanf("%d%d",&N,&m);
		for(int i = 1;i <= N;i++) pos[i] = N + i;
		build(1,1,2 * N);
		for(int i = 1;i <= m;i++) {
			scanf("%d",&id);
			ql = 1; qr = pos[id] - 1;
			printf("%d\n",query(1,1,2 * N));
			tar = pos[id]; v = 0; update(1,1,2 * N);
			pos[id] = N - m;
			tar = pos[id]; v = 0; update(1,1,2 * N);
		}
	}
	return 0;
}
