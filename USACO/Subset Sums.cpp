/*
ID: flsnnx1
LANG: C++
TASK: subset
*/

#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

const long long INF = INT_MAX * 10000LL; 
int N; 
long long note[1000][45];
bool vis[1000][45];

long long dfs(int num,int prev) {
    if(num == 0) return 1;
    if(vis[num][prev]) return note[num][prev];
    vis[num][prev] = true; 
    long long ret = 0; 
    int m = min(N,num); 
    for(int i = prev + 1;i <= m;i++) { 
        long long nret = dfs(num - i,i); 
        if(nret > 0) ret += nret;
    }
    if(ret == 0) return -INF;
    return note[num][prev] = ret;
}

int main() {
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    while(~scanf("%d",&N)) {
        memset(note,-1,sizeof(note));
        memset(vis,0,sizeof(vis));
        int sum = ((1 + N) * N) / 2;
        if(sum % 2 == 0) printf("%lld\n",dfs(sum / 2,0) / 2);
        else puts("0");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

