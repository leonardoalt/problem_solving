#include <stack>
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

queue<int> stations[MAXN];
stack<int> carrier;
int n, s, q;

bool
check()
{
	fori(n) if(stations[i].size() > 0) return true;
	return false;
}

int
main()
{
	int t, ans, sta, x, y, tc, nc;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d %d %d", &n, &s, &q);
		fori(n) { while(!stations[i].empty()) stations[i].pop(); }
		while(!carrier.empty()) carrier.pop();
		nc = 0;
		fori(n)
		{
			scanf("%d", &x);
			if(x) ++nc;
			forj(x)
			{
				scanf("%d", &y);
				stations[i].push(y-1);
			}
		}

		ans = 0;
		sta = 0;
		while(1)
		{
			bool we = stations[sta].empty();
			while(1) //unload
			{
				if(carrier.empty()) break;
				t = carrier.top();
				if(t != sta && int(stations[sta].size()) >= q) break;
				if(t != sta) stations[sta].push(t);
				carrier.pop();
				++ans;
			}
			bool ie = stations[sta].empty();
			if(we

			while(int(carrier.size()) < s && !stations[sta].empty()) //load
			{
				++ans;
				carrier.push(stations[sta].front());
				stations[sta].pop();
			}

			if(carrier.size() > 0 || nc)
			{
				ans += 2;
				if(sta == (n - 1)) sta = 0;
				else ++sta;
			}
			else break;
		}
		printf("%d\n", ans);
	}
	return 0;
}

