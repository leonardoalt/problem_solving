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

int veca[30];
int vecb[30];

int
main()
{
	string a, b;
	while(getline(cin, a) && getline(cin, b))
	{
		memset(veca, 0, sizeof(veca));
		memset(vecb, 0, sizeof(vecb));
		fori(int(a.size())) ++veca[a[i]-'a'];
		fori(int(b.size())) ++vecb[b[i]-'a'];
		fori(26)
		{
			if(veca[i] == 0 || vecb[i] == 0) continue;
			forj(min(veca[i], vecb[i])) printf("%c", char(i+'a'));
		}
		printf("\n");
	}
	return 0;
}

