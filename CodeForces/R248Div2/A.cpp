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
int f[maxn * 200],n,a[maxn];

int main() {
    int sum = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = sum;j >= a[i];j--) {
            f[j] = max(f[j],f[j - a[i]] + a[i]);
        }
    }
    int mid = sum / 2;
    if(f[mid] == mid) puts("YES");
    else puts("NO");
    return 0;
}
