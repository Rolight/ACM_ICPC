#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

map<string,int> count;
string dict[6],board[40];
int hei,wid,size;

bool putcross(string word,int x,int y) {

}

bool putverical(string word,int x,int y) {

}

void dfs(int x,int y,int rest) {
	if(rest == 0) return;
	for(int i = 0;i < 6;i++) {
		
	}
}

int main() {
	for(int i = 0;i < 6;i++) cin >> dict[i];
	sort(dict,dict + 6);
	for(int i = 0;i < 6;i++) 
		if(dict[i].size() > size)
			size = dict[i];
	dfs(0,0,6);
}
