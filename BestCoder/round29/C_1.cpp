#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <ctime>


typedef unsigned long long LL;
const int maxn = 1e6 + 10;
int n, q, arr[maxn];
LL sum[maxn], hash[maxn], nmap[maxn], thash[maxn], thash1[maxn], nmap1[maxn], hash1[maxn];

LL longRand() {
	return 
		((LL)rand() << 49) |
		((LL)rand() << 34) |
		((LL)rand() << 19) |
		((LL)rand() << 4)  |
		(rand() & 15);
}

void init() {
	for(int i = 1; i <= 1000000; i++) {
		nmap[i] = longRand();
		nmap1[i] = longRand();
		thash[i] = thash[i - 1] ^ nmap[i];
		thash1[i] = thash1[i - 1] ^ nmap1[i];
	}
}

int main() {
	srand(time(NULL));
	init();
	while(scanf("%d%d", &n, &q) != EOF)  {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			sum[i] = sum[i - 1] + arr[i];
			hash[i] = hash[i - 1] ^ nmap[arr[i]];
			hash1[i] = hash1[i - 1] ^ nmap1[arr[i]];
		}
		int l, r;
		for(int i = 1; i <= q; i++) {
			scanf("%d%d", &l, &r);
			LL len = r - l + 1;
			if(sum[r] - sum[l - 1] == len * (len + 1) / 2 
					&& hash[r] ^ hash[l - 1] == thash[len] 
					&& hash1[r] ^ hash1[l - 1] == thash1[len]
					) {
				puts("YES");
			}
			else puts("NO");
		}
	}
	return 0;
}
