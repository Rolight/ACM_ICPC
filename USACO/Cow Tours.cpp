/*
ID: flsnnx1
LANG: C++
TASK: cowtour
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 155;
int mp[maxn][maxn];
int id[maxn];
double px[maxn],py[maxn];
double dist[maxn][maxn];
double mdis[maxn];
int n;

double getdist(int i,int j) {
    return sqrt((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]));
}

void dfs(int now,int col) {
    id[now] = col;
    for(int i = 1;i <= n;i++) if(mp[now][i]) {
        if(id[i] == 0) dfs(i,col);
    }
}

void print_dist() {
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            printf("%2.2f ",dist[i][j]);
        }
        puts("");
    }
}

void solve() {
    int nowid = 1;
    for(int i = 1;i <= n;i++) {
        if(!id[i]) {
            dfs(i,nowid++);
        }
    }
    for(int k = 1;k <= n;k++) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++)   {
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) if(id[i] == id[j]) {
            mdis[i] = max(mdis[i],dist[i][j]);
        }
    }
    double ans = 1e90,r2 = -1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(id[i] != id[j]) {
                ans = min(ans,getdist(i,j) + mdis[i] + mdis[j]);
            }
        }
        r2 = max(r2,mdis[i]);
    }
    printf("%.6f\n",max(ans,r2));
}

int main() {
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%lf%lf",px + i,py + i);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            scanf("%1d",&mp[i][j]);
            if(mp[i][j] == 1) dist[i][j] = getdist(i,j);
            else dist[i][j] = 1e90;
        }
        dist[i][i] = 0;
    }
    solve();
    return 0;
}
