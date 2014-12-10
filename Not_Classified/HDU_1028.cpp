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
const int maxn = 125;
int c1[maxn],c2[maxn];

int main() {
    int n;
    while(scanf("%d",&n) == 1) {
        //用第一个多项式初始化
        for(int i = 0;i <= n;i++) {
            c1[i] = 1; c2[i] = 0;
        }
        //第i个多项式
        for(int i = 2;i <= n;i++) {
            //第i个多项式中的第j项
            for(int j = 0;j <= n;j += i) {
                //依次累加
                for(int k = 0;k + j <= n;k++) {
                    c2[k + j] += c1[k];
                }
            }
            memcpy(c1,c2,sizeof(c1));
            memset(c2,0,sizeof(c2));
        }
        printf("%d\n",c1[n]);
    }
    return 0;
}
