#include <cstdio>
#include <cstring>

#define M ((L + R)>>1)
#define lson rt<<1,L,M
#define rson rt<<1|1,M+1,R
#define len(a,b) ((b)-(a)+1)
#define nul	-1

using namespace std;

const int maxn = 100001;

int sumv[maxn << 2],lmax[maxn << 2],rmax[maxn << 2],mmax[maxn << 2],set[maxn << 2];

inline void init() {
	memset(set,nul,sizeof(set));
}

inline void pushup(int rt,int L,int R) {
	int lo = rt << 1,rt = rt << 1 | 1;
	sumv[rt] = sumv[lo] + sumv[ro];
	lmax[rt] = lmax[lo]; rmax[rt] = rmax[ro];
	mmax[rt] = max(mmax[lo],mmax[ro]);
	if(val[M] == val[M + 1] && val[M]) {
		if(lmax[lo] == sum[lo]) lmax[rt] += lmax[ro];
		if(rmax[ro] == sum[ro]) rmax[rt] += rmax[lo];
		mmax[rt] = max(mmax[rt],max(lmax[rt],rmax[rt]));
		mmax[rt] = max(mmax[rt],rmax[lo] + lmax[ro]);
	}
}

void build(int rt,int L,int R) {
	if(L == R) {
		sumv[rt] = val[L];
		lmax[rt] = rmax[rt] = mmax[rt] = 1;
	} else {
		build(lson); build(rson);
		pushup(rt,L,R);
	}
}

void update(int rt,int L,int R,int l,int r) {
	if(l <= L && r >= R) {
		if(setv[rt] != nul) pushdown(rt);
		setv[rt] = v; se
	}
}


int main() {
	
}
