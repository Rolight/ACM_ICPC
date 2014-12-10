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
const int maxn = 100000 + 5;
int N,K,dis[maxn << 1];

void solve() {
    memset(dis,-1,sizeof(dis));
    queue<int> q;
    q.push(N); dis[N] = 0;
    while(!q.empty()) {
        int now = q.front(), nds = dis[now] + 1;
        q.pop();
        if(now == K) break;
        if(now - 1 >= 0 && dis[now - 1] == -1) {
            q.push(now - 1); dis[now - 1] = nds;
        }
        if(now * 2 <= 2 * K && dis[now * 2] == -1) {
            q.push(now * 2); dis[now * 2] = nds;
        } 
        if(now + 1 <= K && dis[now + 1] == -1) {
            q.push(now + 1); dis[now + 1] = nds;
        }
    }
    printf("%d\n",dis[K]);
}

int main() {
    while(scanf("%d%d",&N,&K) != EOF) {
        solve();
    }
    return 0;
}
