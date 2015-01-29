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

//using namespace std;

typedef long long LL;
const int maxn = 1e5 + 10;
int a[maxn], n, cl, cr, count[maxn], odd;

bool check(int lpos, int rpos) {
	memset(count, 0, sizeof(count));
	for(int i = lpos; i <= rpos; i++) {
		count[a[i]]++;
	}
	for(int i = 1; i < n - i + 1; i++) {
		bool inL = (i >= lpos && i <= rpos);
		bool inR = (n - i + 1 >= lpos && n - i + 1 <= rpos);
		if(inL && inR) continue;
		else if(inL) {
			if(--count[a[n - i + 1]] < 0) return false;
		}
		else if(inR) {
			if(--count[a[i]] < 0) return false;
		}
		else {
			if(a[i] != a[n - i + 1]) return false;
		}
	}
	return true;
}

LL calc(int pos) {
	int l = pos, r = n, tar;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(pos, mid)) {
			tar = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return (LL)pos * (LL)(n - tar + 1);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		count[a[i]]++;
	}

	for(int i = 1; i <= n; i++) {
		if(count[i] & 1) {
			odd++;
		}
	}

	cl = 1;
	cr = n;

	while(cl <= cr && a[cl] == a[cr]) {
		cl++; cr--;
	}

	if(cl > cr) {
		LL ret = (LL)n * (LL)(n - 1) / 2 + n;
		printf("%I64d\n", ret);
	}
	else if(odd > 1) {
		puts("0");
	}
	else {
		LL ret = -(LL)cl * (LL)(n - cr + 1);
		ret += calc(cl);
		std::reverse(a + 1, a + 1 + n);
		ret += calc(cl);
		printf("%I64d\n", ret);
	}

	return 0;
}
