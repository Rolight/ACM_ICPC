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
const int maxn = 2005;
const int maxlen = 10;
char buf[maxn][maxlen];
int dist[maxn][maxn],lowcase[maxn],n;

int getdist(char *a,char *b) {
    int len = strlen(a),ret = 0;
    for(int i = 0;i < len;i++) if(a[i] != b[i]) ret++;
    return ret;
}

int main() {
    while(scanf("%d",&n),n) {
        int Q = 0;
        for(int i = 1;i <= n;i++) scanf("%s",buf[i]);
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                dist[i][j] = getdist(buf[i],buf[j]);
            }
        }
        for(int i = 1;i <= n;i++) lowcase[i] = dist[1][i];
        lowcase[1] = -1;
        for(int i = 1;i < n;i++) {
            int minv = INT_MAX,x;
            for(int j = 1;j <= n;j++) if(lowcase[j] != -1) {
                if(lowcase[j] < minv) {
                    minv = lowcase[x=j];
                }
            }
            lowcase[x] = -1;
            Q += minv;
            for(int j = 1;j <= n;j++) if(lowcase[j] != -1) {
                lowcase[j] = min(lowcase[j],dist[x][j]);
            }
        }
        printf("The highest possible quality is 1/%d.\n",Q);
    }
    return 0;
}
