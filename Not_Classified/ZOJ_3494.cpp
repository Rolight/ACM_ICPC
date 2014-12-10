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
const int maxnode = 1048576 + 5;
const int sigma_size = 2;
const int maxn = 700;

struct Solver {
    int ch[maxnode][sigma_size],val[maxnode];
    int sz,fail[maxnode];
    int lim[maxn],len;


    void acinit() {
        sz = 1; memset(ch[0],sizeof(ch[0]));
    }

    inline int idx(char c) {
        return c - '0';
    }

    void insert(char *str) {
        int len = strlen(str), u = 0;
        for(int i = 0;i < len;i++) {
            int c = idx(str[i]);
            if(ch[u]][c] == 0) {
                memset(ch[u],0,sizeof(ch[u]));
                fail[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
    }

    void construct() {
        queue<int> q;
        int u = 0;
        for(int i = 0;i < sigma_size;i++) {
            q.push(ch[u][i]); fail[ch[u][i]] = 0;
        }
        while(!q.empty()) {
            u = q.front(); q.pop();
            for(int i = 0;i < sigma_size;i++) {
                int &v = ch[u][i];
                if(v) {
                    fail[v] = ch[fail[u]][i];
                    q.push(v);
                } else {
                    v = ch[fail[u]][i];
                }
            }
        }
    }

    void getlim(LL num) {
    }

    LL query() {

    }
}

int main() {
    return 0;
}
