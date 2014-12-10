#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 1005;

bool vis[maxn];

struct Segment {
    double l,r;
    bool operator < (const Segment &x) const {
        if(r == x.r) return l < x.l;
        return r < x.r;
    }
    Segment(double l = 0,double r = 0):l(l),r(r) {
    }
};

Segment seg[maxn];

int main() {
    int n,d,kase = 1;
    double px,py;
    while(~scanf("%d%d",&n,&d),n) {
        memset(vis,0,sizeof(vis));
        bool ok = true;
        for(int i = 0;i < n;i++) {
            scanf("%lf%lf",&px,&py);
            if(py > d) ok = false;
            if(ok) {
                double pl = px - sqrt(d * d - py * py);
                double pr = px + sqrt(d * d - py * py);
                seg[i] = Segment(pl,pr);
            }
        }
        sort(seg,seg + n);
        double nowr = -1e100;
        printf("Case %d: ",kase++);
        if(!ok) puts("-1");
        else {
            int ans = 0;
            for(int i = 0;i < n;i++) {
                if(seg[i].l > nowr) {
                    nowr = seg[i].r;
                    ans++;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

