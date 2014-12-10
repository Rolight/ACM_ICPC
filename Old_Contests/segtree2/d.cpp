#include <stdio.h>
#include <string.h>

#define maxn 70000 * 2
#define l(o) ((o)<<1)
#define r(o) ((l(o))|1)
#define dv(l,r) ((l+r)>>1)
#define midl (dv(L,R))
#define midr (midl + 1)

char set[maxn << 2],val[maxn << 2];
int ql,qr,v,N;


void pushdown(int o) {
	if(~set[o]) {
		set[l(o)] = set[r(o)] = set[o];
		if(set[o] == -2) {
			val[l(o)] ^= 1; val[r(o)] ^= 1;
		} else 	val[l(o)] = val[r(o)] = set[o];
	}
}

void init() {
	memset(set,-1,sizeof(set));
	memset(val,0,sizeof(val));
}

void update(int o,int L,int R) {
	if(ql <= L && qr >= R) {
		set[o] = v;
		if(set[o] == -2) val[o] ^= 1;
		else val[o] = v;
	}
	else {
		pushdown(o);
		if(ql <= midl) update(l(o),L,midl);
		if(qr > midl) update(r(o),midr,R);
	}
}

int query(int p) {
	int o = 1,L = 2,R = N;
	printf("%d\n",p);
	while(L <= R) {
		pushdown(o);
		if(L == R || (ql <= L && qr >= R)) return val[o];
		if(p <= midl) R = midl,o = l(o);
		else L = midr,o = r(o);
	}
}

void setto(int l,int r,bool le,bool re,int val) {
	char left = le?'[':'(',right = re?']':')';
	if(l != 1)l <<= 1; r <<= 1;
	if(r > N) r = N;
	if(!le) l++; if(!re) r--;
	printf("set: %c%d,%d%c to %d\n",left,l,r,right,val);
	ql = l; qr = r; v = val;
	update(1,1,N);
}

void work(int n) {
	char res[maxn];
	for(int i = 1;i <= 2 * n;i++) res[i] = query(i);
	bool le,re,in = false; int l,r,now = 0;
	for(int i = 1;i <= 2 * n;i++) {
		now = res[i];
		if(now) {
			if(!in) {
				in = true;
				l = i;
			}
		} else {
			if(in) {
				in = false;
				r = i;
				if(l & 1) printf("(%d,",(l - 1) / 2 - 1);
				else printf("[%d,",l / 2 - 1);
				if(r & 1) printf("%d)",(r + 1) / 2 - 1);
				else printf("%d]",r / 2 - 1);
			}
		}
	}
}

int main() {
	N = maxn;
	char cmd,le,re;
	int l,r;
	init();
	while(~scanf(" %c %c%d,%d%c",&cmd,&le,&l,&r,&re)) {
		l++; r++;
		if(le == '[') le = 1; else le = 0;
		if(re == ']') re = 1; else re = 0;
		switch(cmd) {
			case 'U' : setto(l,r,le,re,1); break;
			case 'D' : setto(l,r,le,re,0); break;
			case 'S' : setto(l,r,le,re,-2); break;
			case 'I' : setto(1,l,1,!le,0); setto(r,N,!re,1,0); break;
			case 'C' : 
				setto(1,l,1,!le,0); setto(r,N,!re,1,0);
				setto(l,r,le,re,-2); break;
		}
	}
	printf("finished!\n");
	work(65536 * 2);
	return 0;
}
