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
const int maxlen = 2e5 + 10;
char buf[maxlen];

std::map<std::string, int> mp;
typedef std::map<std::string, int>::iterator Iter;

LL gcd(LL n, LL m) {
	return m == 0 ? n : gcd(m, n % m);
}

LL C2(LL n) {
	return n * (n - 1) / 2;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		mp.clear();
		for(int i = 0; i < n; i++) {
			scanf("%s", buf);
			mp[buf]++;
		}
		LL ans = 0, odd = 0, even = 0, ap = C2(n);
		for(Iter i = mp.begin(); i != mp.end(); ++i) {
			int len = i->first.length();
			if(len % 2 == 0) even += i->second;
			else odd += i->second;
			if(i->second > 1) ans += C2(i->second);
		}
		ans += odd * even;
		if(ans == 0) puts("0/1");
		else {
			LL gg = gcd(ans, ap);
			std::cout << ans / gg << "/" << ap / gg << std::endl;
		}
	}
	return 0;
}
