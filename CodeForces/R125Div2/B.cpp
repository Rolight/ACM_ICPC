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
const int maxn = 100;
const double eps = 1e-8;
double r[maxn],x[maxn],y[maxn];
int cnt = 0;


double dist(double x1,double x2,double y1,double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool ok(int i,int j) {
    double doo = dist(x[i],x[j],y[i],y[j]);
    if(doo  > fabs(r[i]-r[j])  && doo + 1e-6 < fabs(r[i]+r[j])) return false;
    return true;
}

int main() {
    for(int i = 0;i < 2;i++) {
        double a,b,c,d;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        r[cnt] = c; x[cnt] = a; y[cnt] = b; cnt++;
        r[cnt] = d; x[cnt] = a; y[cnt] = b; cnt++;
    }
    int ans = 0;
    for(int i = 0;i < cnt;i++)  {
        int sum = 0;
        for(int j = 0;j < cnt;j++) if(i != j) {
            sum += !ok(i,j);
        }
        if(sum == 0) {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
