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

void
gaussian_elimination(vector< vector< double > >& a, vector<double>& b)
{
	int i, j, k, l, maxi, n;
	double f, aux;

	n = a.size();
	for(i = 0; i < n; ++i)
	{
		maxi = i;
		for(l = i; l < n; ++l)
			if(fabs(a[l][i]) > fabs(a[maxi][i])) maxi = l;

		for(l = 0; l < n; ++l) swap(a[i][l], a[maxi][l]);
		aux = b[i], b[i] = b[maxi], b[maxi] = aux;
		for(k=i+1; k<n; ++k)
		{
			f = a[k][i] / a[i][i];
			for(j=i; j<n; ++j) a[k][j] -= a[i][j] * f;
			b[k] -= b[i] * f;
		}
	}

	for(i=n-1; i>= 0; --i)
	{
		b[i] = b[i] / a[i][i]; a[i][i] = 1.0;
		for(j=i-1; j >= 0; --j)
			b[j] -= a[j][i] * b[i], a[j][i] = 0.0;
	}
}

int
main()
{
	int n;
	double x;
	vector< vector< double > > eqs;
	vector<double> ans;
	cin >> n;
	fori(n)
	{
		eqs.push_back(vector<double>());
		forj(n)
		{
			cin >> x;
			eqs[i].push_back(x);
		}
		cin >> x;
		ans.push_back(x);
	}
	gaussian_elimination(eqs, ans);
	fori(n) cout << "x" << i << " = " << ans[i] << '\n';
}

