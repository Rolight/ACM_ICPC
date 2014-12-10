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
const int maxn = 20;
const int maxm = 200;
int num[maxn][maxm], n, m;
int f[maxn][maxm], pre[maxn][maxm];

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                scanf("%d",&num[i][j]);
            }
        }
        memset(f,0x3f,sizeof(f));
        for(int i = 0;i < n;i++) f[i][m - 1] = num[i][m - 1];
        for(int j = m - 1;j > 0;j--) {
            for(int i = 0;i < n;i++) {
                int c[3] = {i,(i + 1) % n,(i - 1 + n) % n};
                for(int k = 0;k < 3;k++) {
                    if(f[c[k]][j - 1] > f[i][j] + num[c[k]][j - 1]) {
                        f[c[k]][j - 1] = f[i][j] + num[c[k]][j - 1];
                        pre[c[k]][j - 1] = i;
                    }
                }
            }
        }
        int ans = INF;
        for(int i = 0;i < n;i++) ans = min(ans,f[i][0]);
        for(int i = 0;i < n;i++) if(ans == f[i][0]) {
            int nowrow = i;
            printf("%d",nowrow + 1);
            for(int j = 1;j < m;j++) {
                nowrow = pre[nowrow][j - 1];
                printf(" %d",nowrow + 1);
            }
            break;
        }
        printf("\n%d\n",ans);
    }
    return 0;
}
