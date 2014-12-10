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
const int maxn = 5, maxm = 9;
const int n = 4,m = 8;
const int maxq = 65536;
int mp[maxn][maxm];

struct Node {
    int data[maxn][maxm],dis;
    Node(int val[maxn][maxm],int dis):dis(dis) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                data[i][j] = val[i][j];
            }
        }
    }

    Node() {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j < m;j++) {
                data[i][j] = i * 10 + j;
            }
            data[i][8] = 0;
        }
    }

    bool operator == (const Node &node) const {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(node.data[i][j] != data[i][j]) return false;
            }
        }
        return true;
    }
};

const Node tar;

Node q[maxq], val[maxq];
int head[maxq], nxt[maxq], sz;
int qs,qe;

int gethash(const Node &now) {
    int ret = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            ret = (ret << 6) + now.data[i][j];
        }
    }
    return ret & (maxq - 1);
}

bool exist(const Node &now) {
    int hc = gethash(now);
    for(int i = head[hc];~i;i = nxt[i]) {
        if(val[i] == now) return true;
    }
    val[sz] = now; nxt[sz] = head[hc];
    head[hc] = sz++;
    return false;
}

void expand(int x,int y,Node now) {
    bool found = false;
    int val = now.data[x][y - 1] + 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) if(now.data[i][j] == val) {
            now.data[i][j] = 0;
            now.data[x][y] = val;
            found = true;
            break;
        }
    }
    if(!found) return;
    if(!exist(now)) {
        now.dis++;
        q[qe % maxq] = now;
        qe++;
    }
}

int solve() {
    qs = qe = sz = 0;
    q[qe++] = Node(mp,0);
    memset(head,-1,sizeof(head));
    while(qs < qe) {
        Node now = q[qs % maxq]; qs++;
        if(now == tar) return now.dis;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) if(now.data[i][j] == 0) {
                expand(i,j,now);
            }
        }
    }
    return -1;
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        for(int i = 1;i <= n;i++) {
            for(int j = 2;j <= m;j++) {
                scanf("%d",&mp[i][j]);
                if(mp[i][j] % 10 == 1) {
                    mp[mp[i][j] / 10][1] = mp[i][j];
                    mp[i][j] = 0;
                }
            }
        }
        printf("%d\n",solve());
    }
    return 0;
}
