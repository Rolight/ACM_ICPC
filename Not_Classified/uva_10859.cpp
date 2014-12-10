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
const int maxn = 1005;
VI e[maxn];
int n, m, vis[maxn][2], note[maxn][2];

int dfs(int i, int j, int f) {
    if(vis[i][j]) return note[i][j];
    vis[i][j] = 1;
    int &ret = note[i][j] = INF;
    //如果当前节点不放灯（父亲节点必须放灯）
    //总数为每一个节点的和 × 2000 + 1
    //需要对根节点进行特判
    int sum = f == -1 ? 0 : 1, mm = e[i].size();
    if(j) {
        for(int nx = 0;nx < mm;nx++) if(e[i][nx] != f) {
            sum += dfs(e[i][nx], 0, i);
        }
        ret = sum;
    }
    //当前节点放灯
    //总数为每一个节点的和*2000，然后如果父亲节点没有灯，再+1
    sum = j == 0 ? 1 : 0;
    for(int nx = 0;nx < mm;nx++) if(e[i][nx] != f) {
        sum += dfs(e[i][nx], 1, i);
    }
    sum += 2000;
    ret = min(sum,ret);
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        memset(vis,0,sizeof(vis));
        memset(note,0,sizeof(note));
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++) e[i].clear();
        for(int i = 0;i < m;i++) {
            int a,b; scanf("%d%d",&a,&b);
            e[a].PB(b); e[b].PB(a);
        }
        //当前节点，父节点有没有点亮，父节点编号
        //dfs(i,j,k)
        //枚举森林中的每一棵树
        int ans = 0;
        for(int i = 0;i < n;i++) if(!vis[i][0]) {
            ans += dfs(i,1,-1);
        }
        printf("%d %d %d\n",ans / 2000,m - ans % 2000,ans % 2000);
    }
    return 0;
}
