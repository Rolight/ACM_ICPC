#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <sstream>
#include <numeric>
#include <fstream>
#include <functional>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 500;

struct Point {
    double x,y;
    Point(double x = 0,double y = 0): x(x), y(y) {}
    bool operator < (const Point &p) const {
        if(fabs(p.x - x) < eps) return y < p.y;
        return x < p.x;
    }
};

double sq(double x) { return x * x; }

int n;
double f[maxn][maxn];
Point p[maxn];
double dist[maxn][maxn];

int main() {
    while(scanf("%d",&n) != EOF) {
        for(int i = 1;i <= n;i++) {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                f[i][j] = DINF;
            }
        }
        sort(p + 1, p + 1 + n);
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) if(i != j) {
                dist[i][j] = sqrt(sq(p[i].x - p[j].x) + sq(p[i].y - p[j].y));
            }
        }
        double ans = DINF;
        f[1][1] = 0;
        for(int i = 1;i <= n;i++) {
            int m = i == 1 ? 1 : i - 1;
            for(int j = 1;j <= m;j++) {
                f[i + 1][i] = min(f[i + 1][i], f[i][j] + dist[j][i + 1]);
                f[i + 1][j] = min(f[i + 1][j], f[i][j] + dist[i][i + 1]);
                if(i == n) {
                    ans = min(ans, f[i][j] + dist[j][n]);
                }
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
