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
const int maxn = 180 * 50 + 1000;
int f[maxn], d[maxn], n, t, sumt;

int main() {
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        memset(f,0,sizeof(f));
        memset(d,0,sizeof(d));
        scanf("%d%d",&n,&t);
        for(int i = 1;i <= n;i++) {
            int len; scanf("%d",&len);
            for(int j = maxn - 1;j >= len;j--) {
                if(d[j - len] + 1 >= d[j]) {
                    if(d[j - len] + 1 == d[j]) {
                        f[j] = max(f[j - len] + len,f[j]);
                    }
                    else f[j] = f[j - len] + len;
                    d[j] = d[j - len] + 1;
                }
            }
        }
        printf("Case %d: %d %d\n",kase, d[t - 1] + 1, f[t - 1] + 678);
    }
    return 0;
}
