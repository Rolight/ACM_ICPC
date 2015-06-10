#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <ctime>
#include <cstdlib>

typedef long long LL;
const int maxn = 100000 + 10;
std::multiset<LL> st;
typedef std::multiset<LL>::iterator Iter;
LL n, p, a[maxn], ans;

inline void gao(LL val) {
	Iter it = st.lower_bound(val);
	LL tmp = p - 1 - *it;
	st.erase(it);
	Iter it1 = st.lower_bound(tmp);
	if(it1 != st.begin() && *it1 > tmp)  it1--;
	ans = std::max(ans, (val + *it1) % p);
	it1 = st.lower_bound(tmp + p);
	if(it1 != st.begin() && *it1 > tmp)  it1--;
	ans = std::max(ans, (val + *it1) % p);
	st.insert(val);
}

inline bool scanf_(int &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0; //EOF
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}

int main() {
	while(std::cin >> n >> p) {
		st.clear();
		ans = 0;
		int tmp;
		for(int i = 1; i <= n; i++) {
			scanf_(tmp);
			a[i] = tmp;
			a[i] %= p;
			st.insert(a[i]);
		}
		for(int i = 1; i <= n; i++) gao(a[i]);
		std::cout << ans << std::endl;
	}
	return 0;
}
