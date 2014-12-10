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
const int maxn = 500;
int c1[maxn],c2[maxn];

int main() {
    int n; 
    while(scanf("%d",&n),n) {
        for(int i = 0;i <= n;i++) {
            c1[i] = 1; c2[i] = 0;
        }
        for(int i = 2;i * i <= n;i++) {
            int nowval = i * i;
            for(int j = 0;j <= n;j += nowval) {
                for(int k = 0;k + j <= n;k++) {
                    c2[j + k] += c1[k];
                }
            }
            memcpy(c1,c2,sizeof(c1));
            memset(c2,0,sizeof(c2));
        }
        printf("%d\n",c1[n]);
    }
    return 0;
}
