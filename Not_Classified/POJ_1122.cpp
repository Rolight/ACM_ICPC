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
const int maxn = 25;
int d[maxn],vis[maxn],e[maxn][maxn];
int n,str;

void dijkstra() {
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++) d[i] = -1;
    d[str] = 0;
    for(int k = 1;k <= n;k++) {
        int x,minv = INT_MAX;
        for(int i = 1;i <= n;i++) if(!vis[i] && d[i] != -1) {
            if(d[i] < minv) minv = d[x = i];
        }
        vis[x] = true;
        for(int i = 1;i <= n;i++) if(!vis[i] && e[x][i] != -1) {
            if(d[i] == -1) d[i] = d[x] + e[x][i];
            else d[i] = min(d[i],d[x] + e[x][i]);
        }
    }
}

bool cmp(int a,int b) {
    return d[a] < d[b];
}

char buf[1024];
vector<int> r;

void print_path(int now) {
    printf("    %d",now);
    if(now == str) return;
    for(int i = 1;i <= n;i++) {
        if(e[i][now] != -1 && i != now && d[now] == d[i] + e[i][now]) {
            print_path(i); return;
        }
    }

}

int main() {
    bool first = true;
    while(scanf("%d",&n) != EOF) {
        if(first) first = false;
        else puts("");
        r.clear();
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                scanf("%d",&e[j][i]);
            }
        }
        scanf("%d",&str);
        dijkstra();
        puts("Org   Dest    Time    Path");
        gets(buf);
        int len = strlen(buf),pos = 0;
        while(pos < len && buf[pos] == ' ') pos++;
        while(pos < len) {
            int tmp;
            sscanf(buf + pos,"%d",&tmp);
            r.push_back(tmp);
            while(pos < len && buf[pos] != ' ') pos++;
            while(pos < len && buf[pos] == ' ') pos++;
        }
        sort(r.begin(),r.end(),cmp);
        for(int i = 0;i < r.size();i++) {
            int now = r[i];
            printf("%d  %d  %d",now,str,d[now]);
            print_path(now);
            putchar('\n');
        }
    }
    return 0;
}
