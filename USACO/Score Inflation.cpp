/*
ID: flsnnx1
LANG: C++
TASK: inflate
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
const int maxn = 10000 + 5;
int C[maxn],W[maxn],n,V;
int f[maxn];

int main() {
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);
    cin >> V >> n;
    for(int i = 1;i <= n;i++) cin >> W[i] >> C[i];
    for(int i = 1;i <= n;i++) {
        for(int j = C[i];j <= V;j++) {
            f[j] = max(f[j],f[j - C[i]] + W[i]);
        }
    }
    printf("%d\n",f[V]);
    return 0;
}
