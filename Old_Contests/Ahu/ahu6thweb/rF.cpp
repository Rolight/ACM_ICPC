#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100001;
int n,m,v[maxn],sum;

bool ok(int t) {
    int cc = n - m,i = 0;
    while(i < n && cc) {
        int cs = v[i]; i++;
        while(cs + v[i] <= t && i < n && cc) {
            cs += v[i++]; cc--;
        }
    }
    return cc == 0;
}

int main() {
    while(~scanf("%d%d",&n,&m)) {
        int maxv = 0;
        sum = 0;
        for(int i = 0;i < n;i++) {
            scanf("%d",&v[i]),sum += v[i];
            maxv = max(v[i],maxv);
        }
        int l = maxv,r = sum,mid;
        while(l < r) {
            mid = (l + r) / 2;
            if(ok(mid)) {
                r = mid;
            } else l = mid + 1;
        }
        printf("%d\n",l);
    }
    return 0;
}
