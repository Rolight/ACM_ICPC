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
char str1[maxn], str2[maxn];
int pos[26 * 26], pos1[26 * 26];

int hash(char a, char b) {
    return (a - 'a') * 26 + b - 'a';
}

int main() {
    memset(pos, -1, sizeof(pos));
    int len, ap1 = -2, ap2 = -2, hm = 0;
    scanf("%d", &len);
    scanf("%s%s", str1, str2);
    for(int i = 0; i < len; i++) {
        if(str1[i] == str2[i]) continue;
        if(pos[hash(str2[i], str1[i])] != -1) {
            ap1 = pos[hash(str2[i], str1[i])];
            ap2 = i;
            break;
        }
        pos[hash(str1[i], str2[i])] = i;
    }
    if(ap1 < 0) {
        memset(pos, -1, sizeof(pos));
        memset(pos1, -1, sizeof(pos1));
        for(int i = 0; i < len; i++) if(str1[i] != str2[i]) {
            if(pos[str2[i] - 'a'] != -1) {
                ap1 = pos[str2[i] - 'a']; ap2 = i; break;
            }
            else if(pos1[str1[i] - 'a'] != -1) {
                ap1 = pos1[str1[i] - 'a']; ap2 = i; break;
            }
            pos[str1[i] - 'a'] = i;
            pos1[str2[i] - 'a'] = i;
        }
    }
    if(ap1 >= 0) swap(str1[ap1], str1[ap2]);
    for(int i = 0; i < len; i++) if(str1[i] != str2[i]) hm++;
    printf("%d\n%d %d\n", hm, ap1 + 1, ap2 + 1);
    return 0;
}

