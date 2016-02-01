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

#define MAXN 110

int games[MAXN];
int wins[MAXN];

int
main()
{
	bool first = true;
	int n, k, p1, p2;
	string s1, s2;
	while(1)
	{
		scanf("%d", &n);
		if(!n) break;
		if(!first) printf("\n");
		first = false;
		scanf("%d", &k);
		memset(games, 0, sizeof(games));
		memset(wins, 0, sizeof(wins));
		fori((k*n*(n-1))/2)
		{
			cin >> p1 >> s1 >> p2 >> s2;
			--p1; --p2;
			if(s1[0] == s2[0]) continue;
			++games[p1];
			++games[p2];
			if(s1[0] == 'r')
			{
				if(s2[0] == 's') ++wins[p1];
				else ++wins[p2];
			}
			else if(s1[0] == 's')
			{
				if(s2[0] == 'r') ++wins[p2];
				else ++wins[p1];
			}
			else
			{
				if(s2[0] == 's') ++wins[p2];
				else ++wins[p1];
			}
		}
		fori(n)
		{
			if(games[i] == 0) printf("-\n");
			else
			{
				double d = wins[i];
				printf("%.3lf\n", d/games[i]);
			}
		}
	}
	return 0;
}

