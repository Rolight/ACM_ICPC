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
const int maxn = 105;
int pos[maxn];

int main() {
	int n; cin >> n;
	for(int i = 1; i <= n; i++) {
		int tmp; cin >> tmp;
		pos[tmp] = i;
	}
	for(int i = 1; i <= n; i++) {
		cout << pos[i] << " ";
	}
	cout << endl;
	return 0;
}
