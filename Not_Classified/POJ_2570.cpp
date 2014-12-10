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
#include <stack>

using namespace std;

typedef long long LL;
const int maxn = 205;
int n,val[maxn][maxn];
bool e[maxn][maxn];
char buf[1024];

int getval(char *s) {
    int len = strlen(s),ret = 0;
    for(int i = 0;i < len;i++) {
        ret |= (1 << (s[i] - 'a'));
    }
    return ret;
}

void floyd() {
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            for(int k = 1;k <= n;k++) {
                val[j][k] |= val[j][i] & val[i][k];
            }
        }
    }
}

int main() {
    while(scanf("%d",&n),n) {
        memset(val,0,sizeof(val));
        int a,b;
        while(scanf("%d%d",&a,&b),a) {
            scanf("%s",buf);
            val[a][b] = getval(buf) ;
        }
        floyd();
        while(scanf("%d%d",&a,&b),a) {
            int cnt = 0;
            for(int i = 0;i < 26;i++) {
                if(val[a][b] & (1 << i)) {
                    cnt++;
                    putchar(i + 'a');
                }
            }
            if(cnt == 0) putchar('-');
            puts("");
        }
        puts("");
    }
    return 0;
}
