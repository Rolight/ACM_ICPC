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
const int maxn = 105;
map<string,int> mp;
int maxcost[maxn][maxn],cost[maxn][maxn];
int n,cnt,str,ed;
string a,b;

int id(string &s) {
    if(mp.count(s) == 0) mp[s] = ++cnt;
    return mp[s];
}

int main() {
    while(cin >> a >> b) {
        mp.clear();
        cnt = 0;
        str = id(a); ed = id(b);
        cin >> n;
        memset(maxcost,-1,sizeof(maxcost));
        memset(cost,-1,sizeof(cost));
        for(int i = 1;i <= n;i++) {
            int cc;
            cin >> a >> b >> cc;
            cost[id(a)][id(b)] = cost[id(b)][id(a)] = 0;
            maxcost[id(a)][id(b)] = maxcost[id(a)][id(b)] = cc;
        }
        for(int k = 1;k <= cnt;k++) {
            for(int i = 1;i <= cnt;i++) {
                for(int j = 1;j <= cnt;j++) if(cost[i][k] != -1 && cost[k][j] != -1) {
                    int ca = cost[i][j];
                    int cb = cost[i][k] + cost[k][j] + min(maxcost[i][k],maxcost[k][j]);
                    if(cb < ca || ca == -1) {
                        cost[i][j] = cb;
                        maxcost[i][j] = max(maxcost[i][k],maxcost[k][j]);
                    }
                }
            }
        }
        printf("%d\n",cost[str][ed]);
    }
    return 0;
}
