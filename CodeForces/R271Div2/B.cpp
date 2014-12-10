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
const int maxn = 505;
vector<int> pnum;
bool vis[100008 + 100];
int mat[maxn][maxn];

void getprime() {
    for(int i = 2;i <= 100008;i++) {
        if(!vis[i]) {
            pnum.push_back(i);
            for(int j = i + i;j <= 100008;j += i) {
                vis[j] = true;
            }
        }
    }
}

int gettimes(int n) {
    if(n == 1) return 1;
    int l = 0,r = pnum.size() - 1;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(pnum[mid] < n) l = mid + 1;
        else r = mid;
    }
    int ret =  pnum[l] - n;
    return ret;
}

int main() {
    getprime();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> mat[i][j];
        }
    }
    int ans = 2100000000;
    for(int i = 1;i <= n;i++) {
        int sum = 0;
        for(int j = 1;j <= m;j++) {
            sum += gettimes(mat[i][j]);
        }
        ans = min(sum,ans);
    }
    for(int j = 1;j <= m;j++) {
        int sum = 0;
        for(int i = 1;i <= n;i++) {
            sum += gettimes(mat[i][j]);
        }
        ans = min(sum,ans);
    }
    cout << ans << endl;
    return 0;
}
