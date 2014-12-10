#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
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

using namespace std;
const int maxn = 100000 + 5;
const int maxm = 1000000 + 6;

struct Node {
    int d,id;
    bool operator < (const Node &x) const {
        return d < x.d;
    }
};

int n,k,l[maxm],r[maxm];
bool vis[maxn];
Node a[maxn];

void solve() {
    sort(a + 1,a + n + 1);
    if(a[1].d != 0 || a[1].d == a[2].d) {
        puts("-1"); return;
    }
    int fpos = 1,cpos = 2,cnt = 0;
    vis[1] = true;
    for(int i = 1;i <= n;i++) {
        if(vis[i] == false) {
            printf("-1\n"); return;
        }
        int nowcnt = 0,m = i == 1 ? k : k - 1;
        while(nowcnt < m && a[cpos].d == a[i].d + 1 && cpos <= n) {
            l[cnt] = a[i].id; r[cnt] = a[cpos].id; vis[cpos] = true;
            nowcnt++;  cnt++; cpos++;
        }
    }
    printf("%d\n",cnt);
    for(int i = 0;i < cnt;i++) printf("%d %d\n",l[i],r[i]);
}

int main() {
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&a[i].d);
        a[i].id = i;
    }
    solve();
}
