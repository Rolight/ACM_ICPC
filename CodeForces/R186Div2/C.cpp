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
const int maxn = 2000000 + 5;
int num[maxn],n,k;
LL sum[maxn];
bool cmp(int a,int b) {
    return a > b;
}

int main() {
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&num[i]);
    }
    sort(num + 1,num + 1 + n,cmp);
    for(int i = 1;i <= n;i++) {
        sum[i] = sum[i - 1] + num[i];
    }
    while((1 << (2 * k)) < n) k++;
    LL ans = 0;
    for(int i = 0;i <= k;i++) {
        int mm = ((1 << (2 * i)));
        ans += sum[mm];
    }
    cout << ans << endl;
    return 0;
}
