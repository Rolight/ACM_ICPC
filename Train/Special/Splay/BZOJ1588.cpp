#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <climits>
#include <iostream>

using namespace std;

typedef long long LL;

const int maxn = 1e6 + 10;
int fa[maxn], key[maxn], ch[maxn][2], root, sz;

void debug() {
	puts("----------debug start----------------");
	for(int i = 0; i <= sz; i++) {
		printf("Node %d, key = %d, lch = %d, rch = %d, fa = %d\n",
				i, key[i], ch[i][0], ch[i][1], fa[i]);
	}
	puts("************debug end**************");
}

void newNode(int &r, int father, int k) {
	r = ++sz;
	fa[r] = father;
	key[r] = k;
	ch[r][0] = ch[r][1] = 0;
}

void rotate(int o, int d) {
	int y = fa[o];
	ch[y][d ^ 1] = ch[o][d]; 
	fa[ch[o][d]] = y;
	if(fa[y] != 0) {
		ch[fa[y]][y == ch[fa[y]][1]] = o;
	}
	ch[o][d] = y; 
	fa[o] = fa[y];
	fa[y] = o;
}

void splay(int r, int goal) {
	while(fa[r] != goal) {
		int d = (r == ch[fa[r]][1]), y = fa[r];
		if(fa[fa[r]] == goal) rotate(r, d ^ 1);
		else {
			int d1 = ch[fa[y]][1] == y;
			if(d == d1) {
				rotate(y, d ^ 1);
				rotate(r, d ^ 1);
			}
			else {
				rotate(r, d1);
				rotate(r, d);
			}
		}
	}
	if(goal == 0) root = r;
}

int insert(int val) {
	int r = root;
	while(ch[r][val > key[r]]) {
		if(key[r] == val) {
			splay(r, 0); return 0;
		}
		r = ch[r][val > key[r]];
	}
	newNode(ch[r][val > key[r]], r, val);
	splay(ch[r][val > key[r]], 0);
	return 1;
}

int ask(int x, int d) {
	x = ch[x][d ^ 1];
	while(ch[x][d]) x = ch[x][d];
	return x;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		root = sz = 0;
		int ans = 0;
		newNode(root, 0, INT_MAX);
		insert(-INT_MAX);
		for(int i = 1; i <= n; i++) {
			int num; scanf("%d", &num);
			if(i == 1) {
				insert(num); ans += num;
			}
			else {
				int ret = insert(num);
				if(ret == 0) continue;
				int t1 = ask(root, 0), t2 = ask(root, 1);
				ans += min((LL)abs((LL)key[t1] - num),
						(LL)abs((LL)key[t2] - num));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
