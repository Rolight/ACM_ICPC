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
const int maxn = 3005;
const int C = 12345, p = 67890, q = 1e9 + 7;
char str1[maxn], str2[maxn];
VI ch[maxn], hash[maxn];
int fa[maxn];

int dfs(int now) {
    int m = ch[now].size();
    if(m == 0) return C;
    for(int i = 0;i < m;i++) {
        hash[now].PB(dfs(ch[now][i]));
    }
    sort(hash[now].begin(),hash[now].end());
    int ret = C;
    for(int i = 0;i < m;i++) {
        ret = (ret * p) ^ hash[now][i] % q;
    }
    return ret;
}

int gethash(char *str) {
    memset(fa,0,sizeof(fa));
    int len = strlen(str), u = 0, sz = 1;
    for(int i = 0;i < len;i++) {
        ch[i].clear(); hash[i].clear();
    }
    for(int i = 0;i < len;i++) {
        if(str[i] == '0') {
            ch[u].PB(sz);
            fa[sz] = u;
            u = sz++;
        }
        else {
            u = fa[u];
        }
    }
    return dfs(0);
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%s%s",str1,str2);
        if(gethash(str1) == gethash(str2)) {
            puts("same");
        }
        else puts("different");
    }
    return 0;
}
