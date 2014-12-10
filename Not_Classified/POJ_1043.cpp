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
const int maxn = 30;
map<string,int> real,fake;
vector<string> strreal,strfake;
vector<pair<string,string> > outbuf;
bool inroomr[maxn],inroomf[maxn * maxn];
bool g[maxn * maxn][maxn * maxn];
string buf,name;
int n;

int realid(string &name) {
    return real[name];
}

int fakeid(string &name) {
    if(fake.count(name) == 0) {
        int m = fake.size();
        fake[name] = m;
        strfake.push_back(name);
    }
    return fake[name];
}

int bx[maxn],by[maxn * maxn];
bool vis[maxn * maxn];

int dfs(int now) {
    int mm = fake.size();
    for(int i = 0;i < mm;i++) if(!vis[i] && g[now][i]) {
        vis[i] = true;
        if(by[i] == -1 || dfs(by[i])) {
            by[i] = now; bx[now] = i;
            return 1;
        }
    }
    return 0;
}

void solve() {
    memset(bx,-1,sizeof(bx));
    memset(by,-1,sizeof(by));
    outbuf.clear();
    int ans = 0;
    for(int i = 0;i < n;i++) if(bx[i] == -1) {
        memset(vis,0,sizeof(vis));
        ans += dfs(i);
    }
    int mm = fake.size();
    for(int i = 0;i < mm;i++) {
        int sum = 0;
        for(int j = 0;j < n;j++) if(g[j][i] && bx[j] == -1) {
            sum++; break;
        }
        if(sum || by[i] == -1) 
            outbuf.push_back(make_pair(strfake[i],":???"));
        else outbuf.push_back(make_pair(strfake[i],string(":") + strreal[by[i]]));
    }
    sort(outbuf.begin(),outbuf.end());
    for(int i = 0;i < outbuf.size();i++) {
        cout << outbuf[i].first << outbuf[i].second << endl;
    }
}

int main() {
    while(cin >> n) {
        real.clear();
        fake.clear();
        strreal.clear();
        strfake.clear();
        memset(inroomr,0,sizeof(inroomr));
        memset(inroomf,0,sizeof(inroomf));
        memset(g,0,sizeof(g));
        for(int i = 0;i < n;i++) {
            cin >> buf; real[buf] = i;
            strreal.push_back(buf);
        }
        while(cin >> buf,buf[0] != 'Q') {
            cin >> name;
            if(buf[0] == 'E') {
                inroomf[fakeid(name)] = true;
            }
            if(buf[0] == 'M') {
                int mm = fake.size(),nowid = realid(name);
                for(int i = 0;i < mm;i++) if(!inroomf[i]) {
                    g[nowid][i] = false;
                } else if(!inroomr[nowid]) g[nowid][i] = true;
                inroomr[nowid] = true;
            }
            if(buf[0] == 'L') {
                inroomf[fakeid(name)] = false;
            }
        }
        solve();
    }
    return 0;
}
