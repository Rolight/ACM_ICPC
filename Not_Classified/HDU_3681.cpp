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
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 20;
const int dx[] = {0,0,-1,1},dy[] = {1,-1,0,0};
char mp[maxn][maxn];
int n,m,Ycnt,tmpdist[maxn][maxn];
int ID[maxn][maxn],pcnt,Sx,Sy,dist[maxn][maxn];
int f[maxn][1 << 17];
bool vis[maxn][maxn];

bool input() {
    pcnt = Ycnt  = 0;
    scanf("%d%d",&n,&m);
    if(!n && !m) return false;
    memset(mp,'D',sizeof(mp));
    memset(ID,-1,sizeof(ID));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            scanf(" %c",&mp[i][j]);
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(mp[i][j] == 'F') {
                ID[i][j] = pcnt++,Ycnt++;
                break;
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(mp[i][j] == 'Y') ID[i][j] = pcnt++,Ycnt++;
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) if(mp[i][j] == 'G') {
            ID[i][j] = pcnt++;
        }
    }
    return true;
}

void bfs(int Ox,int Oy) {
    memset(vis,0,sizeof(vis));
    memset(tmpdist,0,sizeof(tmpdist));
    int x,y;
    queue<int> qx,qy;
    qx.push(Ox); qy.push(Oy);
    vis[Ox][Oy] = true;
    while(!qx.empty()) {
        x = qx.front(); y = qy.front();
        qx.pop(); qy.pop();
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i],ny = y + dy[i];
            if(mp[nx][ny] != 'D' && !vis[nx][ny]) {
                vis[nx][ny] = true;
                qx.push(nx); qy.push(ny); 
                tmpdist[nx][ny] = tmpdist[x][y] + 1;
            }
        }
    }
    int nowID = ID[Ox][Oy];
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) if(tmpdist[i][j]) {
            dist[nowID][ID[i][j]] = tmpdist[i][j];
        }
    }
}

bool ok(int Val) {
    int FinalState = (1 << Ycnt) - 1;
    memset(f,-1,sizeof(f));
    f[0][1] = Val;
    for(int st = 0;st < (1 << pcnt);st++) {
        for(int i = 0;i < pcnt;i++) if((1 << i) & st) {
            if(f[i][st] == -1) continue;
            if((st & FinalState) == FinalState) return true; 
            for(int j = 0;j < pcnt;j++) if(!((1 << j) & st) && dist[i][j] != -1) {
                int nextVal = f[i][st] - dist[i][j];
                int nextState = st | (1 << j);
                if(nextVal < 0) continue;
                f[j][nextState] = max(f[j][nextState],j < Ycnt ? nextVal : Val);
            } 
        }
    }
    return false;
}

int solve() {
    memset(dist,-1,sizeof(dist));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) if(ID[i][j] != -1) {
            bfs(i,j);
        }
    }
    int l = 0,r = n * m + 5,ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(ok(mid)) {
            ans = mid; r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}

int main() {
    while(input()) printf("%d\n",solve());
    return 0;
}
