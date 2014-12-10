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
const int maxn = 100;
int n,maxv,a[maxn];
int l[maxn],r[maxn];

int main() {
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> l[i] >> r[i];
    for(int i = 2;i <= n;i++) for(int j = l[i];j < r[i];j++) a[j]++;
    int ans = 0;
    for(int i = l[1];i < r[1];i++) if(a[i] == 0) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}
