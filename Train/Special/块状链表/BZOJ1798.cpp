#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxm = 320;
const int maxn = 1e5 + 10;

typedef long long LL;

struct Chunk {
	LL num[maxm + 1];
	LL sum, tagMul, tagAdd;
	int next, len;
};

Chunk ck[320];
int arr[maxn], n, modP, ckCnt;

void loadArr() {
	int rest = n, cpos = 0;
	ckCnt = 0;
	while(rest > 0) {
		ck[cpos].len = ck[cpos].sum = ck[cpos].tagAdd = 0;
		ck[cpos].tagMul = 1;
		for(int i = 1; i <= maxm && rest > 0; i++) {
			ck[cpos].num[i] = arr[cpos * maxm + i];
			ck[cpos].sum += ck[cpos].num[i];
			ck[cpos].len++;
			rest--;
		}
		ckCnt++; cpos++;
	}
}

int search(int pos) {
	int l = 0, r = ckCnt - 1, ans = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		if((mid + 1) * maxm >= pos) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	//printf("ckCnt is %d, search %d get %d\n", ckCnt, pos, ans);
	//system("pause");
	return ans;
}

void down(int cpos) {
	if(ck[cpos].tagAdd == 0 && ck[cpos].tagMul == 1) return;
	ck[cpos].sum = 0;
	for(int i = 1; i <= ck[cpos].len; i++) {
		ck[cpos].num[i] = 
			(ck[cpos].num[i] * ck[cpos].tagMul % modP + ck[cpos].tagAdd) % modP;
		ck[cpos].sum = (ck[cpos].num[i] + ck[cpos].sum) % modP;
	}
	ck[cpos].tagAdd = 0;
	ck[cpos].tagMul = 1;
}

void mul(int l, int r , int num) {
	int cl, pl, cr, pr;
	cl = search(l); pl = l - cl * maxm;
	cr = search(r); pr = r - cr * maxm;
	for(int i = cl; i <= cr; i++) {
		if(i != cl && i != cr) {
			ck[i].tagMul = (ck[i].tagMul * num) % modP;
			ck[i].tagAdd = (ck[i].tagAdd * num) % modP;
			ck[i].sum = (ck[i].sum * num) % modP;
		}
		else if(cl == cr) {
			down(i);
			for(int j = pl; j <= pr; j++) {
				ck[i].sum -= ck[i].num[j];
				ck[i].num[j] *= num; ck[i].num[j] %= modP;
				ck[i].sum = (ck[i].num[j] + ck[i].sum + modP) % modP;
			}
		}
		else if(i == cl) {
			down(i);
			for(int j = pl; j <= ck[i].len; j++) {
				ck[i].sum -= ck[i].num[j];
				ck[i].num[j] *= num; ck[i].num[j] %= modP;
				ck[i].sum = (ck[i].num[j] + ck[i].sum + modP) % modP;
			}
		}
		else if(i == cr) {
			down(i);
			for(int j = 1; j <= pr; j++) {
				ck[i].sum -= ck[i].num[j];
				ck[i].num[j] *= num; ck[i].num[j] %= modP;
				ck[i].sum = (ck[i].num[j] + ck[i].sum + modP) % modP;
			}
		}
	}
}

void add(int l, int r, int num) {
	int cl, pl, cr, pr;
	cl = search(l); pl = l - cl * maxm;
	cr = search(r); pr = r - cr * maxm;
	for(int i = cl; i <= cr; i++) {
		if(i != cl && i != cr) {
			ck[i].tagAdd = (ck[i].tagAdd + num) % modP;
			ck[i].sum = (ck[i].sum + num * ck[i].len) % modP;
		}
		else if(cl == cr) {
			down(i);
			for(int j = pl; j <= pr; j++) {
				ck[i].num[j] = (ck[i].num[j] + num) % modP;
				ck[i].sum = (ck[i].sum + num) % modP;
			}
		}
		else if(i == cl) {
			down(i);
			for(int j = pl; j <= ck[i].len; j++) {
				ck[i].num[j] = (ck[i].num[j] + num) % modP;
				ck[i].sum = (ck[i].sum + num) % modP;
			}
		}
		else if(i == cr) {
			down(i);
			for(int j = 1; j <= pr; j++) {
				ck[i].num[j] = (ck[i].num[j] + num) % modP;
				ck[i].sum = (ck[i].sum + num) % modP;
			}
		}
	}
}

LL query(int l, int r) {
	int cl, pl, cr, pr;
	cl = search(l); pl = l - cl * maxm;
	cr = search(r); pr = r - cr * maxm;
	LL ret = 0;
	for(int i = cl; i <= cr; i++) {
		if(i != cl && i != cr) ret = (ret + ck[i].sum) % modP;
		else if(cl == cr) {
			down(i);
			for(int j = pl; j <= pr; j++) {
				ret = (ret + ck[i].num[j]) % modP;
			}
		}
		else if(i == cl) {
			down(i);
			for(int j = pl; j <= ck[i].len; j++) {
				ret = (ret + ck[i].num[j]) % modP;
			}
		}
		else if(i == cr) {
			down(i);
			for(int j = 1; j <= pr; j++) {
				ret = (ret + ck[i].num[j]) % modP;
			}
		}
	}
	return ret;
}

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &modP);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	loadArr();
	int q; scanf("%d", &q);
	int cmd, l, r, num;
	while(q--) {
		scanf("%d", &cmd);
		if(cmd == 1) {
			scanf("%d%d%d", &l, &r, &num);
			mul(l, r, num);
		}
		else if(cmd == 2) {
			scanf("%d%d%d", &l, &r, &num);
			add(l, r, num);
		}
		else {
			scanf("%d%d", &l, &r);
			printf("%d\n", (int)query(l, r));
		}
	}
	return 0;
}
