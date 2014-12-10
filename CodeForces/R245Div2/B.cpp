#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

typedef long long LL;
const int maxn = 105;
int col[maxn],n,k,x;

int getval(int pos) {
    int ncol = x,ncnt = 1,pl = pos,pr = pos + 1;
    int ret = 0;
    while(1) {
        if(col[pl] != ncol && col[pr] != ncol) {
            if(ncnt >= 3) {
                ncol = max(col[pl],col[pr]);
                ret += ncnt; ncnt = 0;
                if(ncol == -1) break;
            }
            else break;
        }
        if(col[pl] == ncol) {
            ncnt++; pl = pl - 1;
        } 
        if(col[pr] == ncol) {
            ncnt++; pr = pr + 1;
        }
    }
    return ret - 1;
}

int main() {
    memset(col,-1,sizeof(col));
    scanf("%d%d%d",&n,&k,&x);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&col[i]);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) ans = max(ans,getval(i));
    printf("%d\n",ans);
    return 0;
}


