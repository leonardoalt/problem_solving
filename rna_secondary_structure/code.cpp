#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <climits>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

int p10[] = {1, 10, 100, 1000};

#define MAXN 160
#define MAXK 30

int dp[MAXN][MAXN][MAXK];

string rna;
int K;

bool
close(char c0, char c1)
{
	if(c0 > c1) swap(c0, c1);
	if(c0 == 'C' && c1 == 'G') return true;
	if(c0 == 'A' && c1 == 'U') return true;
	return false;
}

int
preproc(string s)
{
	stringstream ss(s);
	vector<int> f;
	string allnuc = "";
	char nuc;
	int c, L = 0;
	while(ss >> nuc)
	{
		allnuc += nuc;
		ss >> c;
		f.push_back(c);
		L += c;
	}
	int n = f.size();
	if(n == 1) return 0;

	L -= f[0] + f[n-1];
	int pre = 0;
	if(close(allnuc[0], allnuc[n-1]))
	{
		int p = min(f[0], f[n-1]);
		if(allnuc[0] == 'C' || allnuc[0] == 'G')
		{
			p = min(p, K);
			K -= p;
		}
		pre += p;
		f[0] -= p;
		f[n-1] -= p;
	}

	f[0] = min(f[0], L);
	f[n-1] = min(f[n-1], L);

	rna = "";
	fori(n) forj(f[i]) rna += allnuc[i];

	return pre;
}

int
func(int l, int r, int k)
{
	if(l >= r) return 0;

        int& ans = dp[l][r][k];
        if(ans >= 0) return ans;

	ans = func(l+1, r, k);

	if(rna[l] == 'C' || rna[l] == 'G') k--;
	if(k < 0) return ans;

	for(int i = l + 1; i <= r; ++i)
	{
		if(!close(rna[l], rna[i])) continue;
		for(int w = 0; w <= k; ++w) ans = max(ans, func(l + 1, i - 1, w) + 1 + func(i + 1, r, k - w));
	}

	return ans;
}

int
main()
{
	string s;
	int n, ca=0, t, ans;

	scanf("%d", &t);
	while(t--)
	{
		cin >> s >> K;
		ans = preproc(s);
		n = int(rna.size());
		memset(dp, -1, sizeof(dp));
		ans += func(0, n-1, K);
		printf("Case %d: %d\n", ++ca, ans);
	}
	return 0;
}

