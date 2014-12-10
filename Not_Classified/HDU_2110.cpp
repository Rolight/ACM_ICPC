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

using namespace std;
const int maxn = 200;
const int maxv = 100 * 10 * 10 + 10;
const int mod = 10000;
int c1[maxv],c2[maxv];
int cnt[maxn],val[maxn];
int n;

int main() {
    while(scanf("%d",&n),n) {
        bool ok = false;
        int sum = 0;
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i = 1;i <= n;i++) {
            scanf("%d%d",&val[i],&cnt[i]);
            sum += val[i] * cnt[i];
        }
        if(sum % 3 != 0) {
            puts("sorry"); continue;
        }
        c1[0] = 1;
        for(int i = 1;i <= n;i++) {
            for(int j = 0;j <= cnt[i];j++) {
                for(int k = 0;k + j * val[i] <= sum;k++) {
                    c2[k + j * val[i]] += c1[k];
                    c2[k + j * val[i]] %= mod;
                    if(c2[sum / 3] != 0) ok = true;
                }
            }
            for(int j = 0;j <= sum;j++) {
                c1[j] = c2[j]; c2[j] = 0;
            }
        }
        if(!ok) puts("sorry");
        else printf("%d\n",c1[sum /  3] % mod);
    }
    return 0;
}
