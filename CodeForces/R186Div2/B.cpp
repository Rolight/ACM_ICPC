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
char buf[maxn];
int len,m,f[maxn];

int lowbit(int x) {
    return x & -x;
}

void addv(int i,int v) {
    while(i <= len) {
        f[i] += v;
        i += lowbit(i);
    }
}

int getsum(int i) {
    int ret = 0;
    while(i > 0) {
        ret += f[i];
        i -= lowbit(i);
    }
    return ret;
}

int main() {
    scanf("%s",buf + 1);
    len = strlen(buf + 1);
    for(int i = 1;i < len;i++) {
        if(buf[i] == buf[i + 1]) {
            addv(i,1);
        }
    }
    scanf("%d",&m);
    for(int i = 0;i < m;i++) {
        int a,b; scanf("%d%d",&a,&b);
        printf("%d\n",getsum(b - 1) - getsum(a - 1));
    }
    return 0;
}
