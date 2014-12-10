/*I have given up the treatment.-_-||*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
using namespace std;
#define mod 1000000
typedef long long LL;
#define N 11111
#define M 111111
LL t, n, m;
LL du[N];
struct node {
    LL u, v;
}edge[M];
int main()
{
   scanf("%lld", &t);
   int kase = 0;
   while(t--){
        if(kase++) puts("");
        scanf("%lld%lld", &n, &m);
        memset(du, 0, sizeof(du));
        for(LL i = 1; i <= m; i++) {
            scanf("%lld%lld", &edge[i].u, &edge[i].v);
            du[edge[i].u] ++;
            du[edge[i].v]++;
        }
        LL ans = 0;
        for(LL i = 1;i <= m; i++) {
            ans += du[edge[i].u];
            ans += du[edge[i].v];
        }
        printf("%lld\n", ans);
   }


    return 0;
}
