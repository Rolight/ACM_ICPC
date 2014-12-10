#include <cstdio>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
#include <ctime>
#include <set>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <string>
#include <list>

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

const int manx = 1000;
const int maxm = 13;

int hire, fire, salary;
int need[maxm], n;
int note[maxm][manx];

int dfs(int now,int amount) {
	if(now > n) {
		return 0;
	}
	if(~note[now][amount]) return note[now][amount];
	int cost = INF;
	if(amount <= need[now]) {
		cost = dfs(now + 1, need[now]) + (need[now] - amount) * hire + salary * need[now];
	} else {
		for(int i = need[now]; i <= amount; i++) {
			cost = min(dfs(now + 1, i) + (amount - i) * fire + salary * i,cost);
		}
	}
	return note[now][amount] = cost;
}

int main() {
	while(scanf("%d",&n), n) {
		scanf("%d%d%d", &hire, &salary ,&fire);
		memset(note,-1,sizeof(note));
		for(int i = 1;i <= n;i++) scanf("%d", &need[i]);
		printf("%d\n", dfs(1, 0));
	}
	return 0;
}


