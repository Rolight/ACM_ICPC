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

int main() {
	LL n, m;
	while(cin >> n >> m) {
		LL ans1 = 0, ans2 = 0;
		if(n > m) swap(n, m);
		for(LL i = n; i <= m; i++) {
			if(i & 1) ans2 += i * i * i;
			else ans1 += i * i;
		}
		cout << ans1 << " " << ans2 << endl;
	}
    return 0;
}
