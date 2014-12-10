#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;
char mp[maxn][maxn];

int main() {
    int n,m; scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            scanf(" %c",&mp[i][j]);
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(mp[i][j] == '.') {
                putchar(((i + j) % 2) ? 'W' : 'B');
            } else putchar('-');
        }
        putchar('\n');
    }
    return 0;
}
