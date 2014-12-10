#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
 
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
double F;
int D;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    while(scanf("%lf%d", &F, &D) != EOF) {
        int ansu = 0, ansd = 1;
        double mineps = 1e9;
        for(int i = 1; i <= D; i++) {
            int nowu = i * F + 0.5, nowd = i;
            if(fabs((double)nowu / nowd - F) < mineps) {
                mineps = fabs((double)nowu / nowd -F);
                ansu = nowu; ansd = nowd;
            }
        }
        int lc = gcd(ansu, ansd);
        ansu /= lc; ansd /= lc;
        printf("%d %d\n", ansu, ansd);
    }
    return 0;
}
