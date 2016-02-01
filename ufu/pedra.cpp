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
f(string& s)
{
	if(s[0] == 't') return 0;
	if(s[1] == 'e') return 1;
	return 2;
}

int
main()
{
	int t, na, nb;
	string a, b;
	scanf("%d", &t);
	while(t--)
	{
		cin >> a >> b;
		na = f(a);
		nb = f(b);
		if(na == nb) printf("Empate\n");
		else
		{
			if(na == 0 && nb == 2) printf("Jogador 1\n");
			else if(na == 1 && nb == 0) printf("Jogador 1\n");
			else if(na == 2 && nb == 1) printf("Jogador 1\n");
			else printf("Jogador 2\n");
		}
	}
	return 0;
}

