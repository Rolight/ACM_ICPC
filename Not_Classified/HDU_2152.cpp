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

using namespace std;
const int maxn = 105;
const int maxv = 105;
int c1[maxv],c2[maxv];
int l[maxn],r[maxn];
int n,m;

int main() {
    while(scanf("%d%d",&n,&m) == 2) {
        int sum  = 0;
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i = 1;i <= n;i++) {
            scanf("%d%d",&l[i],&r[i]);
        }
        for(int i = l[1];i <= r[1];i++) c1[i] = 1;
        for(int i = 2;i <= n;i++) {
            for(int j = l[i];j <= r[i];j++) {
                for(int k = 0;k + j <= m;k++) {
                    c2[k + j] += c1[k];
                }
            }
            memcpy(c1,c2,sizeof(c1));
            memset(c2,0,sizeof(c2));
        }
        printf("%d\n",c1[m]);
    }
}
