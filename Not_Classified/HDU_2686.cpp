#include <cstdio>
#include <cstring>

#define max2(a,b) ((a)>(b) ? (a) : (b))
#define max(a,b,c,d) (max2(max2(a,b),max2(c,d)))

using namespace std;

const int maxn = 105;
int mat[maxn][maxn];
int f[maxn + maxn][maxn][maxn];

int main() {
    int n;
    while(scanf("%d",&n) != EOF) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                scanf("%d",&mat[i][j]);
            }
        }
        memset(f,0,sizeof(f));
        for(int k = 1;k < n + n;k++) {
            //第一个走到i第二个走到j
            for(int i = 1;i <= n;i++) {
                for(int j = 1;j <= n;j++) {
                    if(i == j) continue;
                    f[k][i][j] = max(
                        f[k-1][i-1][j],
                        f[k-1][i][j],
                        f[k-1][i][j-1],
                        f[k-1][i-1][j-1]
                            );
                    f[k][i][j] += mat[i][k-i+1] + mat[j][k-j+1];
                    printf("%d %d %d %d\n",k,i,j,f[k][i][j]);
                }
            }
        }
        printf("%d\n",f[n+n-1][n][n-1]);
    }
    return 0;
}
