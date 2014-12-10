#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <sstream>
#include <numeric>
#include <fstream>
#include <functional>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 100000 + 10;
const int maxk = 30;
const int mod = 65536;
int n,k;

struct Node {
    int data[maxk];
    Node(int val = 0) {
        int pos = 0;
        memset(data,0,sizeof(data));
        while(val) {
            data[pos++] = val & 1;
            val >>= 1;
        }
    } 

    bool operator == (const Node &node) const {
        for(int i = 0;i < k;i++) if(node.data[i] != data[i]) return false;
        return true;
    }
};

Node operator + (Node a,Node b) {
    for(int i = 0;i < k;i++) {
        a.data[i] += b.data[i];
    }
    return a;
}


void con(Node &node) {
    int minval = INF;
    for(int i = 0;i < k;i++) //if(node.data[i] != 0)  
        minval = min(minval,node.data[i]);
    for(int i = 0;i < k;i++) //if(node.data[i] != 0)
        node.data[i] -= minval;
}

int gethash(const Node &node) {
    int ret = 0;
    for(int i = 0;i < k;i++) {
        ret = ret * (n + 1) + node.data[i];
    }
    return ret & (mod - 1);
}


Node cow[maxn],val[maxn];
int head[mod],nxt[maxn],pos[maxn],sz;

int ask(const Node &node,int p) {
    int hc = gethash(node);
    for(int i = head[hc];~i;i = nxt[i]) {
        if(val[i] == node) return pos[i];
    }
    val[sz] = node; pos[sz] = p;
    nxt[sz] = head[hc]; head[hc] = sz++;
    return p;
}

int main() {
    while(scanf("%d%d",&n,&k) != EOF) {
        memset(head,-1,sizeof(head));
        sz = 0;
        for(int i = 1;i <= n;i++) {
            int tmp; scanf("%d",&tmp);
            cow[i] = cow[i - 1] + Node(tmp);
        }
        for(int i = 1;i <= n;i++) con(cow[i]);
        int ans = 0;
        for(int i = 0;i <= n;i++) {
    //        for(int j = 0;j < k;j++) printf("%d ",cow[i].data[j]); putchar('\n');
            int pos = ask(cow[i],i);
            ans = max(ans,i - pos);
        }
        printf("%d\n",ans);
    }
    return 0;
}
