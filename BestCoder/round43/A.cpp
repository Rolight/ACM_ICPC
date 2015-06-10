#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <ctime>
#include <cstdlib>

typedef long long LL;

int main() {
	int T; std::cin >> T;
	while(T--) {
		std::string str, a = "", b = "";
		std::cin >> str;
		for(int i = 0; i < str.size(); i++) {
			if(i & 1) b += str[i];
			else a += str[i];
		}
		std::reverse(b.begin(), b.end());
		std::cout << a << "\n" << b << std::endl;
	}
	return 0;
}
