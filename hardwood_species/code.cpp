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

int
main()
{
	int t;
	double num;
	string line;
	scanf("%d", &t);
	getline(cin, line);
	getline(cin, line);
	while(t--)
	{
		mapa.clear();
		num = 0.;
		while(1)
		{
			getline(cin, line);
			if(line == "") break;
			if(!mapa.count(line)) mapa[line] = 1;
			else ++mapa[line];
			++num;
		}
		for(map<string, int>::iterator it = mapa.begin(); it != mapa.end(); ++it)
			printf("%s %.4lf\n", it->first.c_str(), (it->second*100.)/num);
		if(t) printf("\n");
	}
	return 0;
}

