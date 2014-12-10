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
const int maxn = 300;
const int maxk = 50;
int p,k,s;
string str,buf,dict[10];
int f[maxn][maxk],cc[maxn][maxn];

int calc(int l,int r) {
    l--; r--;
    int ret = 0;
    for(int i = l;i <= r;i++) {
        for(int j = 0;j < s;j++) {
            int nz = dict[j].size(), pos = i;
            bool ok = true;
            if(pos + nz - 1 > r) continue;
            for(int k = 0;k < nz;k++) {
                if(str[pos + k] != dict[j][k]) {
                    ok = false; break;
                }
            }
            if(ok) {
                ret++; break;
            }
        }
    }
    return ret;
}

void solve() {
    memset(f,0,sizeof(f));
    int n = str.size();
    if(k > n) {
        puts("0"); return;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = i;j <= n;j++) {
            cc[i][j] = calc(i,j);
        }
    }
    for(int i = 1;i <= n;i++) f[i][1] = cc[1][i];
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            for(int l = j + 1;l <= i;l++) {
                f[i][j] = max(f[i][j],f[l - 1][j - 1] + cc[l][i]);
            }
        }
    }
    printf("%d\n",f[n][k]);
}

int main() {
    int T; cin >> T;
    while(T--) { 
        str = "";
        cin >> p >> k;
        for(int i = 0;i < p;i++) {
            cin >> buf;
            str += buf;
        }
        cin >> s;
        for(int i = 0;i < s;i++) {
            cin >> dict[i];
        }
        solve();
    }
    return 0;
}

