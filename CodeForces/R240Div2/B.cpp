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
const int INF = INT_MAX;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 100000 + 5;

ULL getval(ULL x,ULL a,ULL b) {
    ULL mon = x * a / b;
    if(mon == 0) return x;
    ULL l = 0,r = x,ans = 0;
    while(l <= r) {
        ULL mid = (l + r) / 2;
        if(mid * a / b >= mon) {
            r = mid - 1; ans = mid;
        } else l = mid + 1;
    }
    return x - ans;
}

int main() {
    ULL n,a,b;
    cin >> n >> a >> b;
    for(int i = 1;i <= n;i++) {
        ULL x; cin >> x;
        if(i > 1)  cout << " ";
        cout << getval(x,a,b);
    }
    cout << endl;
    return 0;
}
