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
const int maxn = 1005;

struct Lamp {
    int v,k,c,l;
    Lamp(int v=0,int k=0,int c=0,int l=0):v(v),k(k),c(c),l(l) {}
    bool operator < (const Lamp &x) const {
        return v < x.v;
    }
};

Lamp lamp[maxn];
int n, cost[maxn], cnt[maxn];

int main() {
    while(scanf("%d",&n), n) {
        for(int i = 1;i <= n;i++) {
            int v,k,c,l; scanf("%d%d%d%d",&v,&k,&c,&l);
            lamp[i] = Lamp(v,k,c,l);
        }
        sort(lamp + 1, lamp + 1 + n);
        for(int i = 1;i <= n;i++) cnt[i] = cnt[i - 1] + lamp[i].l;
        for(int i = 1;i <= n;i++) {
            cost[i] = INF;
            for(int j = i;j >= 1;j--) {
                int nowval = cost[j - 1] + (cnt[i] - cnt[j - 1]) * lamp[i].c + lamp[i].k;
                cost[i] = min(cost[i],nowval);
            }
        }
        printf("%d\n",cost[n]);
    }
    return 0;
}
