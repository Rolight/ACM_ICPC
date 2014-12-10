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

struct Node {
	int a, b;
	bool operator < (const Node &x) const {
		if(b == x.b) return a < x.a;
		return b < x.b;
	}
};

Node a[105];

int main() {
	int n;
	while(cin >> n, n) {
		for(int i = 1; i <= n; i++) cin >> a[i].a >> a[i].b;
		sort(a + 1, a + 1 + n);
		int ans = 0, nowb = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i].a < nowb) continue;
			ans++;
			nowb = a[i].b;
		}
		cout << ans << endl;
	}
    return 0;
}
