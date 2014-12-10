#include <cstdio>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;
const int maxn = 100;
int dist[maxn][maxn],N,str,ed,d[maxn],b[maxn];
vector<int> path;

int min(int a,int b) {
    return a < b ? a : b;
}

void bellman_ford() {
    for(int i = 1;i <= N;i++) d[i] = INF;
    d[str] = 0;
    for(int i = 1;i <= N;i++) {
        for(int j = 1;j <= N;j++) {
            for(int k = 1;k <= N;k++) if(dist[j][k] != -1) {
                if(d[j] != INF) d[k] = min(d[k],d[j] + dist[j][k]);
            }
        }
    }
}

bool get_path(int now) {
    if(now == ed) return true;
    for(int i = 1;i <= N;i++) if(i != now) {
        if(d[now] + dist[now][i] == d[i]) {
            path.push_back(i);
            bool ret = get_path(i);
            if(ret) return true;
            path.erase(path.end() - 1);
        }
    }
    return false;
}

void print_path() {
    path.clear();
    get_path(str);
    printf("%d",str);
    for(int i = 0;i < path.size();i++) {
        printf("-->%d",path[i]);
    }
    putchar('\n');
}


int main() {
    while(scanf("%d",&N), N) {
        for(int i = 1;i <= N;i++) {
            for(int j = 1;j <= N;j++) {
                scanf("%d",&dist[i][j]);
            }
        }
        for(int i = 1;i <= N;i++) {
            scanf("%d",&b[i]);
            for(int j = 1;j <= N;j++) if(dist[i][j] > 0) {
                dist[i][j] += b[i];
            }
        }
        while(scanf("%d%d",&str,&ed),~str) {
            path.clear();
            for(int i = 1;i <= N;i++) if(dist[str][i] > 0) {
                dist[str][i] -= b[str];
            }
            bellman_ford(); 
            printf("From %d to %d :\n",str,ed);
            printf("Path: ");
            print_path();
            printf("Total cost : %d\n",d[ed]);
            for(int i = 1;i <= N;i++) if(dist[str][i] > 0) {
                dist[str][i] += b[str];
            }
            puts("");
        }
    }
    return 0;
}
