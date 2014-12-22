/*
ID: flsnnx1
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void eatline(ifstream &fin)
{
	fin.get();
}

int main()
{
	char *infilename = "gift1.in";
	char *outfilename = "gift1.out";
	ofstream fout(outfilename);
	ifstream fin(infilename);
	
	map<string,int> people;
	vector<string> namelist;
	
	int i,np;
	fin >> np;
	eatline(fin);
	cout << np << endl;
	for(i = 0;i < np;i++)
	{
		string name;
		getline(fin,name);
		people[name] = 0;
		namelist.push_back(name);
	}

	for(i = 0;i < np;i++)
	{
		int n,total,j,momey = 0;
		string name(""),nowname("");
		getline(fin,nowname);
		fin >> total >> n;
		eatline(fin);
		//people[nowname] = total;
		for(j = 0;j < n;j++)
		{
			getline(fin,name);
			people[name] += total / n;
			people[nowname] -= total / n;
		}
	}

	for(vector<string>::iterator iter = namelist.begin();
			iter != namelist.end();++iter)
		fout << (*iter) << " " << people[(*iter)] << endl;
	fin.close();
	fout.close();
	return 0;
}
