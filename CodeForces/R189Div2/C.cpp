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
const int maxn = 200;
const LL MOD = 1e9 + 7;
char buf[maxn];

LL mypow(int n) {
    LL ret = 1;
    while(n--) ret = (ret * 2) % MOD;
    return ret;
}

int main() {
    scanf("%s",buf);
    int len = strlen(buf);
    LL ret = mypow(len - 1);
    LL x = 0;
    for(int i = len - 1;i >= 0;i--) {
        if(buf[i] == '1') {
            x += mypow(len - i - 1);
            x %= MOD;
        }
    }
    cout << (x * ret) % MOD << endl;
    return 0;
}
