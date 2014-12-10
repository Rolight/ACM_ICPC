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
int dist[1000000 + 6];
int n,x[100000 + 5];
int a,b,mm;
vector<int> xx;

void solve() {
    int minval = a;
    memset(dist,-1,sizeof(dist));
    queue<int> q;
    q.push(a);
    dist[a - b] = 0;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        if(now == b) break;
        if(now > minval) continue;
        //-1
        if(now - 1 >= b && dist[now - 1 - b] == -1 && now - 1 < minval) {
            minval = now - 1;
            q.push(now - 1); dist[now - 1 - b] = dist[now - b] + 1;
        }
        //mod
        for(int i = 0;i < n;i++) if(now >= x[i]) {
            int val = now - now % x[i];
            if(val >= b && dist[val - b] == -1 && val < minval) {
                minval = val;
                dist[val - b] = dist[now - b] + 1;
                q.push(val);
            }
        }
    }
    printf("%d\n",dist[0]);
}

int main() {
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d",&x[i]);
      scanf("%d%d",&a,&b);
      solve();
      return 0;
}
