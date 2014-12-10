#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>


using namespace std;

struct Square {
    int left,right,up,down;
    bool operator==(const Square &x) const {
        return left == x.left && right == x.right && up == x.up && down == x.down;
    }
};

const int maxn = 30;
int mp[maxn][maxn],n;
Square s[maxn];
int cnt[maxn],ct;
bool vis[maxn];

bool ok(int x,int y,int i) {
    bool ret = true;
    int t;
    if(y > 0 && (t = mp[x][y - 1]) != -1) 
        ret = ret &&  (s[i].left == s[t].right);
    if(x > 0 && (t = mp[x - 1][y]) != -1) 
        ret = ret && (s[i].up == s[t].down);
    return ret;
}

bool dfs(int u) {
    if(u == n * n) return true;
    int x = u / n,y = u % n;
    for(int i = 0;i < ct;i++) {
        if(cnt[i] && ok(x,y,i)) {
            cnt[i]--;
            mp[x][y] = i;
            bool ret = dfs(u + 1);
            if(ret) return ret;
            cnt[i]++;
        }
    }
    return false;
}

int main() {
    int kase = 1;
    while(scanf("%d",&n),n) {
        memset(mp,-1,sizeof(mp));
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        ct = 0;
        if(kase != 1) puts("");
        for(int i = 1;i <= n * n;i++) {
            Square ss;
            scanf("%d%d%d%d",&ss.up,&ss.right,&ss.down,&ss.left);
            bool found = false;
            int j;
            for(j = 0;j < ct;j++) if(ss == s[j]) {
                found = true; break;
            }
            if(found) cnt[j]++;
            else {
                s[ct] = ss; cnt[ct]++; ct++;
            }
        }
        bool ret = dfs(0);
        printf("Game %d: ",kase++);
        if(ret) puts("Possible");
        else puts("Impossible");
    }
    return 0;
}
