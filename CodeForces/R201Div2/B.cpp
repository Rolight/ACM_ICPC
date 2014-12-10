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
int arr[maxn],pos[maxn];

int main() {
    int n; scanf("%d",&n);
    int ans = 0;
    for(int i = 0;i < n;i++) {
        scanf("%d",&arr[i]);
        if(arr[i] == i) ans++;
        pos[arr[i]] = i;
    }
    bool ok = false;
    for(int i = 0;i < n;i++) if(arr[i] != i) {
        if(pos[i] == arr[i])  {
            ans += 2; ok = true; break;
        }
    }
    if(!ok && ans != n) ans++;
    printf("%d\n",ans);
    return 0;
}
