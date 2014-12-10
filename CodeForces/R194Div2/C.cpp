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

LL mypow(LL a,LL b) {
    if(b == 0) return 1;
    if(b & 1) return mypow(a * a,b / 2) * a;
    return mypow(a * a,b / 2);
}

int main() {
    LL n,a = 3; cin >> n;
    while((n % a) == 0) a *= 3;
    cout << (n / a) + 1 << endl;
    return 0;
}
