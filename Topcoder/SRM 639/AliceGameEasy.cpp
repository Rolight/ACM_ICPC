#line 5 "AliceGameEasy.cpp"
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

class AliceGameEasy
{
        public:
        long long findMinimumValue(long long x, long long y)
        {
			long long sum = 0, t = 1;
			while(sum < x + y) {
				sum += t; t++;
			}
			t--;
			if(sum != x + y) return -1;
			if(x == 0) return 0;
			sum = 0;
			for(long long i = t, ans = 1; i >= 1; i--, ans++) {
				sum += i;
				if(sum >= x) return ans;
			}
			return -1;
        }
        

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

