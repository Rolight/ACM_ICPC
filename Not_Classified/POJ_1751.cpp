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
const int maxn = 800;
double posx[maxn],posy[maxn],lowcost[maxn],dist[maxn][maxn];
int tolowcost[maxn];
bool vis[maxn];
vector< pair<int,int> > ans;
double sq(double x) { return x * x; }

int main() {
    int N,M;
    while(scanf("%d",&N) != EOF) {
        memset(vis,0,sizeof(vis));
        ans.clear();
        for(int i = 1;i <= N;i++) {
            scanf("%lf%lf",&posx[i],&posy[i]);
        }
        for(int i = 1;i <= N;i++) {
            for(int j = 1;j <= N;j++) if(i != j) {
                dist[i][j] = sqrt(sq(posx[i]-posx[j]) + sq(posy[i]-posy[j]));
            }
        }
        scanf("%d",&M);
        for(int i = 1;i <= M;i++) {
            int a,b; scanf("%d%d",&a,&b);
            dist[a][b] = dist[b][a] = 0;
        }
        for(int i = 1;i <= N;i++) {
            lowcost[i] = dist[1][i];
            tolowcost[i] = 1;
        }
        vis[1] = true;
        for(int i = 2;i <= N;i++) {
            double minv = 1e90;
            int x;
            for(int j = 1;j <= N;j++) if(!vis[j]){
                 if(lowcost[j] < minv) {
                     minv = lowcost[j];
                     x = j;
                 }
            }
            vis[x] = true;
            if(lowcost[x] != 0) printf("%d %d\n",tolowcost[x],x);
            for(int j = 1;j <= N;j++) if(!vis[j]) {
                if(dist[x][j] < lowcost[j]) {
                    lowcost[j] = dist[x][j];
                    tolowcost[j] = x;
                }
            }
        }
        /*
        puts("\n\n\n");
        for(auto iter = ans.begin();iter != ans.end();iter++) {
            printf("%d %d\n",iter->first,iter->second);
        }
        */
    }
    return 0;
}
