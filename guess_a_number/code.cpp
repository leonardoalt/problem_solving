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
	int n;
	string s;
	char a;
	long long v, min, max;
	while(scanf("%d", &n) != EOF)
	{
		min = -1000000001;
		max =  1000000001;
		fori(n)
		{
			cin >> s >> v >> a;

			if(a == 'N')
			{
				if(s == "<") s = ">=";
				else if(s == "<=") s = ">";
				else if(s == ">") s = "<=";
				else s = "<";
			}

			if(s == "<") { --v; s = "<="; }
			else if(s == ">") { ++v; s = ">="; }

			if(s == "<=")
			{
				if(v < max) max = v;
			}
			else
			{
				if(v > min) min = v;
			}
		}
		if(max < min) printf("Impossible\n");
		else printf("%lld\n", min);
	}
	return 0;
}

