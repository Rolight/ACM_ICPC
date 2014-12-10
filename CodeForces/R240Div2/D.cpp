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
const int maxn = 2005;
const LL mod = 1e9 + 7;
int n,k;
LL f[maxn][maxn];

LL dfs(int now,int prev) {
    if(now == k) return 1;
    LL ret = 0;
    if(f[now][prev] != -1) {
        return f[now][prev];
    }
    for(int i = prev;i <= n;i += prev)  {
        ret += dfs(now + 1,i);
        ret %= mod;
    }
    f[now][prev] = ret;
    return ret;
}

int main() {
    cin >> n >> k;
    memset(f,-1,sizeof(f));
    LL ret = dfs(0,1);
    cout << ret << endl;
    return 0;
}
