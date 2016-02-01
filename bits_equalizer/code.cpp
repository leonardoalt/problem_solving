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

vector<int> vecs[2];
vector<int> ivecs[2];

int
main()
{
	int te, l, ans, is, b, ca=0, f;
	string s, t;
	scanf("%d", &te);
	while(te--)
	{
		vecs[0].clear();
		vecs[1].clear();
		ivecs[0].clear();
		ivecs[1].clear();
		cin >> s >> t;
		l = int(s.size());
		ans = 0;
		is = 0;
		fori(l)
		{
			if(s[i] == '?')
			{
				++is;
				ivecs[t[i]-'0'].push_back(i);
				continue;
			}
			if(s[i] == t[i]) continue;
			vecs[s[i]-'0'].push_back(i);
		}
		printf("Case %d: ", ++ca);
		ans += min(vecs[0].size(), vecs[1].size());
		b = vecs[0].size() < vecs[1].size();
		f = (int(vecs[b].size()) - int(vecs[!b].size()));
		if(b == 0) { printf("%d\n", ans + f + is); continue; }
		if(int(ivecs[b].size()) < f)
		{
			printf("-1\n");
			continue;
		}
		ans += is + f;
		printf("%d\n", ans);
	}
	return 0;
}

