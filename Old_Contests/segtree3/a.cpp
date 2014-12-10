#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define M ((L+R)>>1)
#define lson rt<<1,L,M
#define rson rt<<1|1,M+1,R
#define root 1,1,N

const int maxn = 100001;

struct q {
	int l,r,h,res;
};

struct brick {
	int val,pos;
};

int sum[maxn << 2],ql,qr,tar;
q querys[maxn],*pquerys[maxn];
brick b[maxn];
char tmp[15];

bool cmp(q *a,q *b) {
	return (a->h) < (b->h);
}

bool cmp1(brick a,brick b) {
	return a.val < b.val;
}

inline void pushup(int rt) {
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void update(int rt,int L,int R) {
	if(L == R) sum[rt] = 1;
	else {
		if(tar <= M) update(lson);
		else update(rson);
		pushup(rt);
	}
}

int query(int rt,int L,int R) {
	if(ql <= L && qr >= R) return sum[rt];
	else {
		int ans = 0;
		if(ql <= M) ans += query(lson);
		if(qr > M) ans += query(rson);
		return ans;
	}
}

int getnum() {
	int ans = 0,i = 1;
	while((tmp[0] = getchar()) == ' ' || tmp[0] == '\n');
	while((tmp[i] = getchar()) != ' ' && tmp[i] != '\n') i++;
	for(int k = 0;k < i;k++) ans = ans * 10 + tmp[k] - '0';
	return ans;
}

void putnum(int num) {
	int i = 0;
	tmp[0] = '0';
	while(num) {
		tmp[i++] = num % 10 + '0';
		num /= 10;
	}
	i--;
	if(i < 0) puts("0");
	else {
		while(i >= 0) putchar(tmp[i--]);
		putchar('\n');
	}
}

int main() {
	int T,N,m,now;
	T = getnum();
	for(int k = 1;k <= T;k++) {
		memset(sum,0,sizeof(sum));
		int bpos = 0,hh = -1;
		N = getnum(); m = getnum();
		for(int i = 0;i < N;i++) {
			b[i].val = getnum();
			b[i].pos = i + 1;
		}
		for(int i = 0;i < m;i++) {
			querys[i].l = getnum();
			querys[i].r = getnum();
			querys[i].h = getnum();
			pquerys[i] = querys + i;
		}
		sort(pquerys,pquerys + m,cmp);
		sort(b,b + N,cmp1);
		for(int i = 0;i < m;i++) {
			ql = pquerys[i]->l + 1; qr = pquerys[i]->r + 1;
			if(hh < pquerys[i]->h) {
				hh = pquerys[i]->h;
				while(b[bpos].val <= hh && bpos < N) {
					tar = b[bpos++].pos;
					update(root);
				}
			}
			pquerys[i]->res = query(root);
		}
		printf("Case %d:\n",k);
		for(int i = 0;i < m;i++) putnum(querys[i].res);
	}
	return 0;
}
