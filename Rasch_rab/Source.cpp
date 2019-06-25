#include<iostream>
#include<conio.h>
#include<tuple>
#include<vector>
#include<set>
#include<fstream>

using namespace std;


int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	vector<pair<short, short>> vec_g;

	set<short> rebr;
	set<short> _notuse;
	set<short> _notdef;
	short _start;

	int N;
	fin >> N;
	for (int i(0); i < N; i++)
	{
		short a;
		short b;
		fin >> a >> b;
		vec_g.push_back(pair<short, short>(a, b));
	}
	for (const pair<short, short>& a : vec_g)
	{
		_notdef.insert(a.first);
		_notdef.insert(a.second);
	}
	while (!_notdef.empty())
	{
		_start = *_notdef.begin();
		_notdef.erase(_notdef.begin());
		do{
			for (int i(0); i < vec_g.size(); i++)
			{
				if (vec_g[i].first == _start && _notdef.find(vec_g[i].second) != _notdef.end())
				{
					_notdef.erase(_notdef.find(vec_g[i].second));
					rebr.insert(i);
					_notuse.insert(vec_g[i].second);
				}
				if (vec_g[i].second == _start && _notdef.find(vec_g[i].first) != _notdef.end())
				{
					_notdef.erase(_notdef.find(vec_g[i].first));
					rebr.insert(i);
					_notuse.insert(vec_g[i].first);
				}
			}
			if (_notuse.empty())
				break;
			_start = *_notuse.begin();
			_notuse.erase(_notuse.begin());

		} while (1);
	}
	fout << rebr.size() << endl;
	for (const short& a : rebr)
	{
		fout << vec_g[a].first << ' ' << vec_g[a].second << endl;
	}
	return 0;
}