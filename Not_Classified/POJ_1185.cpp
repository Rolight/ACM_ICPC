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
#include <stack>
#include <sstream>
#include <numeric>
#include <fstream>
#include <functional>

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
const int maxn = 105;
const int maxm = 15;
char mp[maxn][maxm];
//状态为：当前是第几行，本行状态，上行的状态下最多能放多少个
int n,m,imp[maxn],f[maxn][100][100];
VI st[maxn],cnt[maxn];

inline int bit(int i,int pos) {
    return (bool)(i & (1 << pos));
}

inline bool check(int st,int nst) {
    if(bit(st,0) && bit(st,1)) return false;
    for(int i = 2;i < m;i++) if(bit(st,i)) 
        if(bit(st,i - 1) || bit(st,i - 2)) return false;
    return (nst | st) == nst;
}

inline bool ok(int st1,int st2) {
    return !(st1 & st2);
}

int solve() {
    int ans = 0;
    for(int i = 0;i < st[0].size();i++) {
        f[0][i][0] = cnt[0][i];
        ans = max(ans,cnt[0][i]);
    }
    if(n == 1) return ans;
    for(int i = 0;i < st[1].size();i++) {
        for(int j = 0;j < st[0].size();j++) if(ok(st[1][i],st[0][j])) {
            f[1][i][j] = max(f[1][i][j],f[0][j][0] + cnt[1][i]);
        }
    }
    for(int i = 1;i + 1 < n;i++) {
        for(int j = 0;j < st[i].size();j++) {
            for(int k = 0;k < st[i - 1].size();k++) if(ok(st[i][j],st[i - 1][k])) {
                for(int l = 0;l < st[i + 1].size();l++) if(ok(st[i][j],st[i + 1][l]) && ok(st[i - 1][k],st[i + 1][l])) {
                    f[i + 1][l][j] = max(f[i + 1][l][j],f[i][j][k] + cnt[i + 1][l]);
                    if(i + 1 == n - 1) ans = max(ans,f[i + 1][l][j]);
                }
            }
        }
    }
    return ans;
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        memset(imp,0,sizeof(imp));
        memset(f,0,sizeof(f));
        for(int i = 0;i < n;i++) scanf("%s",mp[i]);
        for(int i = 0;i < n;i++) 
            for(int j = 0;j < m;j++) if(mp[i][j] == 'P') imp[i] |= (1 << j);
        for(int i = 0;i < n;i++) {
            st[i].clear(); cnt[i].clear();
            for(int j = 0;j < (1 << m);j++) if(check(j,imp[i])) {
                int cc = 0;
                for(int k = 0;k < m;k++) if(bit(j,k)) cc++;
                st[i].PB(j); cnt[i].PB(cc);
            }
        }
        printf("%d\n",solve());
    }
    return 0;
}
