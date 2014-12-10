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

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-5;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 55;
double a[maxn];
int n;
bool vis[maxn];
vector<double> vi;

#define QIAN 0
#define HOU 1

int main() {
    int T; cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        sort(a + 1,a + 1 + n);
        a[n + 1] = DINF;
        for(int i = 2;i <= n;i++) vi.PB(a[i] - a[i - 1]);
        for(int i = 2;i <= n;i++) vi.PB((a[i] - a[i - 1]) / 2.0);
        vi.PB(1);
        sort(vi.begin(),vi.end());
        int m = vi.size() - 1;
        for(int i = m;i >= 0;i--) {
            double nowval = vi[i];
            bool ok = true,prev = QIAN;
            memset(vis,0,sizeof(vis));
            for(int j = 2;j <= n;j++) {
                if(!vis[j]) {
                    if(prev == QIAN) {
                        if(a[j] - nowval + eps >= a[j - 1]) {
                            prev = QIAN;
                        }
                        else {
                            if(a[j] + nowval - eps <= a[j + 1]) {
                                if(fabs(a[j] + nowval - a[j + 1]) < eps)
                                    vis[j + 1] = true;
                                prev = HOU;
                            }
                            else {
                                ok = false;
                                break;
                            }
                        }
                    }
                    else {
                        if(a[j] - nowval - nowval + eps >= a[j - 1]) {
                            prev = QIAN;
                        }
                        else {
                            if(a[j] + nowval - eps <= a[j + 1]) {
                                prev = HOU;
                                if(fabs(a[j] + nowval - a[j + 1]) < eps)
                                    vis[j + 1] = true;
                            }
                            else {
                                ok = false;
                                break;
                            }
                        }
                    }
                    vis[j] = true;
                }
                else {
                    prev = QIAN;
                }
            }
            if(ok) {
                printf("%.3f\n",nowval);
                break;
            }
        }
    }
    return 0;
}
