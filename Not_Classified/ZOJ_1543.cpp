#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 105;
double v[maxn];

double combine(double a,double b) {
    return 2 * sqrt(a * b);
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        for(int i = 0;i < n;i++) scanf("%lf",&v[i]);
        sort(v,v + n);
        for(int i = n - 2;i >= 0;i--) {
            v[i] = combine(v[i],v[i + 1]);
        }
        printf("%.3f\n",v[0]);
    }
    return 0;
}

