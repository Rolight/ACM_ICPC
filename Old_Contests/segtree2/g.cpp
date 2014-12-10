#include <cstdio>
#include <cstring>

#define l(o) ((o)<<1)
#define r(o) (((o)<<1)|1)
#define dv(o) ((o)>>1)
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define len(a,b) ((b)-(a)+1)

using namespace std;

const int maxn = 100001;

int a[maxn],lmax[maxn << 2],rmax[maxn << 2],mmax[maxn << 2],lval[maxn << 2],rval[maxn << 2];
int ql,qr,addv[maxn << 2],v;

void pushdown(int o) {
	if(addv[o]) {
		int lc = l(o),rc = r(o);
		lval[lc] += addv[o]; rval[lc] += addv[o];
		lval[rc] += addv[o]; rval[rc] += addv[o];
		addv[lc] += addv[o]; addv[rc] += addv[o];
		addv[o] = 0;
	}
}

void pushup(int o,int L,int R) {
	int lc = l(o),rc = r(o),M = dv(L + R);
	lmax[o] = lmax[lc]; rmax[o] = rmax[rc];
	lval[o] = lval[lc]; rval[o] = rval[rc];
	mmax[o] = 0;
	if(rval[lc] < lval[rc])	{
		if(lmax[lc] == len(L,M)) lmax[o] += lmax[rc];
		if(rmax[rc] == len(M + 1,R)) rmax[o] += rmax[lc];
		mmax[o] = rmax[lc] + lmax[rc];
	}
	mmax[o] = max(mmax[o],max(lmax[o],rmax[o]));
	mmax[o] = max(mmax[o],max(mmax[lc],mmax[rc]));
}

void build(int o,int L,int R) {
	if(L == R) {
		lmax[o] = rmax[o] = mmax[o] = 1;
		lval[o] = rval[o] = a[L];
		addv[o] = 0;
	} else {
		int lc = l(o),rc = r(o),M = dv(L + R);
		build(lc,L,M); build(rc,M + 1,R);
		pushup(o,L,R);
	}
	//printf("%d %d %d:\nlr=%d,rl=%d,lll=%d,rll=%d\n",L,R,mmax[o],rval[l(o)],lval[r(o)],lmax[r(o)],rmax[l(o)]);
}

void update(int o,int L,int R) {
	if(ql <= L && qr >= R) {
	   	addv[o] += v;
		lval[o] += v; rval[o] += v;
	}
	else {
		pushdown(o);
		int lc = l(o),rc = r(o),M = dv(L + R);
		if(ql <= M) update(lc,L,M);
		if(qr > M) update(rc,M + 1,R);
		pushup(o,L,R);
	}
}

int query(int o,int L,int R) {
	if(ql <= L && qr >= R) return mmax[o];
	else {
		if(addv[o]) pushdown(o);
		int lc = l(o),rc = r(o),M = dv(L + R);
		if(ql > M) return query(rc,M + 1,R);
		else if(qr <= M) return query(lc,L,M);
		else {
			int ans = max(query(lc,L,M),query(rc,M + 1,R));  
			if(rval[lc] < lval[rc])
				ans = max(ans,min(len(ql,M),rmax[lc] ) + min( len(M + 1,qr),lmax[rc]));  
			return ans;  
		}
	}
}

int main() {
	freopen("in.txt","r",stdin);
	int T,N,Q;
	char cmd;
	scanf("%d",&T);
	for(int c = 1;c <= T;c++) {
		memset(addv,0,sizeof(addv));
		printf("Case #%d:\n",c);
		scanf("%d%d",&N,&Q);
		for(int i = 1;i <= N;i++) scanf("%d",a + i);
		build(1,1,N);
		for(int i = 1;i <= Q;i++) {
			scanf(" %c%d%d",&cmd,&ql,&qr);
			if(cmd == 'a') {
				scanf("%d",&v);
				update(1,1,N);
			} else printf("%d\n",query(1,1,N));
		}
	}
	return 0;
}
