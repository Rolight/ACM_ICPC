#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <climits>
#include <iostream>

using namespace std;

typedef long long LL;
const int maxn = 180;
double a[maxn][maxn];
int n;

int main() {
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(j > 1) putchar(' ');
            printf("%f",(a[i][j] + a[j][i]) / 2);
        }
        puts("");
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(j > 1) putchar(' ');
            printf("%f",(a[i][j] - a[j][i]) / 2);
        }
        puts("");
    }
    return 0;
}


