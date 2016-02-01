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

int vec[1000];

int
main()
{
	int t, k, v, n, ans, b, c;
	char a;
	string line;
	scanf("%d", &t);
	while(t--)
	{
		memset(vec, 0, sizeof(vec));
		scanf("%d", &k);
		while(k--)
		{
			cin >> a >> v;
			vec[int(a) + 200] = v;
		}

		scanf("%d", &n);
		getline(cin, line);
		ans = 0;
		while(n--)
		{
			getline(cin, line);
			for(int i = 0; i < (int)line.length(); ++i)
				ans += vec[int(line[i]) + 200];
		}
		b = ans/100;
		c = ans%100;
		if(c >= 10) printf("%d.%d$\n", b, c);
		else printf("%d.0%d$\n", b, c);
	}
	return 0;
}

