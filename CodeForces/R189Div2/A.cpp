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
const int maxn = 15;
char buf[maxn];
char pat[3][10] = {
    "144","14","1"
};
int ll[3] = {3,2,1};
bool vis[maxn];
int cnt = 0,tmp;

void work(int posi,int k) {
    int sum = 0;
    for(int i = posi;i < posi + ll[k];i++) {
        if(i >= cnt) break;
        if(buf[i] == pat[k][i - posi]) sum++;
    }
    if(sum == ll[k]) {
        for(int i = posi;i < posi + ll[k];i++) {
            vis[i] = true;
        }
    }
}

int main() {
    while(scanf("%1d",&tmp) == 1) {
        buf[cnt++] = tmp + '0';
    }
    for(int i = 0;i < cnt;i++) {
        for(int j = 0;j < 3;j++) {
            work(i,j);
        }
    }
    bool ok = true;
    for(int i = 0;i < cnt;i++) {
        if(!vis[i]) ok = false;
    }
    if(ok) puts("YES");
    else puts("NO");
    return 0;
}
