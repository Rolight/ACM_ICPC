##include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

LL gao(int n) {
    LL ret = 0;
    while(n) {
        ret = (ret << 1) | (n & 1);
        n >>= 1;
    }
    return ret;
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        LL n; cin >> n;
        cout << gao(n) << endl;
    }
    return 0;
}
