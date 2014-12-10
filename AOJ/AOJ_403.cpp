#include <cstdio>
#include <cstring>

#define M ((L+R)>>1)
#define lson rt<<1,L,M
#define rson rt<<1|1,M+1,R
#define len(a,b) ((b)-(a)+1)

using namespace std;

const int maxn = 500001;

bool isdes[maxn],val;
int lmax[maxn<<2],rmax[maxn<<2],tar,desed[maxn],pd;

inline void pushup(int rt,int L,int R) {
	lmax[rt] = lmax[rt<<1];  rmax[rt] = rmax[rt<<1|1];
	if(!isdes[M] && !isdes[M + 1]) {
		if(lmax[rt<<1] == len(L,M)) lmax[rt] = lmax[rt<<1] + lmax[rt<<1|1];
		if(rmax[rt<<1|1] == len(M + 1,R)) rmax[rt] = rmax[rt<<1|1] + rmax[rt<<1];
	}
}

void build(int rt,int L,int R) {
	if(L == R) {
		lmax[rt] = rmax[rt] = 1;
		isdes[L] = false;
	} else {
		build(lson); build(rson);
		lmax[rt] = rmax[rt] = lmax[rt<<1] + lmax[rt<<1|1];
	}
}

void update(int rt,int L,int R) {
	if(L == R) {
		isdes[L] = val;
		lmax[rt] = rmax[rt] = (int)(!val);
	} else {
		if(tar <= M) update(lson);
		else update(rson);
		pushup(rt,L,R);
	}
}

int query(int t,int n) {
	int L = 1,R = n,rt = 1,left = 0,right = 0;
	if(isdes[t]) return 0;
	while(1) {
		if(L == R) return left + right + 1;
		if(t <= M) {
			if(lmax[rt<<1|1] == len(M + 1,R)) right += lmax[rt<<1|1];
			else right = lmax[rt<<1|1];
			rt = rt<<1; R = M;
		} else {
			if(rmax[rt<<1] == len(L,M)) left += rmax[rt<<1];
			else left = rmax[rt<<1];
			rt = rt<<1|1; L = M + 1;
		}
	}
}

int main() {
	int N,m;
	char cmd;
	while(scanf("%d%d",&N,&m) != EOF) {
		memset(desed,0,sizeof(desed));
		pd = 0;
		build(1,1,N);
		for(int c = 0;c < m;c++) {
			scanf(" %c",&cmd);
			if(cmd == 'R') {
				if(!pd) continue;
				while(pd && desed[pd - 1] == false) pd--;
				tar = desed[--pd];
				val = false;
				update(1,1,N);
			} else {
				scanf("%d",&tar);
				if(cmd == 'D') {
					desed[pd++] = tar;
					if(isdes[tar]) continue;
					val = true;
					update(1,1,N);
				} else printf("%d\n",query(tar,N));
			}
		}
	}
	return 0;
}
