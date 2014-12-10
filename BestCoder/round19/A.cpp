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
const int maxv = 4e4;
const int inf = 1e9 + 1;
vector<int> pnum;
bool vis[maxv + 1];
int val[100], pcnt;

void init() {
	for(int i = 2; i <= maxv; i++) if(vis[i] == false) {
		pnum.push_back(i);
		for(int j = i + i; j <= maxv; j += i) vis[j] = true;
	}
}

void gao(int num) {
	if(num <= 0) {
		puts("0"); return;
	}
	int tmp = num;
	pcnt = 0;
	int m = sqrt(num), ans = inf;
	int sz = pnum.size();
	for(int i = 0; i < sz && pnum[i] <= m; i++) {
		if(tmp % pnum[i] == 0) val[pcnt++] = pnum[i];
		while(tmp % pnum[i] == 0) {
			tmp /= pnum[i];
		}
		if(tmp == 1) break;
	}
	if(tmp != 1) val[pcnt++] = tmp;
	if(pcnt == 0) puts("0");
	else {
		printf("%d\n", num / val[pcnt - 1]);
	}
}

int main() {
	init();
	int n; 
	while(scanf("%d", &n) != EOF) {
		gao(n);
	}
	return 0;
}
