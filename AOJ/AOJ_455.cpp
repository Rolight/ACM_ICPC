#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;

struct Node {
    int x,y,h;
    bool operator< (const Node& x) const {
        return h < x.h;
    }
};

int h[maxn][maxn],v[maxn][maxn],nx,ny;
int dx[4] = {0,0,1,-1},dy[4] = {1,-1,0,0};
Node pp[maxn * maxn];

int main() {
    int n,m;  
    while(scanf("%d%d",&n,&m),n || m) {
        memset(h,-1,sizeof(h));
        int cc = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf("%d",&h[i][j]);
                v[i][j] = 1;
                pp[cc++] = (Node){i,j,h[i][j]};
            }
        }
        sort(pp,pp + cc);
        for(int i = 0;i < cc;i++) {
            Node &now = pp[i];
            int x = now.x,y = now.y,vv = v[x][y] + 1;
            for(int j = 0;j < 4;j++) {
                nx = x + dx[j];
                ny = y + dy[j];
                if(h[nx][ny] != -1 && h[nx][ny] > h[x][y] && v[nx][ny] < vv) {
                    v[nx][ny] = vv;
                }
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                ans = max(ans,v[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

