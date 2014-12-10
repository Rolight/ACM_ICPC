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
LL a, b;

int main() {
	int n; cin >> n;
	while(n--) {
		cin >> a >> b;
		for(int i = 0; i < 63; i++) {
			LL val = a | (1LL << i);
			if(val <= b) a = val;
		}
		cout << a << endl;
	}
	return 0;
}
