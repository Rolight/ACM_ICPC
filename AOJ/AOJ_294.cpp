#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 350;
double C[maxn][maxn];

void init() {
    C[0][0] = 1;
    for(int i = 1;i <= maxn;i++) {
        for(int j = 1;j <= i;j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

double pow(double n,double k) {
    double ans = 1;
    while(k--) ans *= n;
    return ans;
}

int main() {
    int n; double k;
    init();
    while(~scanf("%d%lf",&n,&k)) {
        double ans = 0.0;
        for(int i = n;i <= 2 * n - 1;i++) {
            ans += C[i][n] * pow(k,n) * pow((1 - k),i - n);
        }
        printf("%.6f\n",ans);
    }   
    return 0;
}

