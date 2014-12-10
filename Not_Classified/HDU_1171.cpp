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
const int maxn = 55;
const int maxv = 50 * 50 * 100 + 5;
int c1[maxv],c2[maxv];
int val[maxn],cnt[maxn],n;

int main() {
    while(scanf("%d",&n),n >= 0) {
        int sum = 0;
        for(int i = 0;i < n;i++) {
            scanf("%d%d",&val[i],&cnt[i]);
            sum += val[i] * cnt[i];
        }
        memset(c1,0,sizeof(int) * sum);
        memset(c2,0,sizeof(int) * sum);
        c1[0] = 1;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j <= cnt[i];j++) {
                for(int k = 0;val[i] * j + k <= sum;k++) {
                    c2[val[i] * j + k] += c1[k];
                }
            }
            for(int j = 0;j <= sum;j++) {
                c1[j] = c2[j]; c2[j] = 0;
            }
        }
        int mindelta = INT_MAX,a1 = 0,a2 = 0;
        for(int i = 0;i <= sum;i++) if(c1[i]) {
            int nowd = abs(2 * i - sum);
            if(nowd < mindelta) {
                mindelta = nowd;
                a1 = max(i,sum - i);
                a2 = sum - a1;
            }
        }
        printf("%d %d\n",a1,a2);
    }
    return 0;
}
