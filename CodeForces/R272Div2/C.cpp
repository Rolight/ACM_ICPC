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
const LL mod = 1e9 + 7;

LL gao(LL a, LL b) {
	LL sa = (1 + a) * a / 2, sb = b * (b - 1) / 2;
	sa %= mod; sb %= mod;
	return (sa * b % mod + a) % mod * sb % mod;
}

int main() {
	LL a, b;
	while(cin >> a >> b) {
		cout << gao(a, b) << endl;
	}
    return 0;
}
