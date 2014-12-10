#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <sstream>
#include <numeric>
#include <fstream>
#include <functional>
 
using namespace std;
 
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 15;
char my[maxn], cmd[maxn];
int len, cnt, sum, opos;

void dfs(int cid, int pos) {
	if(cid == len) {
		sum++;
		if(pos == opos) cnt++;
		return;
	}
	if(cmd[cid] == '+') dfs(cid + 1, pos + 1);
	else if(cmd[cid] == '-') dfs(cid + 1, pos - 1);
	else { 
		dfs(cid + 1, pos + 1);
		dfs(cid + 1, pos - 1);
	}
}

int main() {
	scanf("%s%s", my, cmd);
	len = strlen(cmd);
	int len2 = strlen(my);
	for(int i = 0; i < len2; i++) {
		if(my[i] == '+') opos++;
		else opos--;
	}
	dfs(0, 0);
	printf("%.13f\n", (double)cnt / sum);
    return 0;
}
