#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <iostream>
#include <string>

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
    LL kmin, kmax, n, m;
    cin >> n >> m;
    if(n == m) {
        kmin = kmax = 0;
    }
    else {
        if(n % m == 0) {
            LL t = n / m;
            kmin = t * (t - 1) / 2 * m;
        }
        else {
            LL t = n / m, t1 = n / m + 1;
            LL cntt = m - n % m, cntt1 = n % m;
            kmin = cntt * t * (t - 1) / 2 + cntt1 * t1 * (t1 - 1) / 2;
        }
        kmax = (n - m + 1) * (n - m) / 2;
    }
    cout << kmin << " " << kmax << endl;
    return 0;
}
