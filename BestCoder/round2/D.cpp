#include <cstdio>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
#include <ctime>
#include <set>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <string>
#include <list>

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

void setfile() {
    freopen(INPUT_FILE,"r",stdin);
    freopen(OUTPUT_FILE,"w",stdout);
}

const int maxn = 2097152 + 2;
const int maxlen = 8;
const int maxtlen = 1000000 + 5;
const int maxnode = maxn * maxlen;
const int sigma_size = 8;
void display(int);

struct AC_automation {
    int sz;
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int fail[maxnode];
    bool vis[maxnode];

    void init() {
        memset(ch[0],0,sizeof(ch[0]));
        fail[0] = val[0] = 0;
        sz = 1;
    }

    inline int idx(char c) {
        return c - 'A';
    }

    void flagclear() {
        memset(vis,0,sizeof(vis));
    }

    void insert(char *str,int wval) {
        int len = strlen(str),u = 0;
        for(int i = 0;i < len;i++) {
            int c = idx(str[i]);
            if(ch[u][c] == 0) {
                memset(ch[sz],0,sizeof(ch[sz]));
                fail[sz] = val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = wval;
    }

    int getans() {
        queue<int> q;
        int u;
        q.push(0);
        while(!q.empty()) {
            u = q.front(); q.pop();
            for(int i = 0;i < sigma_size;i++) {
                int v = ch[u][i];
                printf("now v is %d vis is %d\n",v,vis[v]);
                if(!vis[v]) {
                    u = v; break;
                }
                q.push(v);
            }
        }
        return val[u];
    }

    void construct() {
        queue<int> q;
        int u = 0;
        for(int i = 0;i < sigma_size;i++) if(ch[u][i]) {
            fail[ ch[u][i] ] = 0;
            q.push(ch[u][i]);
        }
        while(!q.empty()) {
            u = q.front(); q.pop();
            for(int i = 0;i < sigma_size;i++) {
                int &v = ch[u][i];
                if(v) {
                    q.push(v);
                    fail[v] = ch[ fail[u] ][i];
                } else {
                    v = ch[ fail[u] ][i];
                }
            }
        }
    }

    void query(char *str) {
        int len = strlen(str),u = 0;
        int ans = 0;
        for(int i = 0;i < len;i++) {
            int c = idx(str[i]);
            u = ch[u][c];
            int v = u;
            while(v) {
                vis[v] = true;
                printf("vis[%d] = %d\n",v,vis[v]);
                v = fail[v];
            }
        }
    }

};

char T[maxtlen];
int dict[maxn],dcnt;
char nowstr[10];
AC_automation ac;

void dfs(int pos,int val) {
    if(pos == 8) return;
    if(pos == 7) {
        nowstr[pos] = 0;
        ac.insert(nowstr,val);
        dict[dcnt++] = val;
    }
    for(int i = 'A';i <= 'H';i++) {
        nowstr[pos] = i;
        dfs(pos + 1,val * 10 + i - 'A' + 1);
    }
}

void display(int val) {
    stack<char> ss;
    while(val) {
        int now = val % 10;
        ss.push('A' + now - 1);
        val /= 10;
    }
    while(!ss.empty()) {
        putchar(ss.top());
        ss.pop();
    }
    puts("");
}

int main() {
    int kase; scanf("%d",&kase);
    ac.init();
    dfs(0,0);
    ac.construct();
    getchar();
    while(kase--) {
        gets(T);
        ac.flagclear();
        ac.query(T);
        int ans = ac.getans();
        display(ans);
    }
    return 0;
}
