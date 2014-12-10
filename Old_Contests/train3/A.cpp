#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;
const int maxn = 1005;
int n,m;
int p[maxn];

void init() {
    for(int i = 1;i <= n;i++) p[i] = i;
}

int findset(int i) {
    return p[i] == i ? i : p[i] = findset(p[i]);
}

int main() {
    while(scanf("%d%d",&n,&m),n) {
        int ans = 0;
        init();
        for(int i = 0;i < m;i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            int x = findset(a),y = findset(b);
            p[x] = y;
        }
        for(int i = 1;i <= n;i++) {
            if(i == findset(i)) ans++;
        }
        printf("%d\n",ans - 1);
    }
    return 0;
}
