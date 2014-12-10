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
const int inf = 2e9;

int main() {
	int l = inf, r = -inf, u = -inf, d = inf;
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		l = min(x, l);
		r = max(x, r);
		u = max(y, u);
		d = min(y, d);
	}
	LL pa = r - l, pb = u - d;
	cout << max(pa, pb) * max(pa, pb) << endl;
	return 0;
}
