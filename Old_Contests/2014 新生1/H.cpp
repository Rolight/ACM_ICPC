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
int f[200][200];

int main() {
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <= i; j++) cin >> f[i][j];
		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <= i; j++) 
				f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + f[i][j];
		int ans = 0;
		for(int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
		cout << ans << endl;
	}
    return 0;
}
