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
const int maxn = 1e6 + 5;
bool lv[maxn],rv[maxn];
set<pair<int,int> > st;
int cntl,cntr;
vector<int> l,r;

int main() {
    for(int i = 1;i <= 8;i++) {
        int x,y; cin >> x >> y;
        if(!lv[x]) {
            cntl++; l.push_back(x); lv[x] = true;
        }
        if(!rv[y]) {
            cntr++; r.push_back(y); rv[y] = true;
        }
        st.insert(make_pair(x,y));
    }
    if(cntl != 3 || cntr != 3) {
        puts("ugly");
    } else {
        bool bad = false;
        sort(l.begin(),l.end());
        sort(r.begin(),r.end());
        for(int i = 0;i < 3;i++) {
            for(int j = 0;j < 3;j++) {
                if(i == 1 && j == 1) continue; 
                int ret = st.count(make_pair(l[i],r[j]));
                if(ret != 1) bad = true;
            }
        }
        if(bad) puts("ugly");
        else puts("respectable");
    }
    return 0;
}
