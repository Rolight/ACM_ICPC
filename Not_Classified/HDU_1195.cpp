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
const int maxn = 10;
int d[maxn][maxn][maxn][maxn];

struct Node {
    int v[4],dist;
    Node(int a[4],int dd):dist(dd) {
        for(int i = 0;i < 4;i++) v[i] = a[i];
    }
};

bool insert(Node &node,int val) {
    int &vv = d[node.v[0]][node.v[1]][node.v[2]][node.v[3]];
    if(vv <= val) return false;
    vv = val;
    return true;
}

Node opr(Node node,int pos,int val) {
    node.v[pos] += val;
    if(node.v[pos] == 0) node.v[pos] = 9;
    if(node.v[pos] == 10) node.v[pos] = 1;
    return node;
}

void bfs(int a[4],int b[4]) {
    memset(d,0x7f,sizeof(d));
    queue<Node> q;
    q.push(Node(a,0));
    while(!q.empty()) {
        Node now = q.front(); q.pop();
        for(int i = 0;i < 4;i++) {
            for(int j = -1;j <= 1;j += 2) {
                Node nn = opr(now,i,j);
                if(insert(nn,now.dist + 1)) {
                    q.push(Node(nn.v,now.dist + 1));
                }
                if(i + j < 0 || i + j >= 4) continue;
                Node nn1 = now;
                swap(nn1.v[i],nn1.v[i + j]);
                if(insert(nn1,now.dist + 1)) {
                    q.push(Node(nn1.v,now.dist + 1));
                }
            }
        }
    }
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        int tv[2][4];
        for(int i = 0;i < 2;i++) {
            for(int j = 0;j < 4;j++) scanf("%1d",&tv[i][j]);
        }
        bfs(tv[0],tv[1]);
        printf("%d\n",d[tv[1][0]][tv[1][1]][tv[1][2]][tv[1][3]]);
    }
    return 0;
}
