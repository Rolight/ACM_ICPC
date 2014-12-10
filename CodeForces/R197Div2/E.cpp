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
const int maxn = 1000 + 5;
int a[maxn],n,cnt,l[4],r[4];

void swap(int &a,int &b) { int t = a; a = b; b = t; }
int rev(int l,int r) { while(l < r) swap(a[l++],a[r--]);  };
int find(int x) { for(int i = 1;i <= n;i++) if(a[i] == x) return i;  }
bool check() {
    for(int i = 1;i <= n;i++) if(a[i] != i) return false;
    return true;
}
bool dfs(int x) {
    if(x > 3) return false;
    int bl = 1,br = n;
    while(a[bl] == bl && bl <= n) bl++;
    while(a[br] == br && br >= 1) br--;
    if(bl == n + 1) {
        return true;
    }
    rev(bl,br);
    if(check()) {
        l[x] = bl; r[x] = br; return true;
    }
    if(x == 3) return false;
    rev(bl,br);
    int cr = find(bl),cl = find(br);
    rev(bl,cr); l[x] = bl; r[x] = cr;
    if(dfs(x + 1)) return true;
    rev(bl,cr); rev(cl,br); l[x] = cl; r[x] = br;
    if(dfs(x + 1)) return true;
    rev(cl,br);
    return false;
}

int main() {
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    dfs(1);
    vector<int> ansl,ansr;
    for(int i = 1;i <= 3;i++) {
        int nl = max(l[i],1),nr = max(r[i],1);
        if(nl != nr) {
            ansl.push_back(nl);
            ansr.push_back(nr);
        }
    }
    printf("%d\n",(int)ansl.size());
    for(int i = 0;i < ansl.size();i++) printf("%d %d\n",ansl[i],ansr[i]);
    return 0;
}
