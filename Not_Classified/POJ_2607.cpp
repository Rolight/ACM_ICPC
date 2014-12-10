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
const int maxn = 505;
const int INF = INT_MAX / 4;
int d[maxn][maxn],f,n,t[maxn],nr[maxn];
char buf[1024];

int main() {
    while(~scanf("%d%d",&f,&n)) {
        for(int i = 1;i <= f;i++) scanf("%d",&t[i]);
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                d[i][j] = INF;
            }
            d[i][i] = 0;
        }
        getchar();
        while(gets(buf)) {
            if(strlen(buf) == 0) break;
            int a,b,c; sscanf(buf,"%d%d%d",&a,&b,&c);
            d[a][b] = d[b][a] = min(d[a][b],c);
        }
        for(int k = 1;k <= n;k++) {
            for(int i = 1;i <= n;i++) {
                for(int j = 1;j <= n;j++) {
                    d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
                }
            }
        }
        int nowval = -1,ans = 1,ansval = INF;
        for(int i = 1;i <= n;i++) {
            int near = INF;
            for(int j = 1;j <= f;j++) near = min(near,d[t[j]][i]);
            nowval = max(nowval,near);
            nr[i] = near;
            //printf("nr %d %d\n",i,nr[i]);
        }
        for(int i = 1;i <= n;i++) if(nr[i] != 0) {
            //printf("now i is %d\n",i);
            int curval = -1;
            for(int j = 1;j <= n;j++) if(i != j) {
                curval = max(curval,min(nr[j],d[i][j]));
             //   printf("%d %d %d\n",curval,nr[j],d[i][j]);
            }
            if(curval < nowval && curval < ansval) {
                ans = i; ansval = curval;
            }
            //printf("%d %d\n",i,curval);
        }
        printf("%d\n",ans);
    }
    return 0;
}
