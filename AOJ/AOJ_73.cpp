#include <string>
#include <cstring>
#include <set>
#include <iostream>

using namespace std;

const int maxn = 105;
typedef set<string>::iterator Sit;
set<string> st;
string buf, cmd;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n; cin >> n;
        st.clear();
        for(int i = 0; i < n; i++) {
            cin >> cmd >> buf;
            if(cmd == "Visit") st.insert(buf);
            else {
                int len = buf.size();
                for(Sit it = st.begin(); it != st.end(); ++it) {
                    if(strncmp(buf.c_str(), it->c_str(), len) == 0) {
                        cout << *it << endl;
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}
