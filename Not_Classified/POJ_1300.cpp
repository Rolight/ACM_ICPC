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
#include <sstream>

using namespace std;

typedef long long LL;
const int maxn = 105;
int deg[maxn],n,m;
string buf;

int main() {
    //freopen("/tmp/in.txt","r",stdin);
    while(cin >> buf) {
        int cntodd = 0,cntdoor = 0;
        if(buf == "ENDOFINPUT") break;
        memset(deg,0,sizeof(deg));
        cin >> n >> m;
        getline(cin,buf);
        for(int i = 0;i < m;i++) {
            getline(cin,buf);
            int tmp;
            stringstream sin(buf);
            while(sin >> tmp) {
                deg[i]++;
                deg[tmp]++;
                cntdoor++;
            }
        }
        cin >> buf;
        for(int i = 0;i <= m;i++) if(deg[i] & 1) cntodd++;
        if(cntodd == 0 && n == 0) cout << "YES " << cntdoor;
        else if(cntodd == 2 && n != 0 && deg[0] % 2 && deg[n] % 2) 
            cout << "YES " << cntdoor;
        else cout << "NO";
        cout << endl;
    }
    return 0;
}
