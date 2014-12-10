#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>

using namespace std;

struct cow {
	int dline,g;
} c[10001];

bool cmp(cow a,cow b) {
	if(a.dline == b.dline) return a.g > b.g;
	else return a.dline < b.dline;
}

bool operator< (cow a,cow b) {
	return a.g < b.g;
}

map<cow,int> in;
int sec[10001];

int main() {
	int n,ans = 0,pos = 0;
	ifstream fin("msched.in");
	ofstream fout("msched.out");
	fin >> n;
	for(int i = 0;i < n;i++) fin >> c[i].g >> c[i].dline;
	sort(c,c + n,cmp);
	for(int i = 0;i < n;i++) {
		if(pos < c[i].dline) {
			sec[++pos] = c[i].g;
			in[c[i]] = pos;
		}
		else {
			map<cow,int>::iterator min = in.begin();
			if((min->first).g < c[i].g) {
				sec[min->second] = c[i].g;
				in[c[i]] = min->second;
				in.erase(min); 
			}
		}
	}
	for(int i = 0;i <= c[n - 1].dline;i++) ans += sec[i];
	fout << ans << endl;
	return 0;
}
