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

typedef pair<int, char> par;

set<par> seta;
int vec[30];

int
main()
{
	int t;
	char c;
	memset(vec, 0, sizeof(vec));
	scanf("%d", &t);
	while(getchar() != '\n');
	while(t--)
	{
		while((c = getchar()) != '\n')
		{
			if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) continue;
			c = toupper(c);
			--vec[c-'A'];
		}
	}
	for(int i = 'A'; i <= 'Z'; ++i) if(vec[i-'A'] < 0) seta.insert(par(vec[i-'A'], i));
	for(set<par>::iterator it = seta.begin(); it != seta.end(); ++it) printf("%c %d\n", it->second, it->first*-1);
	return 0;
}

