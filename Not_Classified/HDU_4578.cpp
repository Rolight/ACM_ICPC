#include <cstdio>
#include <cstring>
#include <algorithm>

#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r

using namespace std;

const int MOD = 10007;
const int maxn = 100000 + 5;
const int COV = 3;
const int ADD = 1;
const int MUL = 2;

int sq(int x) {
    return (x) * (x) % MOD;
}

int tq(int x) {
    return sq(x) * (x) % MOD;
}

int sum1[maxn<<3],sum2[maxn<<3],sum3[maxn<<3];
int cov[maxn<<3],addc[maxn<<3],mul[maxn<<3];

void updateseg(int rt,int l,int r,int type,int c) {
    int n = (r - l + 1);
    if(type == ADD) {
        sum3[rt] = (sum3[rt] + tq(c) * n) % MOD + 3 *(
 sum2[rt] * c )%MOD+ 3 * (sq(c)* sum1[rt])%MOD;
        sum2[rt] = (sum2[rt] + sq(c) * n) % MOD + 2 * sum1[rt] * c;
        sum1[rt] += c * n;
    }
    if(type == MUL) {
        sum3[rt] *= tq(c);
        sum2[rt] *= sq(c);
        sum1[rt] *= c;
    }
    if(type == COV) {
        sum1[rt] = c * n;
        sum2[rt] = sq(c) * n;
        sum3[rt] = tq(c) * n;
    }
    sum3[rt] %= MOD; sum2[rt] %= MOD; sum1[rt] %= MOD;
}

/*
void pushdown(int rt,int l,int r) {
    int ll = rt<<1,rr = rt<<1|1,m = (l + r) >> 1,n =(r - l) + 1;
    if(l>=r) return;
    pushdown(lson);
    pushdown(rson);
    if(cov[rt]) {
        cov[ll] = cov[rr] = cov[rt];
        addc[ll] = addc[rr] = 0;
        mul[ll] = mul[rr] = 0;
        updateseg(lson,COV,cov[rt]);
        updateseg(rson,COV,cov[rt]);
        cov[rt] = 0;    
        addc[rt] = mul[rt] = 0;
    }
    if(addc[rt]) {
        addc[ll] += addc[rt];
        addc[rr] += addc[rt];
        addc[ll] %= MOD;
        addc[rr] %= MOD;
        updateseg(lson,ADD,addc[rt]);
        updateseg(rson,ADD,addc[rt]);
        addc[rt]  = 0;
    }
    if(mul[rt]) {
        if(mul[ll] == 0) mul[ll] = 1;
        if(mul[rr] == 0) mul[rr] = 1;
        mul[ll] *= mul[rt];
        mul[rr] *= mul[rt];
        mul[ll] %= MOD;
        mul[rr] %= MOD;
        updateseg(lson,MUL,mul[rt]);
        updateseg(rson,MUL,mul[rt]);
        mul[rt] = 0;
    }
}
*/

void pushdown(int rt,int l,int r) {
	int ll = rt<<1,rr = rt<<1|1;
	int m = (l + r) >> 1;
	if(cov[rt] != -1) {
		addc[rt] = addc[ll] = addc[rr] = -1;
		mul[rt] = mul[ll] = mul[rr] = -1;

		cov[ll] = cov[rr] = cov[rt];

		updateseg(lson,COV,cov[rt]);
		updateseg(rson,COV,cov[rt]);

		cov[rt] = -1;
	} else {
		if(mul[rt] != -1) {
			updateseg(lson,MUL,mul[rt]);
			updateseg(rson,MUL,mul[rt]);

			if(cov[ll] != -1) cov[ll] *= mul[rt];
			else if(mul[ll] == -1) mul[ll] = mul[rt];
			else mul[ll] *= mul[rt];
			if(cov[rr] != -1) cov[rr] *= mul[rt];
			else if(mul[rr] == -1) mul[rr] = mul[rt];
			else mul[rr] *= mul[rt];

			if(addc[ll] != -1) addc[ll] *= mul[rt];
			if(addc[rr] != -1) addc[rr] *= mul[rt];

			mul[rt] = -1;
			cov[ll] %= MOD; cov[rr] %= MOD;
			mul[ll] %= MOD; mul[rr] %= MOD;
			addc[ll] %= MOD; addc[rr] %= MOD;
		}
		if(addc[rt] != -1) {
			updateseg(lson,ADD,addc[rt]);
			updateseg(rson,ADD,addc[rt]);

			if(cov[ll] != -1) cov[ll] += addc[rt];
			else if(addc[ll] == -1) addc[ll] = addc[rt];
			else addc[ll] += addc[rt];
			if(cov[rr] != -1) cov[rr] += addc[rt];
			else if(addc[rr] == -1) addc[rr] = addc[rt];
			else addc[rr] += addc[rt];

			cov[ll] %= MOD; cov[rr] %= MOD;
			addc[ll] %= MOD; addc[rr] %= MOD;
			addc[rt] = -1;
		}
	}
}

void pushup(int rt) {
    int ll = rt<<1,rr = rt<<1|1;
    sum1[rt] = sum1[ll] + sum1[rr];
    sum2[rt] = sum2[ll] + sum2[rr];
    sum3[rt] = sum3[ll] + sum3[rr];
	sum3[rt] %= MOD; sum2[rt] %= MOD; sum1[rt] %= MOD;
}

void build() {
    memset(sum1,0,sizeof(sum1));
    memset(sum2,0,sizeof(sum2));
    memset(sum3,0,sizeof(sum3));
    memset(addc,-1,sizeof(addc));
    memset(mul,-1,sizeof(mul));
    memset(cov,-1,sizeof(cov));
}

void update(int rt,int l,int r,int ql,int qr,int type,int c) {
    if(ql <= l && qr >= r) {
		/*
        if(type == COV) {
            int n = r - l + 1;
            updateseg(rt,l,r,COV,c);
            cov[rt] = c;
            mul[rt] = addc[rt] = 0;
        } else {
            pushdown(rt,l,r);
            if(type == ADD) {
                addc[rt] = c;
                updateseg(rt,l,r,ADD,c);
                addc[rt] %= MOD;
            } else  {
                updateseg(rt,l,r,MUL,c);
                mul[rt] = c;
                mul[rt] %= MOD;
            }
        }
		*/
		updateseg(rt,l,r,type,c);
		if(type == COV) {
			cov[rt] = c;
			mul[rt] = addc[rt] = -1;
		} else {
			if(type == ADD) {
				if(cov[rt] != -1) cov[rt] += c;
				else {
					if(addc[rt] == -1) addc[rt] = c;
					else addc[rt] += c;
				}
			} else {
				if(cov[rt] != -1) cov[rt] *= c;
				else {
					if(mul[rt] == -1) mul[rt] = c;
					else mul[rt] *= c;
					if(addc[rt] != -1) addc[rt] *= c;
				}
			}
		}
		addc[rt] %= MOD; mul[rt] %= MOD; cov[rt] %= MOD;
    } else {
        pushdown(rt,l,r);
        int m = (l + r) >> 1;
        if(ql <= m) update(lson,ql,qr,type,c);
        if(qr > m) update(rson,ql,qr,type,c);
        pushup(rt);
    }
}

int query(int rt,int l,int r,int ql,int qr,int p) {
    if(ql <= l && qr >= r) {
        if(p == 1) return sum1[rt];
        if(p == 2) return sum2[rt];
        if(p == 3) return sum3[rt];
    } else {
		pushdown(rt,l,r);
        int m = (l + r) >> 1,ret = 0;
        if(ql <= m) ret = (ret + query(lson,ql,qr,p)) % MOD;
        if(qr > m) ret = (ret + query(rson,ql,qr,p)) % MOD;
        return ret;
    }
}

int main() {
	freopen("in.txt","r",stdin);
	freopen("ff.txt","w",stdout);
    int n,m,cmd,x,y,c;
    while(scanf("%d%d",&n,&m),m || n) {
        build();
        for(int i = 0;i < m;i++) {
            scanf("%d%d%d%d",&cmd,&x,&y,&c);
            if(cmd == 4) {
                int ret = query(1,1,n,x,y,c);
                printf("%d\n",ret);
            } else {
                update(1,1,n,x,y,cmd,c);
            }
        }
    }
	return 0;
}

