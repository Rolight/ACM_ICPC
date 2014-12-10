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

using namespace std;
const char sig[11] = "*01?2????";

int main() {
    srand(time(NULL));
    int n = 5;
    for(int i = 0;i < n;i++) printf("%c",sig[rand() % 10]);
    puts("");
    return 0;
}
