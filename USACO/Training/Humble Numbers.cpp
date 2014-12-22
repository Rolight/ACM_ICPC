/*
ID: flsnnx1
LANG: C++
TASK: humble
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100000 + 5;
typedef long long LL;
int n,k;
LL num[maxn];
int pri[maxn];
int cnt[maxn];

void setfile() {
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
}

int main() {
    setfile();
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> pri[i];
    for(int i = 1;i <= n;i++) cnt[i] = 1;
    num[1] = 1;
    for(int i = 2;i <= k + 2;i++) {
        LL minval = 1e17;
        for(int j = 1;j <= n;j++) {
            int nowval = num[cnt[j]] * pri[j];
            if(nowval < minval) {
                minval = nowval;
            }
        }
        for(int j = 1;j <= n;j++) {
            if(num[cnt[j]] * pri[j] == minval) cnt[j]++;
        }
        num[i] = minval;
    }
    cout << num[k + 1] << endl;
    return 0;
}

