#include <cstdio>
#include <cstring>
#include <map>

using namespace std;
 
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
const int maxn = 2e7 + 10;
const int hsb = 1e9 + 7;

map<LL, PII> mp;
char buf[maxn], qv[maxn];
int len;

void optstr(int ,int);

int gao(int nowpos, LL nowkey) {
    bool iskey = true;
    LL keyhash = nowkey * hsb + '.';
    int vl = nowpos, vr = -1;
    for(int i = nowpos; i < len; i++) {
        if(buf[i] == ':') {
            iskey = false; vl = i + 1;
            if(buf[i + 1] == '{') i = gao(i + 2, keyhash);
        }
        else if(buf[i] == ',' || buf[i] == '}') {
            vr = i - 1;
            mp[keyhash] = MP(vl, vr);
            keyhash = nowkey * hsb + '.';
            iskey = true;
            if(buf[i] == '}') return i;
        }
        else if(iskey) keyhash = keyhash * hsb + buf[i];
    }
}

void optstr(int l, int r) {
    for(int i = l; i <= r; i++) putchar(buf[i]); puts("");
}

LL gethash(char *str) {
    int len = strlen(str);
    LL ret = 0;
    for(int i = 0; i < len; i++) ret = ret * hsb + str[i];
    return ret;
}

int main() {
    int T; scanf("%d", &T);
    qv[0] = '.';
    while(T--) {
        mp.clear();
        scanf("%s", buf);
        len = strlen(buf);
        gao(1, 0);
        int Q; scanf("%d", &Q);
        for(int i = 0; i < Q; i++) {
            scanf("%s", qv + 1);
            LL nowhash = gethash(qv);
            if(mp.count(nowhash)) optstr(mp[nowhash].first, mp[nowhash].second);
            else puts("Error!");
        }
    }
    return 0;
}
