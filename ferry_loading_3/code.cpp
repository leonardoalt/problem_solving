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

typedef pair<int, int> car;
car vec[10010];
char lado[10];
int times[10010];

int
main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &t, &m);
		fori(m)
		{
			scanf("%d %s", &car[i].first, lado);
			car[i].second = lado[0] == 'r';
		}

		l = 0;
		p = 0;
		acc = 0;
		while(1)
		{
			if(vec[p].second != l) { acc += t; p = !p; }
			c = p;
			while(c < m && car[c].first <= acc && car[c].second == l) ++c;
			p += c;
			acc += t;
