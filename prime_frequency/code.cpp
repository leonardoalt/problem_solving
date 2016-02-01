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

#define MAXN 2010

bool isp[MAXN];
int freq[200];


bool
isprime(int n)
{
	for(int i = 2; i <= sqrt(n); ++i)
	{
		if((n % i) == 0) return false;
	}
	return true;
}

int
main()
{
	int t, ca=0;
	string s, ans;
	memset(isp, false, sizeof(isp));
	for(int i = 2; i <= 2001; ++i) if(isprime(i)) isp[i] = true;

	scanf("%d", &t);
	while(t--)
	{
		memset(freq, 0, sizeof(freq));
		cin >> s;
		fori(int(s.size())) ++freq[int(s[i])];
		ans = "";
		for(int i = 48; i <= 122; ++i) if(isp[freq[i]]) ans += char(i);
		printf("Case %d: ", ++ca);
		if(ans == "") printf("empty\n");
		else cout << ans << '\n';
	}

	return 0;
}

