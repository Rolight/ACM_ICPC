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

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 405;
map<string,int> mp;
bool e[maxn][maxn];
int n,scnt,fa[maxn];
int col[maxn];
string sa,sb;

int findp(int x) {
    return x == fa[x] ? x : fa[x] = findp(fa[x]);
}

inline int idx(string &str) {
    if(mp.count(str) == 0) {
        mp[str] = scnt++;
    }
    return mp[str];
}

bool dfs(int now,int nc) {
    bool ret = true;
    col[now] = nc;
    for(int i = 0;i < scnt;i++) if(e[now][i] == true) {
        if(col[i] == -1) ret &= dfs(i,nc ^ 1);
        else if(col[i] == nc) return false;
    }
    return ret;
}

int main() {
    int kase = 1;
    int T; cin >> T;
    while(T--) {
        scnt = 0;
        memset(e,0,sizeof(e));
        memset(col,-1,sizeof(col));
        mp.clear();
        int n; cin >> n;
        for(int i = 0;i < n;i++) {
            cin >> sa >> sb;
            int a = idx(sa),b = idx(sb);
            e[a][b] = e[b][a] = true;
        }
        bool ret = true;
        for(int i = 0;i < scnt;i++) if(col[i] == -1) {
            ret &= dfs(i,0);
        }
        printf("Case #%d: ",kase++);
        if(ret) puts("Yes");
        else puts("No");
    }
    return 0;
}
