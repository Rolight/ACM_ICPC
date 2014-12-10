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
const int maxn = 600;
const int hash_size = 65536;
const unsigned int p_col = 3131, p_row_pos = 1e9 + 7, p_row_val = 2e9 + 17;
char mat[maxn][maxn];
int n,m;
int head[hash_size], nxt[hash_size * 10];
unsigned int val[hash_size * 10], pos_x[hash_size * 10], pos_y[hash_size * 10], sz;
unsigned int pow_col[maxn], pow_row_pos[maxn], pow_row_val[maxn];
unsigned int hc_col[maxn][maxn], hc1[maxn][maxn], hc2[maxn], hc3[maxn];
int ans_x1, ans_x2, ans_y1, ans_y2;

void init() {
    pow_col[0] = pow_row_pos[0] = pow_row_val[0] = 1;
    for(int i = 1;i <= 500;i++) {
        pow_col[i] = p_col * pow_col[i - 1];
        pow_row_pos[i] = p_row_pos * pow_row_pos[i - 1];
        pow_row_val[i] = p_row_val * pow_row_val[i - 1];
    }
}

void init_hc() {
    for(int j = 1;j <= m;j++) {
        for(int i = 1;i <= n;i++) {
            hc_col[i][j] = hc_col[i - 1][j] * p_col + mat[i][j];
        }
    }
}

bool ask(int pos_hash,int val_hash,int x,int y) {
    pos_hash &= (hash_size - 1);
    for(int i = head[pos_hash]; ~i; i = nxt[i]) {
        if(val[i] == val_hash) {
            ans_x1 = pos_x[i];
            ans_y1 = pos_y[i];
            return true;
        }
    }
    pos_x[sz] = x; pos_y[sz] = y;
    val[sz] = val_hash;
    nxt[sz] = head[pos_hash];
    head[pos_hash] = sz++;
    return false;
}

bool ok(int len) {
    //初始化hash表
    memset(head,-1,sizeof(head));
    sz = 0;
    for(int j = 1;j <= m;j++) {
        for(int i = len;i <= n;i++) {
            hc1[i][j] = hc_col[i][j] - hc_col[i - len][j] * pow_col[len];
        }
    }

    for(int i = len;i <= n;i++) {
        hc2[0] = hc3[0] = 0;
        for(int j = 1;j <= m;j++) {
            hc2[j] = hc2[j - 1] * p_row_pos + hc1[i][j] % p_row_pos;
            hc3[j] = hc3[j - 1] * p_row_val + hc1[i][j] % p_row_val;
            if(j >= len) {
                int row_val_hash = hc3[j] - hc3[j - len] * pow_row_val[len],
                    row_pos_hash = hc2[j] - hc2[j - len] * pow_row_pos[len];
                if(ask(row_pos_hash,row_val_hash,i,j)) {
                    ans_x2 = i; ans_y2 = j; return true;
                }
            }
        }
    }
    return false;
}

void solve() {
    init_hc();
    //二分枚举边长
    int l = 1, r = min(n,m), ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(ok(mid)) {
            ans = mid; l = mid + 1;
        }
        else r = mid - 1;
    }
    printf("%d\n",ans);
    if(ans) printf("%d %d %d %d\n",ans_x1 - ans + 1,ans_y1 - ans + 1,ans_x2 - ans + 1,ans_y2 - ans + 1);
}

int main() {
    init();
    while(scanf("%d%d",&n,&m) != EOF) {
        for(int i = 1;i <= n;i++) scanf("%s",mat[i] + 1);
        solve();
    }
    return 0;
}
