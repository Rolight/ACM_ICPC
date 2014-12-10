#include <cstdio>
#include <cstring>

using namespace std;

#define M ((L+R)>>1)
#define lson rt<<1,L,M
#define rson rt<<1|1,M+1,R
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define len(a,b) ((b)-(a)+1)

const int maxn = 50001;
const int sizen = maxn << 2;

int lmax[sizen],rmax[sizen],val[maxn],mmax[sizen],tar,v,des[maxn],cd;

inline void pushup(int rt,int L,int R) {
	int l = rt<<1,r = rt<<1|1;
	lmax[rt] = lmax[l]; rmax[rt] = rmax[r];
	mmax[rt] = 0;
	if(val[M] == val[M + 1]) {
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
	if(L == R) val[L] = 1;
	else {
		if(tar <= M) update(lson);
		else update(rson);
		pushup(rt,L,R);
	}
}

int query(int t,int N) {
	if(val[t]) return 0;
	int L = 1,R = N,rt = 1,left = 0,right = 0;
	while(L < R) {
		if(t <= M) {
			if(val[M] == val[M + 1]) right += lmax[rt<<1|1];
			else right = 0;
			R = M;
		} else {
			if(val[M] == val[M + 1]) left += rmax[rt<<1];
			else left = 0;
			L = M + 1;
		}
	}
	return left + right + 1;
}

int main() {
	int N,Q;
	while(~scanf("%d%d",&N,&Q)) {
		memset(val,0,sizeof(int) * (N + 2));
		cd = 0;
		build(1,1,N);
		char cmd;
		while(Q--) {
			scanf(" %c",&cmd);
			if(cmd == 'D') {
				scanf("%d",&tar);
				v = 1; update(1,1,N);
				des[cd++] = tar;
			} else if(cmd == 'R') {
				if(cd) {
					tar = des[--cd];
					v = 0; update(1,1,N);
				}
			} else {
				scanf("%d",&tar);
				printf("%d ",query(tar,N));
			}
			printf("%c %d\n",cmd,tar);
		}
	}
	return 0;
}
