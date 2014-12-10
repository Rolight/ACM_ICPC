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
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int n, pw[maxn], k[maxn], cnt[maxn];

int main() {
    int T; scanf("%d",&T);
    int kase = 1;
    while(T--) {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++) scanf("%d",&k[i]);
        for(int i = 1;i <= n;i++) scanf("%d",&pw[i]);
        sort(k + 1,k + 1 + n);
        sort(pw + 1, pw + 1 + n);
        LL ans = 1, cnt = 0;
        for(int i = 1, j = 1;i <= n;i++) {
            while(k[j] <= pw[i] && j <= n) {
                cnt++; j++;
            }
            ans = (ans * cnt) % mod;
            if(cnt > 0) cnt--;
        }
        printf("Case #%d: ",kase++);
        cout << ans << endl;
    }
    return 0;
}
