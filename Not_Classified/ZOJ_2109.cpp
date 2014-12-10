#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1005;

struct obj {
    double c,v,w;
    bool operator < (const obj &x) const {
        return w > x.w;
    }
};

obj o[maxn];

int main() {
    int n,m;
    while(scanf("%d%d",&m,&n),~n) {
        double ans = 0;
        for(int i = 0;i < n;i++) {
            scanf("%lf%lf",&o[i].v,&o[i].c);
            o[i].w = o[i].v / o[i].c;
        }
        sort(o,o + n);
        for(int i = 0;i < n;i++) {
            if(m >= o[i].c) {
                ans += o[i].v;
                m -= o[i].c;
            }
            else {
                ans += (m / o[i].c) * o[i].v;
                break;
            }
        }
        printf("%.3f\n",ans);
    }
    return 0;
}

