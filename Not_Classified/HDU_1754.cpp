#include <cstdio>
#include <climits>

using namespace std;

#define M ((L+R)>>1)
#define lson rt<<1,L,M
#define rson rt<<1|1,M+1,R
#define root 1,1,N
#define max(a,b) ((a>b)?a:b)

const int maxn = 200001;

int maxv[maxn << 2],ql,qr,tar,v,val[maxn];

inline void pushup(int rt) {
	maxv[rt] = max(maxv[rt<<1],maxv[rt<<1|1]);
}

void build(int rt,int L,int R) {
	if(L == R) maxv[rt] = val[L];
	else {
		build(lson); build(rson);
		pushup(rt);
	}
}

void update(int rt,int L,int R) {
	if(L == R) maxv[rt] = v;
	else {
		if(tar <= M) update(lson);
		if(tar > M) update(rson);
		pushup(rt);
	}
}

int query(int rt,int L,int R) {
	if(ql <= L && qr >= R) return maxv[rt];
	int lv = -INT_MAX,rv = -INT_MAX;
	if(ql <= M) lv = query(lson);
	if(qr > M) rv = query(rson);
	return max(lv,rv);
}

int main() {
	int N,m; 
	char cmd;
	while(~scanf("%d%d",&N,&m)) {
		for(int i = 1;i <= N;i++) scanf("%d",val + i);
		build(root);
		for(int i = 1;i <= m;i++) {
			scanf(" %c",&cmd);
			if(cmd == 'Q') {
				scanf("%d%d",&ql,&qr);
				printf("%d\n",query(root));
			} else {
				scanf("%d%d",&tar,&v);
				update(root);
			}
		}
	}
	return 0;
}
