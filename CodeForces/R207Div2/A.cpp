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
int a[maxn];

int main() {
    int n,ans = 0,x,y;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    scanf("%d%d",&x,&y);
    for(int i = 0;i <= n;i++) {
        a[i] += a[i - 1];
    }
    for(int i = 1;i <= n;i++) {
        int aa = a[i - 1],bb = a[n] - a[i - 1];
        if(aa >= x && aa <= y && bb >= x && bb <= y) {
            ans = i; break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
