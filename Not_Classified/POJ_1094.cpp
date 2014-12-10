#include <cstdio>
#include <cstring>
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
const int maxn = 30;

int N,M,fa[maxn],incnt[maxn];
bool vis[maxn],sorted[maxn];
int mp[maxn][maxn];

int toposort(vector<int> &ans) {
    int tmp[maxn];
    bool flag = true;
    ans.clear();
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= N;i++) tmp[i] = incnt[i];
    for(int k = 1;k <= N;k++) {
        int x,ncnt = 0;
        for(int i = 1;i <= N;i++) if(!vis[i] && tmp[i] == 0) {
            x = i; ncnt++;
        }
        if(ncnt > 1) flag = false; //就算不能判断出来，不能直接return，还要继续判断是否有环
        if(ncnt == 0) return -1;
        vis[x] = true;
        ans.push_back(x);
        for(int i = 1;i <= N;i++) if(!vis[i] && mp[x][i] == 1) {
            tmp[i]--;
        }
    }
    return flag;
}

int main() {
    while(scanf("%d%d",&N,&M),N) {
        vector<int> ans;
        memset(mp,-1,sizeof(mp));
        memset(incnt,0,sizeof(incnt));
        bool determined = false,inconsistency = false;
        int cnt = 1,kase;
        for(int i = 1;i <= M;i++) {
            char buf[10]; scanf("%s",buf);
            int a = buf[0] - 'A' + 1,b = buf[2] - 'A' + 1;
            if(inconsistency || determined) continue;
            if(mp[a][b] == -1) incnt[b]++;
            mp[a][b] = true;
            int ret = toposort(ans);
            if(ret == 1) determined = true,kase = i;
            if(ret == -1) inconsistency = true;
            if(inconsistency) {
                printf("Inconsistency found after %d relations.\n",i);
                continue;
            }
        }
        if(!inconsistency) {
            if(determined) {
                printf("Sorted sequence determined after %d relations: ",kase);
                for(int i = 0;i < ans.size();i++) printf("%c",ans[i] - 1 + 'A');
                puts(".");
            } else puts("Sorted sequence cannot be determined.");
        }
    }
    return 0;
}   
