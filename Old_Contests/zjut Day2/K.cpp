#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
	char str[1001],c[53];
	while(gets(str)) {
		memset(c,0,sizeof(c));
		int count = 0,len = strlen(str);
		for(int i = 0;i < len;i++) 
			if(isalpha(str[i]) && !c[str[i] - 'a']) {
				count++; c[str[i] - 'a'] = 1;
			}
		if(count % 2 == 0) puts("CHAT WITH HER!");
		else puts("IGNORE HIM!");
	}
	return 0;
}
