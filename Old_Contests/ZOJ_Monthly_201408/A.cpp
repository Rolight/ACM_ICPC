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
typedef pair<int, int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 50000 + 5;
int n, a[maxn], b[maxn];


int main() {
	while (scanf("%d", &n) != EOF) {
		if (n == 1) {
			printf("1 1\n1\n1\n");
			continue;
		}
		for (int i = 1, val = n; i <= n; i++, val--) a[i] = val;
		for (int i = 1, val = n - 1; i <= n - 1; i++, val--) b[i] = val;
		b[n] = n;
		int minval = a[1], maxval = b[1];
		for (int i = 2; i <= n; i++) {
			minval = abs(minval - a[i]);
			maxval = abs(maxval - b[i]);
		}
		printf("%d %d\n", minval, maxval);
		for (int i = 1; i <= n; i++) printf("%d ", a[i]);
		putchar('\n');
		for (int i = 1; i <= n; i++) printf("%d ", b[i]);
		putchar('\n');
	}
	return 0;
}