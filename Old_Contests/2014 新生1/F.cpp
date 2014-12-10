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
int mlim[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int y, m, d;

int main() {
	while(scanf("%d/%d/%d", &y, &m, &d) != EOF) {
		if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) mlim[2] = 29;
		int ans = 0;
		for(int i = 1; i < m; i++) 
			for(int j = 1; j <= mlim[i]; j++) ans++;
		ans += d;
		printf("%d\n", ans);
		mlim[2] = 28;
	}
    return 0;
}
