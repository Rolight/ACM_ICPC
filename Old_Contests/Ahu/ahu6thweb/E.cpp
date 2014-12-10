#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>

using namespace std;

const int maxn = 45;

int on[maxn][maxn][maxn];
int dx[8] = {0,0,1,-1,0,0};
int dy[8] = {1,-1,0,0,0,0};
int dz[8] = {0,0,0,0,1,-1};
int n,m;

struct Node {
    int x,y,z,time;
    Node(int xx,int yy,int zz,int t) {
        x = xx; y = yy; z = zz; time = t;
    }
};

queue<Node> q[maxn * maxn * maxn];
int coc[maxn * maxn * maxn];

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        int cc = 0;
        memset(on,-1,sizeof(on));
        memset(coc,0,sizeof(coc));
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) for(int k = 1;k <= n;k++) on[i][j][k] = 0;
        for(int i = 1;i <= m;i++) {
            int x,y,z; scanf("%d%d%d",&x,&y,&z);
            on[x + 1][y + 1][z + 1] = i;
            q[i].push(Node(x + 1,y + 1,z + 1,0));
            coc[i]++;
        }
        int nt = 0;
        bool ok = true;
        while(ok) {
            ok = false;
            for(int i = 1;i <= m;i++) {
                while(!q[i].empty() &&q[i].front().time == nt) {
                    Node &now = q[i].front();
                    ok = true;
                    int x = now.x,y = now.y,z = now.z;
                    for(int d = 0;d < 8;d++) {
                        int nx = x + dx[d],ny = y + dy[d],nz = z + dz[d];
                        if(on[nx][ny][nz] == 0) {
                            on[nx][ny][nz] = i;
                            coc[i]++;
                            cc--;
                            q[i].push(Node(nx,ny,nz,nt + 1));
                        }
                    }
                    q[i].pop();
                }
            }
            nt++;
        }
        bool first = true;
        for(int i = 1;i <= m;i++) {
            if(first) first = false;
            else putchar(' ');
            printf("%d",coc[i]);
        }
        printf("\n");
    }
    return 0;
}

