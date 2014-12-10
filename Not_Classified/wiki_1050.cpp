#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;
const int maxs = 1 << 5;
int buf[maxn],colVal[maxn],n;
int cnt1[maxs],f[maxn][maxs];

void init() {
    for(int i = 0;i < maxs;i++) 
        for(int j = 0;j < 5;j++) 
            if(i & (1 << j)) cnt1[i]++;
}

int main() {
    init();
    memset(f,0x3f,sizeof(f));
    int ans = f[0][0];
    memset(f[0],0,sizeof(f[0]));
    scanf("%d",&n);
    colVal[0] = maxs - 1;
    for(int i = 1;i <= n;i++) {
        int tmp;
        colVal[i] = 0;
        for(int j = 0;j < 5;j++) {
            scanf("%1d",&tmp);
            colVal[i] = (colVal[i] << 1) | tmp;
        }
    }
    for(int i = 0;i < maxn;i++) {
        for(int j = 0;j < maxs;j++) if((j & colVal[i]) == colVal[i]) {
            for(int k = 0;k < maxs;k++) if((k & j) && (k & colVal[i + 1]) == colVal[i + 1]) {
                f[i + 1][k] = min(f[i + 1][k],f[i][j] + cnt1[k & ~colVal[i + 1]]);
            }
        } 
    }
    for(int i = 0;i < maxs;i++) ans = min(ans,f[n][i]);
    printf("%d\n",ans);
    return 0;
}
