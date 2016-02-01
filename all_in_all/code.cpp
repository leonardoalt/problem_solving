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

int
main()
{
	string s0, s1;
	int l, t, o;
	bool f;
	while(cin >> s0 >> s1)
	{
		l = 0;
		o = int(s0.size());
		t = int(s1.size());
		if(o > t) { printf("No\n"); continue; }
		f = true;
		fori(int(s0.size()))
		{
			for(; l < t; ++l) if(s1[l] == s0[i]) break;
			if(l == t) { f = false; printf("No\n"); break; }
			++l;
		}
		if(f) printf("Yes\n");
	}
	return 0;
}

