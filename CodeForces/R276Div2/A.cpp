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
const int maxn = 1e5 + 5;
bool vis[maxn];

int main() {
	int a, m; cin >> a >> m;
	bool canstop = false;
	vis[a] = true;
	while(1) {
		int nowx = a % m;
		if(nowx == 0) {
			canstop = true;
			break;
		}
		a = (a + nowx) % m;
		if(vis[a] == true) break;
		vis[a] = true;
	}
	if(canstop) puts("Yes");
	else puts("No");
	return 0;
}
