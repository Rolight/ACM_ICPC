#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <climits>
#include <string>


using namespace std;

const int maxn = 25;
const int INF = INT_MAX / 2;

int A,B,C;
int val[maxn][maxn][maxn],sum3[maxn][maxn][maxn];
int mat[maxn][maxn],sum2[maxn][maxn];
int sum[maxn];

int main() {
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        scanf("%d%d%d",&A,&B,&C);
        for(int i = 1;i <= A;i++) {
            for(int j = 1;j <= B;j++) {
                for(int k = 1;k <= C;k++) {
                    scanf("%d",&val[i][j][k]);
                    sum3[i][j][k] = sum3[i][j][k - 1] + val[i][j][k];
                }
            }
        }
        int ans = 0;
        for(int i = 1;i <= C;i++) {
            for(int j = i;j <= C;j++) {

                for(int k = 1;k <= A;k++) {
                    for(int l = 1;l <= B;l++) {
                        mat[k][l] = sum3[k][l][j] - sum3[k][l][i - 1];
                    }
                }

                for(int k = 1;k <= A;k++) {
                    for(int l = 1;l <= B;l++) {
                        sum2[k][l] = sum2[k][l - 1] + mat[k][l];
                    }
                }

                for(int k = 1;k <= B;k++) {
                    for(int l = k;l <= B;l++) {
                        for(int o = 1;o <= A;o++) {
                            sum[o] = sum2[o][l] - sum2[o][k - 1];
                        }           
                        int vv = -INF;
                        for(int o = 1;o <= A;o++) {
                            vv = max(sum[o] + vv,sum[o]);
                            ans = max(ans,vv);
                        }
                    }
                }

            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
