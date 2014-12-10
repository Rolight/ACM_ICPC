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
const int maxn = 500000 + 5;
const int maxnode = 510000;
map<string,int> tb;
int f[maxn],dcnt[maxn];
int ch[maxnode][26],sz,id[maxnode * 10],cnt;
char a[16],b[16];

int idx(char *s) {
    int len = strlen(s),u = 0;
    for(int i = 0;i < len;i++) {
        int now = s[i] - 'a';
        if(ch[u][now] == 0) {
            ch[u][now] = sz++;
        }
        u = ch[u][now];
    }
    if(id[u] == 0) {
        id[u] = ++cnt;
    }
    return id[u];
}

int findp(int x) {
    return x == f[x] ? x : f[x] = findp(f[x]);
}

int main() {
    sz = 1;
    for(int i = 1;i <= maxn;i++) f[i] = i;
    while(scanf("%s%s",a,b) != EOF) {
        int ida = idx(a),idb = idx(b);
        int pa = findp(ida),pb = findp(idb);
        if(pa != pb) f[pa] = pb;
        dcnt[ida]++; dcnt[idb]++;
    }
    int one = 0,rone = 0,root = 0;
    bool bad = false;
    for(int i = 1;i <= cnt;i++) {
        if(dcnt[i] % 2) one++;
        if(findp(i) == i) root++;
    }
    if(!(one == 0 || one == 2)) bad = true;
    if(root > 1) bad = true;
    if(bad) puts("Impossible");
    else puts("Possible");
    return 0;
}
