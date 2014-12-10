#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct time {
	int h,m,s;
	time(int hh,int mm,int ss):h(hh),m(mm),s(ss){};
	time():h(0),m(0),s(0){};
	string tostr() {
		ostringstream sout;
		sout << h << ":";
		if(m < 10) sout << "0"; sout << m << ":";
		if(s < 10) sout << "0"; sout << s;
		return sout.str();
	};
	time operator+=(time a) {
		s += a.s; m += a.m; h += a.h;
		if(s > 59) {
			m += s / 60;
			s %= 60;
		}
		if(m > 59) {
			h += m / 60;
			m %= 60;
		}
		return *this;
	}
};

time operator+(time a,time b) {
	return a += b;
}

bool operator<(time a,time b) {
	if(a.h != b.h) return a.h < b.h;
	if(a.m != b.m) return a.m < b.m;
	if(a.s != b.s) return a.s < b.s;
	return false;
}

bool operator!=(time a,time b) {
	return (a.h != b.h) || (a.m != b.m) || (a.s != b.s);
}

struct person {
	string name;
	time total;
	vector<bool> solved;
	vector<time> punish;
	int totalsolved;
	person(): name(""),solved(27,false),punish(27),totalsolved(0) {};
};

bool cmp(person a,person b) {
	if(a.totalsolved != b.totalsolved) return a.totalsolved > b.totalsolved;
	if(a.total != b.total) return a.total < b.total;
	return a.name < b.name;
}

map<string,person> all;
vector<person> personlist;
time punishtime(0,20,0);

void process(string& line) {
	istringstream sin(line);
	string name,sta;
	char pid,tmp;
	int h,m,s,pnum;
	sin >> name >> pid >> h >> tmp >> m >> tmp >> s >> sta;
	time nowtime(h,m,s);
	pnum = pid - 'A';
	person &now = all[name];
	if(now.name == "") now.name = name;
	if(now.solved[pnum] == true) return;
	if(sta == "Accepted") {
		now.solved[pnum] = true;
		now.total += (nowtime + now.punish[pnum]);
		now.totalsolved++;
	} else now.punish[pnum] += punishtime;
}

void work() {
	string line;
	while(getline(cin,line)) process(line);
	for(map<string,person>::iterator iter = all.begin();iter != all.end();++iter) personlist.push_back(iter->second);
	sort(personlist.begin(),personlist.end(),cmp);
	int nowrank = 1;
	for(vector<person>::iterator iter = personlist.begin();iter != personlist.end();++iter) {
		if(iter != personlist.begin() && (iter->totalsolved != (iter - 1)->totalsolved || iter->total != (iter - 1)->total)) nowrank = (int)(iter - personlist.begin() + 1);
		if(iter->totalsolved == 0) cout << "- ";
		else cout << nowrank << " ";
		cout << iter->name << " " << iter->totalsolved << " " << iter->total.tostr() << endl;
	}
}

int main() {
	work();
	return 0;
}
