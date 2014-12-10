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
const int maxn = 16;
const int maxs = 1 << maxn;
int cpt[maxn], cover[maxs], n;
int f[maxs];

int main() {
    int kase = 1;
    while(scanf("%d", &n), n) {
        int all_cover = (1 << n) - 1, ns = (1 << n);
        memset(cpt,0,sizeof(cpt));
        memset(cover,0,sizeof(cover));
        memset(f,0,sizeof(f));
        for(int i = 0;i < n;i++) {
            int cnt, tmp; scanf("%d",&cnt);
            for(int j = 0;j < cnt;j++) {
                scanf("%d", &tmp);
                cpt[i] |= (1 << tmp);
            }
            cpt[i] |= (1 << i);
        }

        for(int i = 0;i < ns;i++) {
            for(int j = 0;j < n;j++) if(i & (1 << j)) {
                cover[i] |= cpt[j];
            }
        }

        for(int i = 0;i < ns;i++) {
            for(int s = i; s; s = (s - 1) & i) {
                if(cover[s] == all_cover) {
                    f[i] = max(f[i], f[i ^ s] + 1);
                }
            }
        }
        printf("Case %d: %d\n", kase++, f[all_cover]);
    }
    return 0;
}
