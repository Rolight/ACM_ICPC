#include <cstdio>

#define lson rt<<1,L,M
#define rson rt<<1|1,M+1,R
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define len(a,b) ((b)-(a)+1)

using namespace std;

const int maxn = 100001;

int lmax[maxn << 2],rmax[maxn << 2],mmax[maxn << 2],val[maxn];

void build(int rt,int L,int R) {
	if(L == R) lmax[rt] = rmax[rt] = mmax[rt] = 1;
	else {
		int l = rt << 1,r = rt << 1 | 1,M = (L + R) >> 1;
		build(lson); build(rson);
		lmax[rt] = lmax[l]; rmax[rt] = rmax[r];
		mmax[rt] = 0;
		if(val[M] == val[M + 1]) {
			if(lmax[rt] == len(L,M)) lmax[rt] = len(L,M) + lmax[r];
			if(rmax[rt] == len(M + 1,R)) rmax[rt] = len(M + 1,R) + rmax[l];
			mmax[rt] = max(lmax[rt],rmax[rt]);
			mmax[rt] = max(mmax[rt],lmax[r] + rmax[l]);
		}
		mmax[rt] = max(mmax[rt],max(mmax[l],mmax[r]));
	}
}

int query(int rt,int L,int R,int ql,int qr) {
	if(L == R) return 1;
	else if(ql <= L && qr >= R) return mmax[rt];
	else {
		int M = (L + R) >> 1,ans = 0,l = rt << 1,r = rt << 1 | 1;
		if(ql > M) return query(rson,ql,qr);
		if(qr <= M) return query(lson,ql,qr);
		if(val[M] == val[M + 1]) ans = min(len(ql,M),rmax[l]) + min(len(M + 1,qr),lmax[r]);
		int left = query(lson,ql,M),right = query(rson,M + 1,qr);
		ans = max(ans,max(left,right));
		return ans;
	}
}

int main() {
	int N,Q,l,r;
	while(scanf("%d",&N),N) {
		scanf("%d",&Q);
		for(int i = 1;i <= N;i++) scanf("%d",val + i);
		build(1,1,N);
		for(int i = 1;i <= Q;i++) {
			scanf("%d%d",&l,&r);
			printf("%d\n",query(1,1,N,l,r));
		}
	}
	return 0;
}
