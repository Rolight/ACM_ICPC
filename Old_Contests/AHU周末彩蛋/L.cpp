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

int main() {
	int T; cin >> T;
	while(T--) {
		int a, b; cin >> a >> b;
		a %= 100; b %= 100;
		cout << (a + b) % 100 << endl;
	}
	return 0;
}

