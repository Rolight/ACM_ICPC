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

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL; 
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 1005;
typedef pair<pii,pii> ppp;
int n,m,q;
int mp[maxn][maxn];
int down[maxn][maxn],up[maxn][maxn];

void insert(int a,int b) {
    mp[a][b] = 1;
    if(mp[a - 1][b]) {
        int dpp = mp[a + 1][b] ? down[a + 1][b] : a,pos = a;
        while(pos >= 1 && mp[pos][b]) down[pos--][b] = dpp;
    }
    if(mp[a + 1][b]) {
        int upp = mp[a - 1][b] ? up[a - 1][b] : a,pos = a;
        while(pos <= n && mp[pos][b]) up[pos++][b] = upp;
    }
}

void erase(int a,int b) {
    mp[a][b] = 0;
    if(mp[a - 1][b]) {
        int dpp = a + 1,pos = a;
        while(pos >= 1 && mp[pos][b]) down[pos--][b] = dpp;
    }
    if(mp[a + 1][b]) {
        int upp = a - 1,pos = a;
        while(pos <= n && mp[pos][b]) up[pos++][b] = upp;
    }
}

int fleft[maxn],fright[maxn];
int query(int a,int b) {
    if(mp[a][b] == 0) return 0;
    int pl = b,pr = b,sq = 0,ansl = -1,ansr = INF;
    while(mp[a][pl] && pl >= 1) pl--;
    while(mp[a][pr] && pr <= m) pr++;
    pl++; pr--;
    for(int i = pl;i <= pr;i++) fleft[i] = fright[i] = i;
    for(int i = pl;i <= pr;i++) {
        while(up[a][fleft[i] - 1] >= up[a][i]) fleft[i] = fleft[fleft[i] - 1];
    }
    for(int i = pr;i >= pl;i--) {
        while(up[a][fright[i] + 1] >= up[a][i]) fright[i] = fright[fright[i] + 1];
    }
    ansl = max(ansl,fleft[b]); ansr = min(ansr,fright[b]);
    down[a][pl - 1] = down[a][pr + 1] = INF;
    for(int i = pl;i <= pr;i++) fleft[i] = fright[i] = i;
    for(int i = pl;i <= pr;i++) {
        while(down[a][fleft[i] - 1] <= down[a][i]) fleft[i] = fleft[fleft[i] - 1];
    }
    for(int i = pr;i >= pl;i--) {
        while(down[a][fright[i] + 1] <= down[a][i]) fright[i] = fright[fright[i] + 1];
    }
    ansl = max(ansl,fleft[b]); ansr = min(ansr,fright[b]);
    return (ansr - ansl + 1) * (up[a][b] - down[a][b] + 1);
}

int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            scanf("%d",&mp[i][j]);
            if(mp[i][j]) insert(i,j);
            down[i][j] = up[i][j] = i;
        }
    }
    for(int i = 1;i <= q;i++) {
        int cmd,a,b; scanf("%d%d%d",&cmd,&a,&b);
        if(cmd == 1) {
            if(mp[a][b]) erase(a,b);
            else insert(a,b);
        }
        else printf("%d\n",query(a,b));
    }
    return 0;
}
