/*
ID: flsnnx1
LANG: C++
TASK: comehome
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;
const int maxn = 100;
const int INF = INT_MAX / 3;

inline int idx(char c) {
    if(c >= 'a' && c <= 'z') return c - 'a';
    else return c - 'A' + 26;
}

int dist[maxn][maxn];
int n = 52;

int main() {
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    int p; scanf("%d",&p);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            dist[i][j] = INF;
        }
    }
    for(int i = 0;i < p;i++) {
        char ca,cb;
        int a,b,c; scanf(" %c %c%d",&ca,&cb,&c);
        a = idx(ca); b = idx(cb);
        dist[a][b] = dist[b][a] = min(dist[a][b],c);
    }
    for(int k = 0;k < n;k++) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = INF;
    char ansc;
    for(int i = 26;i < 51;i++) {
        if(ans > dist[i][51]) {
            ans = dist[i][51];
            ansc = i - 26 + 'A';
        }
    }
    printf("%c %d\n",ansc,ans);
    return 0;
}
