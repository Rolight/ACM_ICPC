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
const int maxn = 205;
const int INF = INT_MAX / 4;
map<string,int> mp;
int d[maxn][maxn],n,m;
string a,b;

int id(string &s) {
    int now = mp.size();
    if(mp.count(s) == 0) mp[s] = now + 1;
    return mp[s];
}

int main() {
    int kase = 1;
    while(cin >> n >> m,n) {
        mp.clear();
        int dist;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                d[i][j] = -1;
            }
        }
        for(int i = 1;i <= m;i++) {
            cin >> a >> b >> dist;
            d[id(a)][id(b)] = d[id(b)][id(a)] = dist;
        }
        for(int k = 1;k <= n;k++) {
            for(int i = 1;i <= n;i++) {
                for(int j = 1;j <= n;j++) {
                    d[i][j] = max(d[i][j],
                            min(d[i][k],d[j][k]));
                }
            }
        }
        cin >> a >> b;
        cout << "Scenario #" << kase++ << endl;
        cout << d[id(a)][id(b)] << " " << "tons" << endl;
        cout << endl;
    }
    return 0;
}
