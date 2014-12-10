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
const int maxn = 30;
const int maxv = 26 * 26 * 20 + 5;
int val[maxn],cnt[maxn];
int c1[maxv],c2[maxv];

int main() {
    int T; scanf("%d",&T);
    for(int i = 1;i <= 26;i++) val[i] = i;
    while(T--) {
        int n = 26;
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        int sum = 0;
        for(int i = 1;i <= n;i++) scanf("%d",&cnt[i]);
        for(int i = 1;i <= n;i++) sum += cnt[i] * val[i];
        c1[0] = 1;
        for(int i = 1;i <= n;i++) {
            for(int j = 0;j <= cnt[i];j++) {
                for(int k = 0;k + j * val[i] <= sum;k++) {
                    c2[k + j * val[i]] += c1[k];
                }
            }
            for(int j = 0;j <= sum;j++) {
                c1[j] = c2[j]; c2[j] = 0;
            }
        }
        int ans = 0;
        for(int i = 1;i <= 50;i++) ans += c1[i];
        printf("%d\n",ans);
    }
    return 0;
}
