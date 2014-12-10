// BEGIN CUT HERE

// END CUT HERE
#line 5 "SortishDiv2.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;


class SortishDiv2
{
public:
    int n, ncnt[105], tar, nowcnt[105];
    int dfs(int now, int snd ,vector<int> &arr) {
        int ret = 0;
        if(now == n) return snd == tar;
        if(arr[now] != 0) {
            int d = 0;
            for(int j = 0; j < now; j++) if(arr[j] < arr[now]) d++;
            return dfs(now + 1, snd + d, arr);
        }
        for(int i = 1; i <= n; i++) if(ncnt[i] == 0) {
            int d = 0;
            for(int j = 0; j < now; j++) if(arr[j] < i) d++;
            ncnt[i] = 1; arr[now] = i;
            ret += dfs(now + 1, snd + d, arr);
            ncnt[i] = 0; arr[now] = 0;
        }
        return ret;
    }
    int ways(int sortedness, vector <int> seq)
    {
        n = seq.size();
        memset(ncnt, 0, sizeof(ncnt));
        memset(nowcnt, 0, sizeof(nowcnt));
        for(int i = 0; i < n; i++) ncnt[seq[i]] = 1;
        tar = sortedness;
        return dfs(0, 0,seq);
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 5; int Arr1[] = {4, 0, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, ways(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 4; int Arr1[] = {0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, ways(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 2; int Arr1[] = {1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, ways(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 2; int Arr1[] = {1, 2, 0, 5, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, ways(Arg0, Arg1)); }

    // END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SortishDiv2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
