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
int k,m,cnt;
vector<int> gg;
set<string> st;
char ans[1024];

void printnum() {
    int len = strlen(ans);
    if(len > 8) return;
    for(int i = 1;i <= 8 - len;i++) {
        putchar('0');
    }
    for(int i = 0;i < len;i++) printf("%c",ans[i]);
    puts("");
    cnt++;
}

int main() {
    cin >> k >> m;
    for(int i = 0;cnt < m;i++) {
        memset(ans,0,sizeof(ans));
        sprintf(ans,"%d%d",i,abs(k - i));
        string tmp(ans);
        if(!st.count(tmp)) {
            st.insert(tmp);
            printnum();
        }
        if(i >= 1e6) break;
    }
    printf("cnt is %d\n",cnt);
    return 0;
}
