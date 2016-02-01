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
#include <bitset>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

typedef long long ll;

ll _sieve_size;
bitset<10000010> bs;
vector<int> primes;
map<int, int> mapa;

void
sieve(ll upperbound)
{
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= _sieve_size; ++i)
	{
		if(bs[i])
		{
			for(ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
			primes.push_back((int)i);
		}
	}
}

void
primefactors(ll n)
{
	ll pf_idx = 0, pf = primes[pf_idx];
	while(n != 1 && (pf * pf <= n))
	{
		while(n % pf == 0)
		{
			n /= pf;
			if(mapa.count(pf)) ++mapa[pf];
			else mapa[pf] = 1;
		}
		pf = primes[++pf_idx];
	}
	if(n != 1) mapa[n] = 1;
}

ll
nofdivs(ll n)
{
	mapa.clear();
	ll m = 1;
	primefactors(n);
	for(map<int, int>::iterator it = mapa.begin(); it != mapa.end(); ++it) m *= it->second + 1;
	return m;
}

int
main()
{
	ll t, n, m;
	sieve(1000000);
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld %lld", &n, &m);
		ll ans = 0, pans;
		for(ll i = n; i <= m; ++i)
		{
			ll x = nofdivs(i);
			if(x > ans)
			{
				ans = x;
				pans = i;
			}
		}
		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", n, m, pans, ans);
	}
	return 0;
}

