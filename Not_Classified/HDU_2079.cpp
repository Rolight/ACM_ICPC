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
const int maxn = 10;
const int maxv = 8 * 8 * 10 + 5;
int cnt[maxn],val[maxn];
int c1[maxv],c2[maxv];
int n,k;

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&k);
        int sum = 0;
        for(int i = 1;i <= k;i++) scanf("%d%d",&val[i],&cnt[i]);
        for(int i = 1;i <= k;i++) sum += val[i] * cnt[i];
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        c1[0] = 1;
        for(int i = 1;i <= k;i++) {
            for(int j = 0;j <= cnt[i];j++) {
                for(int k = 0;k + j * val[i] <= sum;k++) {
                    c2[k + j * val[i]] += c1[k];
                }
            }
            for(int i = 0;i <= sum;i++) {
                c1[i] = c2[i]; c2[i] = 0;
            }
        }
        printf("%d\n",c1[n]);
    }
    return 0;
}
