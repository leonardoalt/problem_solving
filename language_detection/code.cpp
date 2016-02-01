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

map<string, string> mapa;

int
main()
{
	int ca = 0;
	string s;
	mapa["HELLO"] = "ENGLISH";
	mapa["HOLA"] = "SPANISH";
	mapa["HALLO"] = "GERMAN";
	mapa["BONJOUR"] = "FRENCH";
	mapa["CIAO"] = "ITALIAN";
	mapa["ZDRAVSTVUJTE"] = "RUSSIAN";
	while(1)
	{
		cin >> s;
		if(s[0] == '#') break;
		printf("Case %d: ", ++ca);
		if(mapa.count(s)) printf("%s\n", mapa[s].c_str());
		else printf("UNKNOWN\n");
	}
	return 0;
}

