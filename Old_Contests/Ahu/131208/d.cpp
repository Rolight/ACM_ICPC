#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

char line[3000];
map<int,int> k;
bool ass[3000];
typedef map<int,int>::iterator mit;

int main() {
	int n; cin >> n;
	getchar();
	for(int c = 0;c < n;c++) {
		int i = 0,a,b,max = 0,rest;
		while(1) {
			while(scanf("%c",line + i),line[i] != '\n') i++;
			line[i] = 0;
			if(line[0] == ' ') break;
			sscanf(line,"%d%d",&a,&b);
			k[a][b] = 1;
			if(a > max) max = a;
			if(b > max) max = b;
		}
		rest = max;
		for(int i = 1;i <= max;i++) k[i][i] = 1;
		i = 1;
		for(int i = 1;i <= n;i++) if(!ass[i]) {
			
		}
	}
}
