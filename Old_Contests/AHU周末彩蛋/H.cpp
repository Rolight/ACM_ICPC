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

typedef long long LL;

const int maxn = 1e5 + 10;

multiset<int> st1, st;
int n, len, k, a[maxn];
LL sum = 0;

void insert(int num) {
	if (k == 0) {
		sum -= num; return;
	}
	if (st.size() == k) {
		int pnum = *st.begin();
		if (pnum < num) {
			st.erase(st.begin());
			sum = sum - 2 * pnum + num;
			st.insert(num);
			st1.insert(pnum);
		}
		else {
			st1.insert(num);
			sum -= num;
		}
	}
	else {
		sum += num; st.insert(num);
	}
}

void erase(int num) {
	if (k == 0) {
		sum += num; return;
	}
	multiset<int>::iterator it = st.find(num);
	if (it != st.end()) {
		st.erase(it); sum -= num;
		if (st1.size() != 0) {
			it = st1.end(); it--;
			insert((*it));
			sum += *it;
			st1.erase(it);
		}
	}
	else {
		it = st1.find(num);
		if(it != st1.end()) st1.erase(it);
		sum += num;
	}
}

LL gao() {
	LL ans = 0;
	st.clear(); st1.clear(); sum = 0;
	for (int i = 1; i <= len; i++) {
		if (a[i] >= 0) sum += a[i];
		else insert(-a[i]);
	}
	ans = sum;
	for (int i = len + 1, j = 1; i <= n; i++, j++) {
		if (a[j] < 0) erase(-a[j]);
		else sum -= a[j];
		if (a[i] < 0) insert(-a[i]);
		else sum += a[i];
		ans = max(ans, sum);
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &len);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &k);
	LL ans = gao();
	for (int i = 1; i <= n; i++) a[i] = -a[i];
	ans = max(ans, gao());
	cout << ans << endl;
	return 0;
}
