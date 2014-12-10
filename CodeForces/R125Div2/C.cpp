#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const double eps = 1e-9;

int main() {
    double k,b,n,t; cin >> k >> b >> n >> t;
    int ret;
    if(k != 1) {
        double ans = n + log(1-b/(1-k))/log(k) - log(t-b/(1-k))/log(k);
        ret = ceil(ans - eps);
    } else {
        ret = ceil((1 + n * b - t) / b - eps);
    }
    cout << max(0,ret) << endl;
    return 0;
}
