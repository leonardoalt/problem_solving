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
#include <list>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

#define MAXN 100010

char line[MAXN];
list<string> lista;

int
main()
{
	string text, tmp;
	int p, i, l;
	while(scanf("%s", line) != EOF)
	{
		lista.clear();
		text = "";
		p = 1;
		i = 0;
		l = strlen(line);
		while(1)
		{
			tmp = "";
			while(i < l && line[i] != '[' && line[i] != ']')
			{
				tmp += line[i];
				++i;
			}
			if(p) lista.push_back(tmp);
			else lista.push_front(tmp);
			if(i >= l) break;
			if(line[i] == '[') p = 0;
			else p = 1;
			++i;
		}
		for(list<string>::iterator it = lista.begin(); it != lista.end(); ++it) printf("%s", it->c_str());
		printf("\n");
	}
	return 0;
}

