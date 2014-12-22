/*
ID: flsnnx1
LANG: C++
TASK: fracdec
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;
const int maxn = 1000000 + 5;
int vis[maxn];
int num[maxn];
string ans;

void solve(int a,int b) {
    stringstream sout;
    memset(vis,-1,sizeof(vis));
    sout << a / b  << ".";
    a %= b;
    int pos = 0,cycpos;
    bool cyc = false;
    while(1) {
        num[pos] = (a * 10) / b;
        int mod = (a * 10) % b;
        if(mod == 0) break;
        if(vis[mod] == -1) {
            vis[mod] = pos;
        } else {
            if(num[vis[mod]] == num[pos]) {
                cyc = true; cycpos = vis[mod];
                pos--;
                break;
            } else vis[mod] = pos;
        }
        pos++;
        a = mod;
    }
    for(int i = 0;i <= pos;i++) {
        if(cyc && i == cycpos) sout << "(";
        sout << num[i];
    }
    if(cyc) sout << ")";
    ans = sout.str();
    int len = ans.size();
    for(int i = 0;i < len;i++) {
        if(i % 76 == 0 && i) cout << endl;
        cout <<ans[i];
    }
    cout << endl;
}

int main() {
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    int a,b; cin >> a >> b;
    solve(a,b);
    return 0;
}
