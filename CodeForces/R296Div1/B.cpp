#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector>

using namespace std;
const int maxn = 2e5 + 10;

struct Node {
    int x, w;
    bool operator < (const Node &p) const {
        if(x + w == p.x + p.w) return x < p.x;
        return x + w < p.x + p.w;
    }
};

Node node[maxn];
int n;

int main() {
    scanf("%d", &n);
    for(int i)
    return 0;
}

