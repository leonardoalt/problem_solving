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

map<string, int> mapa;
string vec[5];

int
main()
{
	int n, m, x, ans;
	string s;
	while(1)
	{
		scanf("%d", &n);
		if(!n) break;
		mapa.clear();
		m = 1;
		fori(n)
		{
			forj(5) cin >> vec[j];
			sort(vec, vec+5);
			s = "";
			forj(5) s += vec[j];
			if(mapa.count(s))
			{
				x = ++mapa[s];
				if(x > m) m = x;
			}
			else mapa[s] = 1;
		}
		ans = 0;
		for(map<string, int>::iterator it = mapa.begin(); it != mapa.end(); ++it)
			if(it->second == m) ans += m;
		printf("%d\n", ans);
	}
	return 0;
}

