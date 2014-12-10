#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;
const int maxn = 128;
char buf[maxn];
stack<char> stk;

int main() {
	while(gets(buf) != NULL) {
		while(!stk.empty()) stk.pop();
		if(buf[0] == '.') continue;
		int len = strlen(buf);
		bool bad = false;
		for(int i = 0; i < len; i++)  {
			char nowtop = 0, now = buf[i];
			if(now != '(' && now != ')' && now != '[' && now != ']') continue;
			if(!stk.empty()) nowtop = stk.top();
			if(now == ']') {
				if(nowtop == '[') stk.pop();
				else bad = true;
			}
			else if(now == ')') {
				if(nowtop == '(') stk.pop();
				else bad = true;
			}
			else stk.push(now);
		}
		if(stk.size() != 0) bad = true;
		if(bad) puts("no");
		else puts("yes");
	}
	return 0;
}