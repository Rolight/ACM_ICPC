/*
ID: flsnnx1
LANG: C++
TASK: ttwo
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 15;
const int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
char buf[maxn][maxn];
int n = 10,fx,fy,cx,cy;
int mf[maxn][maxn],mc[maxn][maxn];

void print_map() {
    puts("");
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(i == fx && j == fy) printf("F");
            else if(i == cx && j == cy) printf("C");
            else printf("%c",buf[i][j]);
        }
        puts("");
    }
    puts("");
}

void solve() {
    int nowtime = 0;
    bool cycf = false,cycc = false;
    int df = 0,dc = 0;
    while(1) {
        if(fx == cx && cy == fy) {
            printf("%d\n",nowtime);
            return;
        }
        if(nowtime > 2000000) {
            puts("0"); return;
        }
        mf[fx][fy] = mc[cx][cy] = 1;
        int nfx = fx + dx[df],nfy = fy + dy[df];
        int ncx = cx + dx[dc],ncy = cy + dy[dc];
        int tmpt = 0;
        if(buf[nfx][nfy] != '.') {
            df = (df + 1) % 4;
            nfx = fx; nfy = fy;
        }
        tmpt = 0;
        if(buf[ncx][ncy] != '.') {
            dc = (dc + 1) % 4;
            ncx = cx; ncy = cy;
        }
        fx = nfx; fy = nfy;
        cx = ncx; cy = ncy;
        nowtime++;
        //printf("nowtime is %d\n",nowtime);
        //print_map();
        //getchar();
    }
}

int main() {
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);
    memset(buf,'*',sizeof(buf));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            scanf(" %c",&buf[i][j]);
            if(buf[i][j] == 'F') {
                fx = i; fy = j;
                buf[i][j] = '.';
            }
            else if(buf[i][j] == 'C') {
                cx = i; cy = j;
                buf[i][j] = '.';
            }
        }
    }
    solve();
    return 0;
}
