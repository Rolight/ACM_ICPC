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
const int maxn = 1005;
int n,vis[maxn];
LL l[maxn],r[maxn];
int cnt;

bool isp(int i,int j) {
    if(l[i] > l[j] && l[i] < r[j]) return true;
    if(r[i] > l[j] && r[i] < r[j]) return true;
    return false;
}

bool dfs(int a,int b) {
    bool ret = false;
    if(a == b) return true;
    vis[a] = true;
    for(int i = 1;i <= cnt;i++) if(!vis[i]) {
        if(isp(a,i)) {
            ret |= dfs(i,b);
        }
        if(ret) break;
    }
    return ret;
}

int main() {
    scanf("%d",&n);
    for(int i = 0;i < n;i++) {
        int cmd,a,b;
        scanf("%d%d%d",&cmd,&a,&b);
        if(cmd == 1) {
            ++cnt;
            l[cnt] = a; r[cnt] = b;
        } else {
            memset(vis,0,sizeof(vis));
            if(dfs(a,b)) {
                puts("YES");
            } else puts("NO");
        }
    }
    return 0;
}
