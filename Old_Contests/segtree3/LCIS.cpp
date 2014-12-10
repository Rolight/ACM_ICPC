#include <cstdio>

using namespace std;

#define M ((L+R)>>1)
#define lson rt<<1,L,M
#define rson rt<<1|1,M+1,R
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define len(a,b) ((b)-(a)+1)

const int maxn = 100001;
const int sizen = maxn << 2;

int lmax[sizen],rmax[sizen],val[maxn],mmax[sizen],tar,v;

inline void pushup(int rt,int L,int R) {
	int l = rt<<1,r = rt<<1|1;
	lmax[rt] = lmax[l]; rmax[rt] = rmax[r];
	mmax[rt] = 0;
	if(val[M] < val[M + 1]) {
		if(lmax[l] == len(L,M)) lmax[rt] += lmax[r];
		if(rmax[r] == len(M + 1,R)) rmax[rt] += rmax[l];
		mmax[rt] = max(lmax[rt],rmax[rt]);
		mmax[rt] = max(mmax[rt],rmax[l] + lmax[r]);
	}
	mmax[rt] = max(mmax[rt],max(mmax[l],mmax[r]));
}

void build(int rt,int L,int R) {
	if(L == R) {
		lmax[rt] = rmax[rt] = mmax[rt] = 1;
	} else {
		build(lson); build(rson);
		pushup(rt,L,R);
	}
}

void update(int rt,int L,int R) {
	if(L == R) val[L] = v;
	else {
		if(tar <= M) update(lson);
		else update(rson);
		pushup(rt,L,R);
	}
}

int query(int rt,int L,int R,int ql,int qr) {
	if(ql == L && qr == R) return mmax[rt];
	int l = rt<<1,r = rt<<1|1;
	if(qr <= M) return query(lson,ql,qr);
	if(ql > M) return query(rson,ql,qr);
	int ans = 0,left = query(lson,ql,M),right = query(rson,M + 1,qr);
	ans = max(left,right);
	if(val[M] < val[M + 1]) ans = max(ans,min(len(ql,M),rmax[l]) + min(len(M + 1,qr),lmax[r]));
	return ans;
}

int main() {
	int T,N,Q,l,r;
	char cmd;
	scanf("%d",&T);
	for(int c = 1;c <= T;c++) {
		scanf("%d%d",&N,&Q);
		for(int i = 1;i <= N;i++) scanf("%d",val + i);
		build(1,1,N);
		for(int q = 0;q < Q;q++) {
			scanf(" %c%d%d",&cmd,&l,&r);
			l++; r++;
			if(cmd == 'Q') printf("%d\n",query(1,1,N,l,r));
			else {
				tar = l; v = r - 1;
				update(1,1,N);
			}
		}
	}
	return 0;
}

