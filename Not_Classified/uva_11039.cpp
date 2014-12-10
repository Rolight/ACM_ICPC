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
const int maxn = 5e5 + 10;
int num[maxn], n;

bool cmp(int a,int b) {
    return abs(a) < abs(b);
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i = 0;i < n;i++) {
            scanf("%d",&num[i]);
        }
        sort(num, num + n, cmp);
        int ans = 0, last = -num[0];
        for(int i = 0;i < n;i++) {
            if(last < 0 && num[i] > 0) {
                last = 1; ans++;
            }
            else if(last > 0 && num[i] < 0) {
                last = -1; ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
