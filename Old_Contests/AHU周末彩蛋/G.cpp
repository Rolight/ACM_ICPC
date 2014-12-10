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
const int maxn = 2005;
int dcnt[maxn];

int main() {
	int d, mcnt;
	cin >> d >> mcnt;
	int ans = 0;
	for(int i = 1; i <= mcnt; i++) {
		cin >> dcnt[i];
		ans += (d - dcnt[i]);
	}
	ans -= (d - dcnt[mcnt]);
	cout << ans << endl;
	return 0;
}
