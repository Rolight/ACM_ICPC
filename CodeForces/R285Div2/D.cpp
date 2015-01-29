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

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 10;
int p1[maxn], p1t[maxn], p2[maxn], p2t[maxn], n;
int apt[maxn], ans[maxn];

int C[maxn];

int lowbit(int x) {
	return x & (-x);
}

int init_bit() {
	memset(C, 0, sizeof(C));
}

void addv(int pos, int x, int mx) {
	while(pos <= mx) {
		C[pos] += x;
		pos += lowbit(pos);
	}
}

int ask(int pos) {
	int ret = 0;
	while(pos > 0) {
		ret += C[pos];
		pos -= lowbit(pos);
	}
	return ret;
}

void calc(int arr[], int tar[], int len) {
	init_bit();
	for(int i = 0; i < len; i++) {
		addv(i + 1, 1, len);
	}
	for(int i = len - 1; i >= 0; i--) {
		tar[i] = ask(arr[i]);
		addv(arr[i] + 1, -1, len);
	}
}

int findk(int val, int mx) {
	int l = 1, r = mx, ret = 1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(ask(mid) >= val) {
			ret = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return ret;
}

void recalc(int arr[], int tar[], int len) {
	init_bit();
	for(int i = 0; i < len; i++) {
		addv(i + 1, 1, len);
	}
	for(int i = len - 1; i >= 0; i--) {
		tar[i] = findk(arr[i] + 1, len) - 1;
		addv(tar[i] + 1, -1, len);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &p1[i]);
	}
	reverse(p1, p1 + n);
	calc(p1, p1t, n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &p2[i]);
	}
	reverse(p2, p2 + n);
	calc(p2, p2t, n);
	for(int i = 0; i < n; i++) {
		apt[i] += p1t[i] + p2t[i];
		apt[i + 1] += apt[i] / (i + 1);
		apt[i] %= (i + 1);
	}
	recalc(apt, ans, n);
	for(int i = n - 1; i >= 0; i--) {
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}
