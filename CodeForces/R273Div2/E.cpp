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

LL lim[16], n, k, cnt;
LL ans = -1;
LL f[20][3][20];

LL gao(int now, int pre, int pnum, LL nownum) {
    if(now == 0) return 1;
    if(~pnum && f[now][pre][pnum] != -1) return f[now][pre][pnum];
    LL ret = 0;
    for(int i = 0; i <= 9; i++) {
        LL sb = (nownum * 10) + i;
        if(pnum == -1) {
            if(i == 0) ret += gao(now - 1, 0, -1, sb);
            else ret += gao(now - 1, 0, i, sb) + gao(now - 1, 1, i, sb);
        }
        else {
            if(pre == 1 && i <= pnum) continue;
            if(pre == 0 && i >= pnum) continue;
            ret += gao(now - 1, pre ^ 1, i, sb);
        } 
    }
    if(~pnum) f[now][pre][pnum] = ret;
    return ret;
}

int main() {
    memset(f, -1, sizeof(f));
    cin >> n >> k;
    cout << gao(14, 0, -1, 0) << endl;
    return 0;
}
