#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 1005;

struct Mouse {
    int x,y;
    double p,t;
    bool operator < (const Mouse &mm) const {
        return t < mm.t;
    }
};

#define sq(x) ((x)*(x))

double dis(Mouse a,Mouse b) {
    return sq(a.x - b.x) + sq(b.y - a.y);
}

Mouse m[maxn];
double f[maxn];
int N,V;

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&V);
        for(int i = 1;i <= N;i++) {
            scanf("%d%d%lf%lf",&m[i].x,&m[i].y,&m[i].t,&m[i].p);
            m[i].t += 1;
        }
        sort(m + 1,m + 1 + N);
        memset(f,0,sizeof(f));
        f[0] = 0;
        double ans = 0;
        for(int i = 1;i <= N;i++) {
            double ret = 0;
            for(int j = i - 1;j > 0;j--) {
                if(sqrt(dis(m[i],m[j])) / V - (m[i].t - m[j].t) <= 1e-8) {
                    ret = max(ret,f[j]);
                }
            }
            f[i] = ret + (m[i].p);
            ans = max(ans,f[i]);
        }
        printf("%.6f\n",ans);
    }
    return 0;
}
