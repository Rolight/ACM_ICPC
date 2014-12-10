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
string hrline(80,'-'),buf,enter("<br>"),hrl("<hr>");

int main() {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    bool first = true;
    int nowpos = 0;
    while(cin >> buf) {
        int len = buf.size();
        //cout << buf << endl;
        if(buf == enter) {
            first = true;
            cout << endl;
            nowpos = 0;
        }
        else if(buf == hrl) {
            if(first == false) cout << endl;
            first = true;
            nowpos = 0;
            cout  << hrline << endl;
        }
        else {
            //printf("now pos is %d\n",nowpos);
            if(!first) len++;
            if(nowpos + len > 80) {
                cout << endl << buf;
                nowpos = len - 1;
            } else {
                if(!first) cout << " ";
                first = false;
                cout << buf;
                nowpos += len;
            }
        }
    }
    if(!first) cout << endl;
    return 0;
}
