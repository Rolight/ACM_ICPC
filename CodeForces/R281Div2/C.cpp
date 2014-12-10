#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;
const int maxn = 2e5 + 20;
int n, m, a[maxn], b[maxn];
int pp[maxn << 3], cnt;

inline int calc(int sz, int arr[], int d) {
	int pos = upper_bound(arr + 1, arr + 1 + sz, d) - arr;
	return (pos - 1) * 2 + (sz - pos + 1) * 3;
}

int main() {
	scanf("%d", &n);
	pp[cnt++] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pp[cnt++] = a[i];
		pp[cnt++] = a[i] - 1; 
		pp[cnt++] = a[i] + 1;
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		pp[cnt++] = b[i];
		pp[cnt++] = b[i] - 1; 
		pp[cnt++] = b[i] + 1;
	}
	sort(pp, pp + cnt);
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	cnt = unique(pp, pp + cnt) - pp;
	int ansa = -INT_MAX, ansb = 0;
	for(int i = 0; i < cnt; i++) {
		int tp1 = calc(n, a, pp[i]),
			tp2 = calc(m, b, pp[i]);
		if(tp1 - tp2 > ansa - ansb || 
				(tp1 - tp2 == ansa - ansb && tp1 > ansa)) {
			ansa = tp1; ansb = tp2;
		}
	}
	printf("%d:%d\n", ansa, ansb);
	return 0;
}
