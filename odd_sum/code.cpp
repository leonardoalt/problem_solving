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
	int t, a, b, s, ca=0;
	scanf("%d", &t);
	while(t--)
	{
		s = 0;
		scanf("%d %d", &a, &b);
		for(int i = a; i <= b; ++i) if(i & 1) s += i;
		printf("Case %d: %d\n", ++ca, s);
	}
	return 0;
}

