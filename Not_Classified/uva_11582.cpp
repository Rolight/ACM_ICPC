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

typedef unsigned long long LL;
LL n,a,b,r;

LL mypow(LL a,LL b) {
    if(b == 0) return 1;
    a %= r;
    if(b & 1) return mypow(a * a % r,b / 2) % r * a % r;
    else return mypow(a * a % r,b / 2) % r;
}

void solve() {
    LL now = 1,prev = 0,round = 1;
    while(1) {
        LL tmp = now; now = now + prev; prev = tmp;
        now %= n; prev %= n;
        if(round != 1 && now == 1 % n && prev == 0) break;
        round++;
    }
    r = round;
    LL t = mypow(a,b);
    if(t == 0) cout << 0 << endl;
    else if(t == 1) cout << 1 % n << endl;
    else {
        prev = 1; now = 0;
        for(int i = 1;i <= t;i++) {
            LL tmp = now; now += prev; now %= n; prev = tmp;
        }
        cout << now % n << endl;
    }
}

int main() {
    int T; cin >> T;
    while(T--) {
        cin >> a >> b >> n;
        solve();
    }
    return 0;
}
