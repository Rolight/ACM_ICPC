#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>
#include <set>
#include <string>
#include <map>

#define maxn 150

using namespace std;

map<string,set<string> > folder,file;

int main() {
	int maxfile = 0,maxfolder = 0;
	char line[1000];
	while(gets(line) != NULL) {
		bool isfile = false;
		int pos;
		string dad,son;
		int len = strlen(line);
		for(pos = 0;line[pos] != '\\';pos++) dad += line[pos];
		dad += line[pos++];
		for(pos;line[pos] != '\\';pos++) dad += line[pos];
		son = dad + line[pos++];
		while(1) {
			for(pos;line[pos] != '\\' && pos < len;pos++) son += line[pos];
			for(int j = 0;j < son.size();j++) if(son[j] == '.') 
				isfile = true;
			if(isfile) {
				file[dad].insert(son);
				if(maxfile < file[dad].size()) 
					maxfile = file[dad].size();
				break;
			} else {
				folder[dad].insert(son);
				if(maxfolder < folder[dad].size())
					maxfolder = folder[dad].size();
			}
			son += line[pos++];
		}
	}
	printf("%d %d\n",maxfolder,maxfile);
	return 0;
}
