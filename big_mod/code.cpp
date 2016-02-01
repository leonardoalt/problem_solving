#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll
mod_exp(int b, int e, int m)
{
        ll res = 1;
        while(e > 0)
        {
                if(e & 1) res = (res * b) % m; e >>= 1; b = ((ll) b * b) % m;
        }
        return res;
}

int
main()
{
	ll b, e, m;
	while(scanf("%lld %lld %lld", &b, &e, &m) != EOF) printf("%lld\n", mod_exp(b, e, m));
	return 0;
}

