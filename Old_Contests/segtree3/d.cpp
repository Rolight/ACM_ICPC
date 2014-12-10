#include <cstdio>

using namespace std;

#define M ((L+R)>>1)
#define lson rt<<1,L,M
#define rson rt<<1|1,M+1,R
#define len(a,b) ((b)-(a)+1)
#define undes 0
#define des 1

const int maxn = 50001,sizen = 50001 << 2;

int lmax[sizen],rmax[sizen],val[maxn],tar,v;

void setfile() {
	freopen("in.txt","r",stdin);
	freopen("out1.txt","w",stdout);
}

void build(int rt,int L,int R) {
	if(L == R) {
		lmax[rt] = rmax[rt] = 1;
		val[L] = undes;
	}
	else {
		int l = rt<<1,r = rt<<1|1;
		build(lson); build(rson);
		lmax[rt] = rmax[rt] = lmax[l] + lmax[r];
	}
}

void update(int rt,int L,int R) {
	if(L == R) val[tar] = v;
	else {
		if(tar <= M) update(lson);
		else update(rson);
		int l = rt<<1,r = rt<<1|1;
		lmax[rt] = lmax[l]; rmax[rt] = rmax[r];
		if(val[M] == val[M + 1] && val[M] == undes) {
			if(lmax[l] == len(L,M)) lmax[rt] += lmax[r];
			if(rmax[r] == len(M + 1,R)) rmax[rt] += rmax[l];
		}
	}
}

int queryr(int rt,int L,int R,int ql,int qr);

int queryl(int rt,int L,int R,int ql,int qr) {
	if(ql == L && qr == R) return rmax[rt];
	if(qr <= M) return queryl(lson,ql,qr);
	if(ql > M) return queryl(rson,ql,qr);
	int right = queryr(rson,M + 1,qr);
	if(right == len(M + 1,qr) && val[M] * val[M + 1]) return right + queryl(lson,ql,M);
	return right;
}

int queryr(int rt,int L,int R,int ql,int qr) {
	if(ql == L && qr == R) return lmax[rt];
	if(qr <= M) return queryr(lson,ql,qr);
	if(ql > M) return queryr(rson,ql,qr);
	int left = queryl(lson,ql,M);
	if(left == len(L,M) && val[M] * val[M + 1]) return left + queryr(rson,M + 1,qr);
	return left;
}

int query(int t,int n) {
	if(val[t] == des) return 0;
	int ans = 0;
	if(t - 1 > 0) ans += queryl(1,1,n,1,t - 1);
	if(t + 1 <= n) ans += queryr(1,1,n,t + 1,n);
	return ans + 1;
}


int main() {
//	setfile();
	int n,m,q[maxn],cq;
	char cmd;
	while(~scanf("%d%d",&n,&m)) {
		build(1,1,n);
		cq = 0;
		for(int i = 0;i < m;i++) {
			scanf(" %c",&cmd);
			if(cmd == 'R') {
				if(cq) {
					tar = q[--cq]; v = undes;
					update(1,1,n);
				}
			} else {
				scanf("%d",&tar);
				if(cmd == 'D') {
					if(val[tar] == undes){
						q[cq++] = tar; v = des; update(1,1,n);
					}
				} else printf("%d\n",query(tar,n));
			}
		}
	}
	return 0;
}
