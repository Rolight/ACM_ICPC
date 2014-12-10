#include <cstdio>
#include <cstring>

using namespace std;

char tolow(char c) {
	if(c >= 'A' && c <= 'Z') return c - 'A' + 'a';
	return c;
}

char toup(char c) {
	if(c >= 'a' && c <= 'z') return c - 'a' + 'A';
}

bool isalpha(char c) {
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int dput(char *word,int len) {
	bool first = true;
	int count = 0;
	for(int i = 0;i < len;i++) if(isalpha(word[i])) {
		if(first) putchar(toup(word[i])),first = false;
		else putchar(tolow(word[i]));
		count++;
	}
	return count;
}

void process(char *str) {
	while(str[0] == ' ') str++;
	int len = strlen(str),first = 1;
	char s[200],s1[200];
	if(str[0] == '#' || str[0] == 0) return;
	sscanf(str,"%s%s",s,s1);
	printf("%s\t%s",s,s1);
	while(str[0] != '#') str++;
	while(str[0] == '#') str++;
	sscanf(str,"%s",s);
	if(strcmp("<CJK>",s) == 0) {
		putchar('\n'); return;
	}
	while(str[0]) {
		while(str[0] == ' ') str++;
		if(str[0] == 0) break;
		sscanf(str,"%s",s);
		if(first) {
			putchar('\t');
			first = 0;
		} else putchar(' ');
		dput(s,strlen(s));
		str += strlen(s);
	}
	puts("");
}

void work() {
	char str[200];
	while(gets(str) != NULL) process(str);
}

int main() {
	work();
	return 0;
}
