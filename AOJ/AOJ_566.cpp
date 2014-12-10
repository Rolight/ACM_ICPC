#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 10001;
int T,m,n;
string tmp;
vector<string> dict;
set<string> table;

bool cmp(const string &a,const string &b,int len) {
    for(int i = 0;i < len;i++) if(a[i] != b[i]) return false;
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for(int kase = 1;kase <= T;kase++) {
        cin >> m >> n;
        cout << "Case " << kase << ":" << endl;
        dict.clear();
        table.clear();
        for(int i = 0;i < m;i++) {
           cin >> tmp;
           if(table.count(tmp) == 0) {
                dict.push_back(tmp);
                table.insert(tmp);
           }
        }
        sort(dict.begin(),dict.end());
        for(int i = 0;i < n;i++) {
            int ct = 0;
            cin >> tmp;
            vector<string>::iterator pos = lower_bound(dict.begin(),dict.end(),tmp);
            for(;pos != dict.end() && cmp(*pos,tmp,tmp.size());pos++) {
                if(ct) cout << " ";
                cout << *pos;
                ct++;
            }
            if(ct) {
                cout << endl;
            } else {
                cout << "null" << endl;
            }
        }
    }
    return 0;
}
