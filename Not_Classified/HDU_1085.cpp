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
const int maxn = 1000 + 2 * 1000 + 5 * 1000 + 5;
int c1[maxn],c2[maxn],lim[3],val[3] = {1,2,5};

int main() {
    while(scanf("%d%d%d",&lim[0],&lim[1],&lim[2]),lim[0] + lim[1] + lim[2]) {
        int maxval = lim[0] + 2 * lim[1] + 5 * lim[2];
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i = 0;i <= lim[0];i++) {
            c1[i] = 1;
        }
        for(int i = 1;i < 3;i++) {
            for(int j = 0;j <= lim[i];j++) {
                for(int k = 0;k + j * val[i] <= maxval;k++) {
                    c2[k + j * val[i]] += c1[k];
                }
            }
            for(int i = 0;i <= maxval;i++) {
                c1[i] = c2[i]; c2[i] = 0;
            }
        }
        int ans = 0;
        for(int i = 0;i <= maxval + 10;i++) if(!c1[i]) {
            ans = i; break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
