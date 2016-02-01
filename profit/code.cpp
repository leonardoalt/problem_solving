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

#define MAXN 60

int revs[MAXN];

int
main()
{
	int n, cost, meh, msf;
	while(cin >> n)
	{
		cin >> cost;
		fori(n)
		{
			cin >> revs[i];
			revs[i] -= cost;
		}
		meh = msf = 0;
		fori(n)
		{
			meh = max(0, meh + revs[i]);
			msf = max(msf, meh);
		}
		cout << msf << '\n';
	}
	return 0;
}

