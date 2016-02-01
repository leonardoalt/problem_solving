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
#include <queue>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

typedef long long lala;

lala
doit(lala n)
{

	bool visited[9999+100];
	lala c = 0;
	memset(visited, false, sizeof(visited));
	while(1)
	{
		if(visited[n])
			return c;
		visited[n] = true;
		n = ((n * n) % 1000000) / 100;
		++c;
	}
}

int
main()
{
	lala n;
//	while(1)
cout << "long long ans[9999] = {";
for(n=1;n<10000;++n)
	{
//		cin >> n;
//		if(!n) break;

		cout << doit(n) << ",";
	}
cout << endl;
	return 0;
}
