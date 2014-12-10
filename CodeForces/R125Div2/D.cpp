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
const int maxn = 100000 + 5;
char wall[4][maxn];
int t[4][maxn];
int n,k;

bool bfs(int x,int y) {
    int nt;
    queue<int> qx,qy;
    qx.push(0); qy.push(0);
    memset(t,-1,sizeof(t));
    t[0][0] = 0;
    while(!qx.empty()) {
        x = qx.front(); y = qy.front(); nt = t[y][x];
        qx.pop(); qy.pop();
        if(x + 1 >= n) return true;
        if(t[y][x + 1] == -1 && wall[y][x + 1] != 'X') {
            t[y][x + 1] = nt + 1; qx.push(x + 1); qy.push(y);
        }
        if(x - 1 > nt && t[y][x - 1] == -1 && wall[y][x - 1] != 'X') {
            t[y][x - 1] = nt + 1; qx.push(x - 1); qy.push(y);
        }
        if(x + k >= n) return true;
        if(t[y ^ 1][x + k] == -1 && wall[y ^ 1][x + k] != 'X') {
            t[y ^ 1][x + k] = nt + 1; qx.push(x + k); qy.push(y ^ 1);
        }
    }
    return false;
}

int main() {
    scanf("%d%d%s%s",&n,&k,wall[0],wall[1]);
    bool ret = bfs(0,0);
    if(ret) puts("YES");
    else puts("NO");
    return 0;
}
