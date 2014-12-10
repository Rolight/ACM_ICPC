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
const int maxn = 40000 + 5;
int n,m;
int a[maxn];
map<int,int> mp;

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        mp.clear();
        int posm = 1;
        for(int i = 1;i <= n;i++) {
            scanf("%d",&a[i]);
            if(a[i] == m) posm = i;
            if(a[i] < m) a[i] = -1;
            if(a[i] > m) a[i] = 1;
        }
        LL ans = 0;
        int nowsum = 0;
        for(int i = posm - 1;i >= 1;i--) {
            nowsum += a[i];
            mp[nowsum]++;
        }
        nowsum = 0;
        for(int i = posm + 1;i <= n;i++) {
            nowsum += a[i];
            ans += mp[-nowsum];
            if(nowsum == 0) ans++;
        }
        cout << ans + 1 + mp[0] << endl;
    }
    return 0;
}
