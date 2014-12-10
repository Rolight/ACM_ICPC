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
char str[maxn];
bool vis[maxn][maxn];
int f[maxn];

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%s",str);
        int len = strlen(str);
        memset(vis,0,sizeof(vis));
        //枚举中点
        for(int i = 0;i < len;i++) {
            int l = i, r = i;
            while(l >= 0 && r < len && str[l] == str[r]) {
                vis[l][r] = true;
                l--; r++;
            }
            l = i; r = i + 1;
            while(l >= 0 && r < len && str[l] == str[r]) {
                vis[l][r] = true;
                l--; r++;
            }
            f[i] = INF;
        }
        f[0] = 1;
        for(int i = 1;i < len;i++) {
            for(int j = 0;j <= i;j++) if(vis[j][i]) {
                f[i] = min(f[i], f[j - 1] + 1);
            }
        }
        printf("%d\n",f[len - 1]);
    }
    return 0;
}
