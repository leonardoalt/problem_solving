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

long long
s2i(string s)
{
	long long n;
	stringstream ss(s);
	ss >> n;
	return n;
}

int
main()
{
	int t, i;
	long long n0, n1, ans;
	char op, c;
	bool neg0, neg1;
	string s0, s1, s;
	scanf("%d", &t);
	printf("Modulo 642 - Projeto SNALT\n");
	while(t--)
	{
		cin >> s;
		s0 = s1 = "";
		neg0 = neg1 = false;
		if(s[0] == '-' || s[0] == '+')
		{
			i = 1;
			if(s[0] == '-') neg0 = true;
		}
		else i = 0;
		for(; i < int(s.size()); ++i)
		{
			c = s[i];
			if(c == '+' || c == '-' || c == '/' || c == '*') break;
			s0 += c;
		}
		op = s[i++];
		if(s[i] == '-' || s[i] == '+')
		{
			++i;
			if(s[i-1] == '-') neg1 = true;
		}
		for(; i < int(s.size()); ++i) s1 += s[i];
		n0 = s2i(s0);
		if(neg0) n0 *= -1;
		n1 = s2i(s1);
		if(neg1) n1 *= -1;
		if(op == '+') ans = n0 + n1;
		else if(op == '-') ans = n0 - n1;
		else if(op == '*') ans = n0 * n1;
		else ans = n0 / n1;
		printf("%lld\n", ans);
		if(t > 0) printf("\n");
	}
	printf("Fim do modulo 642\n");
	return 0;
}

