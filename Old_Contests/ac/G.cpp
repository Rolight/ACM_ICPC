#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <sstream>
#include <numeric>
#include <fstream>
#include <functional>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 400;
typedef char Str[maxn];
const Str int_max = "2147483647",
    int_min = "2147483648",
    short_max = "32767",
    short_min = "32768",
    ll_max = "9223372036854775807",
    ll_min = "9223372036854775808";

Str num;

bool ok(char *str1,const char *str2) {
    while(*str1 == '0' && *str1) str1++;
    int len1 = strlen(str1), len2 = strlen(str2);
    if(len1 > len2) return false;
    if(len1 < len2) return true;
    for(int i = 0;i < len1;i++) {
        if(str1[i] > str2[i]) {
            return false;
        }
        if(str1[i] < str2[i]) {
            return true;
        }
    }
    return true;
}

int main() {
    while(scanf("%s",num) != EOF) {
        if(num[0] == '-') {
            if(ok(num + 1, short_min)) puts("short");
            else if(ok(num + 1,int_min)) puts("int");
            else if(ok(num + 1,ll_min)) puts("long long");
            else puts("It is too big!");
        }
        else {
            if(ok(num, short_max)) puts("short");
            else if(ok(num, int_max)) puts("int");
            else if(ok(num, ll_max)) puts("long long");
            else puts("It is too big!");
        }
    }
    return 0;
}
