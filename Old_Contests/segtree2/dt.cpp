#include <stdio.h>
#include <string.h>

#define lson L,m,rt << 1
#define rson m + 1,R,rt << 1 | 1
#define lc (rt << 1)
#define rc (rt << 1 | 1)

const int maxn = (1 << 17);

int val[maxn << 2],XOR[maxn << 2];
bool note[maxn + 1];

void setval(int str,int end) {
	for(int i = str;i <= end;i++) note[i] = true;
}

void setxor(int rt) {
	if(~val[rt]) val[rt] ^= 1; else XOR[rt] ^= 1;
}

void pushdown(int rt) {
	if(~val[rt]) {
		val[lc] = val[rc] = val[rt];
		XOR[lc] = XOR[rc] = 0;
		val[rt] = -1;
	}
	if(XOR[rt]) { setxor(lc); setxor(rc); XOR[rt] = 0; }
}

void update(int ql,int qr,int L,int R,int rt,char cmd) {
	if(ql <= L && qr >= R) {
		switch(cmd) {
			case 'U' : val[rt] = 1; XOR[rt] = 0; break;
			case 'D' : val[rt] = 0; XOR[rt] = 0; break;
			case 'C' : case 'S' : setxor(rt); break;
		}
	} else {
		pushdown(rt);
		int m = (L + R) >> 1;
		if(ql <= m) update(ql,qr,lson,cmd);
		else if(cmd == 'I' || cmd == 'C') XOR[lc] = val[lc] = 0;
		if(m < qr) update(ql,qr,rson,cmd);
		else if(cmd == 'I' || cmd == 'C') XOR[rc] = val[rc] = 0;
	}
}

void query(int L,int R,int rt) {
	if(val[rt] == 1) {
		setval(L,R);
		return;
	}
	else if(val[rt] == 0) return;
	pushdown(rt);
	int m = (L + R) >> 1;
	query(lson); query(rson);
}

int main() {
	char cmd,le,re; int l,r;
	while(~scanf(" %c %c%d,%d%c",&cmd,&le,&l,&r,&re)) {
		l <<= 1; r <<= 1;
		if(le == '(') l++; if(re == ')') r--;
		if(l > r && (cmd == 'C' || cmd == 'I')) val[1] = XOR[1] = 0;
		else if(l <= r) update(l,r,0,maxn,1,cmd);
	}
	query(0,maxn,1);
	int lk = -1,rk; bool be = false;
	for(int i = 0;i <= maxn;i++) {
		if(note[i])	{
			if(lk == -1) lk = i; 
			rk = i;
		}
		else {
			if(~lk) {
				if(be) printf(" "); be = true;
				printf("%c%d,%d%c",(lk & 1)?'(':'[',lk / 2,(rk + 1) / 2,(rk & 1)?')':']');
				lk = -1;
			}
		}
	}
	if(!be) printf("empty set");
	putchar('\n');
	return 0;
}
