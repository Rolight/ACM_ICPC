/*
ID: flsnnx1
LANG: C++
TASK: zerosum
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
const int maxn = 15;
vector<int> tmp;
int n;
char path[maxn];

int getval() {
    stringstream buff;
    buff << "1";
    for(int i = 2;i <= n;i++) {
        if(path[i] != ' ') buff << path[i] ;
        buff << i;
    }
    int ans = 0,tmp;
    while(buff >> tmp) {
        ans += tmp;
    }
    return ans;
}

void dfs(int now) {
    if(now == n + 1 && !getval()) {
        printf("1");
        for(int i = 2;i <= n;i++) {
            printf("%c%d",path[i],i);
        }
        puts("");
        return;
    }
    if(now == n + 1) return;
    path[now] = ' '; dfs(now+1);
    path[now] = '+'; dfs(now+1);
    path[now] = '-'; dfs(now+1);
}

int main() {
    freopen("zerosum.in","r",stdin);
    freopen("zerosum.out","w",stdout);
    scanf("%d",&n);
    dfs(2);
    return 0;
}

