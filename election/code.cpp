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

map<string, string> c2p;
map<string, int> votes;

int
main()
{
	int t, n, x, ans;
	bool tie;
	string sans, cand, party;
	scanf("%d", &t);
	while(t--)
	{
		c2p.clear();
		votes.clear();
		scanf("%d", &n);
		getline(cin, cand);
		while(n--)
		{
			getline(cin, cand);
			getline(cin, party);
			c2p[cand] = party;
			votes[cand] = 0;
		}
		scanf("%d", &n);
		ans = -1;
		tie = true;
		getline(cin, cand);
		while(n--)
		{
			getline(cin, cand);
			if(votes.count(cand))
			{
				x = ++votes[cand];
				if(x > ans)
				{
					tie = false;
					ans = x;
					sans = cand;
				}
				else if(x == ans) tie = true;
			}
		}
		if(tie) printf("tie\n");
		else cout << c2p[sans] << '\n';
		if(t) printf("\n");
	}
	return 0;
}

