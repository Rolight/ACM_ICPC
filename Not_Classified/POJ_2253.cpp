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
const int maxn = 205;
double d[maxn][maxn],posx[maxn],posy[maxn];
int n;

double dist(double x1,double x2,double y1,double y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
    int kase = 1;
    while(scanf("%d",&n),n) {
        for(int i = 1;i <= n;i++) {
            scanf("%lf%lf",&posx[i],&posy[i]);
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                d[i][j] = dist(posx[i],posx[j],posy[i],posy[j]);
                if(i == j) d[i][j] = 1e50;
            }
        }
        for(int k = 1;k <= n;k++) {
            for(int i = 1;i <= n;i++) {
                for(int j = 1;j <= n;j++) {
                    d[i][j] = min(d[i][j],max(d[i][k],d[j][k]));
                }
            }
        }
        printf("Scenario #%d\n",kase++);
        printf("Frog Distance = %.3f\n\n",d[1][2]);
    }
    return 0;
}
