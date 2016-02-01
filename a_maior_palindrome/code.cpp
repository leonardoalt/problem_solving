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

string s;
int siz;

bool
check(int l, int r)
{
	while(l < r)
	{
		if(s[l] != s[r])
			return false;
		++l; --r;
	}
	return true;
}

bool
func0()
{
	int l = int(s.size());
	fori(l)
	{
		if((i + siz) > l) break;
		if(check(i, i+siz-1))
		{
			return true;
		}
	}
	return false;
}

int
main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		cin >> s;
		siz = int(s.length());
		while(siz > 1)
		{
			if(func0()) break;
			--siz;
		}
		printf("%d\n", siz);
	}
	return 0;
}

