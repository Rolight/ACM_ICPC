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
	int n;
	while(cin >> n, n) {
		double tmp;
		int c1 = 0, c2 = 0, c3 = 0;
		while(n--) {
			cin >> tmp;
			if(tmp == 0) c2++;
			else if(tmp > 0) c1++;
			else c3++;
		}
		cout << c3 << " " << c2 << " " << c1 << endl;
	}
    return 0;
}
