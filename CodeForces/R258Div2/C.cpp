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

void swap(LL &a,LL &b) {
    LL tmp = a; a = b; b = tmp;
}

LL n,k,d1,d2; 
bool ok(LL a,LL b,LL c) {
    if(a < 0 || b < 0 || c < 0) return false;
    LL arr[3] = {a,b,c};
    sort(arr,arr + 3);
    LL sq = 2 * arr[2] - arr[1] - arr[0];
    if(sq > (n - k)) return false;
    return (n - k - sq) % 3 == 0;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        LL a,b,c;
        cin >> n >> k >> d1 >> d2;
        bool ret = false;
        if(d1 < d2) swap(d1,d2);
        if((k + 2 * d1 + d2) % 3 == 0) {
            a = (k + 2 * d1 + d2) / 3;
            b = a - d1; c = b - d2;
            ret |= ok(a,b,c);
        }
        if((k + 2 * d1 - d2) % 3 == 0) {
            a = (k + 2 * d1 - d2) / 3;
            b = a - d1; c = b + d2;
            ret |= ok(a,b,c);
        }
        if((k - 2 * d1 + d2) % 3 == 0) {
            a = (k - 2 * d1 + d2) / 2;
            b = a + d1; c = b - d2;
            ret |= ok(a,b,c);
        }
        if((k - 2 * d1 - d2) % 3 == 0) {
            a = (k - 2 * d1 - d2) / 3;
            b = a + d1; c = b + d2;
            ret |= ok(a,b,c);
        }
        if(ret) puts("yes");
        else puts("no");
    }
    return 0;
}
