#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<double,double> pdd;


bool ok(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4) {
    double A = y4 - y3,B = x3 - x4,C = x4 * y3 - x3 * y4;
    double D1 = A * x1 + B * y1 + C,D2 = A * x2 + B * y2 + C;
    if((D1 < 0 && D2 < 0) || (D1 > 0 && D2 > 0)) return false;
    else return true;
}

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        int n; scanf("%d",&n);
        double sx,sy,tx,ty,x0,y0,x1,y1;
        int ans = 0;
        scanf("%lf%lf%lf%lf",&sx,&sy,&tx,&ty);
        for(int i = 1;i <= n;i++) {
            scanf("%lf%lf%lf%lf",&x0,&y0,&x1,&y1);
            if(ok(sx,sy,tx,ty,x0,y0,x1,y1)) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

