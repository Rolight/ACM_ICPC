/*
ID: flsnnx1
LANG: C++
TASK: fact4
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

typedef long long LL;

int main() {
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);
	int n;
	while(scanf("%d", &n) != EOF) {
		LL nowlast = 1;
		for(int i = 2; i <= n; i++) {
			nowlast = nowlast * i;
			while(nowlast % 10 == 0) nowlast /= 10;
			nowlast %= 1000000000LL;
		}
		printf("%d\n", nowlast % 10);
	}
	return 0;
}

