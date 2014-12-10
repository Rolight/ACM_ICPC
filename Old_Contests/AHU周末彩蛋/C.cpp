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
const int maxn = 1e5 + 10;
int num[maxn];

int main() {
	int n; cin >> n;
	bool flag = false;
	for(int i = 1; i <= n; i++) {
		cin >> num[i];
		if(num[i] != 1) flag = true;
	}
	if(!flag) {
		for(int i = 1; i < n; i++) cout << "1 ";
		cout << 2 << endl;
		return 0;
	}
	num[0] = 1;
	sort(num, num + n + 1);
	for(int i = 0; i < n; i++) cout << num[i] << " ";
	cout << endl;
	return 0;
}
