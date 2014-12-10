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
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const LL lim = 1e9;

LL gcd(LL a,LL b) {
    return b == 0 ? a : gcd(b, a %b );
}

int main() {
        int n; cin >> n;
        if(n == -1) return 0;
        LL sum = 0;
        for(int i = 1;i <= n / 2;i++) {
            LL a1,a2; cin >> a1 >> a2;
            sum += gcd(a1,a2);
        }
        if(n & 1) cin >> n;
        cout << sum << endl;
    return 0;
}
