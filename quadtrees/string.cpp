#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <sstream>
#include <map>
#include <set>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

#define MAXL 5

int pots[] = {1, 4, 16, 64, 256, 1024, 4096};

string s;
int pos;
int pos0, pos1;

int
count(int d)
{
	if(s[pos] == 'f')
		return pots[MAXL - d];
	if(s[pos] == 'e')
		return 0;
	int acc = 0;
	fori(4)
	{
		++pos;
		acc += count(d + 1);
	}
	return acc;
}

inline bool
is_leave(string& s, int p)
{
	return s[p] != 'p';
}

string
merge(string s0, string s1)
{
	string res("");

	if(is_leave(s0, pos0) && is_leave(s1, pos1))
	{
		if(s0[pos0] == 'f') res += 'f';
		else res += s1[pos1];
		return re
	}
	else if(is_leave(s1, pos1))
	{
		if(s1[pos1] == 'f') res += 'f';
		else res += s0[pos0];
		return res;
	}
	else if(is_leave(s0, pos0))
	{
		if(s0[pos0] == 'f') res += 'f';
		else res += s1[pos1];
		return res;
	}
	else
	{
		fori(4)
		{
			res += merge(s0, s1);
		}
		return res;
	}

int
main()
{
	int n;
	string s0, s1;
	cin >> n;
	while(n--)
	{
		cin >> s0 >> s1;
		//s = s0;
		//pos = 0;
		//cout << count(0) << endl;
		//s = s1;
		//pos = 0;
		//cout << count(0) << endl;
		pos0 = pos1 = 0;
		s = merge(s0, s1);
		pos = 0;
		cout << count(0) << endl;
	}
	return 0;
}

