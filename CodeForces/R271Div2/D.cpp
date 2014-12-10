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
const int maxnode = 1500 * 1500 + 50;
const int sigma_size = 26;
int ch[maxnode][sigma_size],badcnt[maxnode],sz;
char buf[1506],vis[maxnode];
bool gd[26];
int n,k;

int idx(char c) {
    return c - 'a';
}

void solve() {
    int len = strlen(buf + 1);
    int ans = 0;
    sz = 1;
    for(int str = 1;str <= len;str++) {
        int u = 0,nbadcnt = 0;
        for(int i = str;i <= len;i++) {
            int nc = idx(buf[i]);
            if(ch[u][nc] == 0) {
                ch[u][nc] = sz++;
            }
            u = ch[u][nc];
            nbadcnt += !gd[nc];
            if(vis[u] == false) {
                vis[u] = true;
                if(nbadcnt <= k) ans++;
            }
        }
    }
    printf("%d\n",ans);
}

int main() {
    scanf("%s",buf + 1);
    for(int i = 0;i < 26;i++) {
        int t; scanf("%1d",&t);
        gd[i] = t;
    }
    scanf("%d",&k);
    solve();
    return 0;
}
