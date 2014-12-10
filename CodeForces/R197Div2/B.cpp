#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const int maxn = 100000 + 5;
int a[maxn],n,m;

int main() {
    scanf("%d%d",&n,&m);
    LL ans = 0;
    a[0] = 1;
    for(int i = 1;i <= m;i++) {
        scanf("%d",&a[i]);
        if(a[i] >= a[i - 1]) ans += a[i] - a[i - 1];
        else ans += n - (a[i - 1] - a[i]);
    }
    cout << ans << endl;
    return 0;
}
