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

#define MAXN 10000

string dbg;
int N;
bool done;
int p;

int vec[MAXN+10];
int v1[MAXN+10];
int v2[MAXN+10];

int
checksum()
{
	long long r = 1;
	fori(N)
		r = (31 * r + (long long)vec[i]) % 1000003;
	return (int)r;
}

void
vprint(int *v, int l, int r)
{
	cout << "Vetor " << v << " de " << l << " a " << r << endl;
	for(int i = l; i <= r; ++i) cout << v[i] << ' ';
	cout << endl;
}

int
f(int l, int r)
{
	if(l >= r) return true;
	vprint(vec, l, r);
	int s = r - l + 1;
	int sf = s / 2;
	int p1, p2;
	int ap = p;
	bool suc;
	int bvec[MAXN+10];
	memcpy(&bvec[l], &vec[l], s * sizeof(int));
	cout << "vetor backup" << endl;
	vprint(bvec, l, r);
	for(int i = r-1; i >= l + sf - 1; --i)
	{
		//tentar todas possibilidades de montar v1 e v2 com |v1| = sf
		p = ap;
		p1 = p2 = r;
		memcpy(&vec[l], &bvec[l], s * sizeof(int));
		vprint(vec, l, r);
		cout << "Testando " << vec[i] << " com p = " << p << endl;
		if(dbg[p--] == '1')
		{
			v1[p1--] = vec[i];
			for(int j = r; j > i; --j) v2[p2--] = vec[j];
		}
		else //if(dbg[p] == '2')
		{
			v2[p2--] = vec[i];
			for(int j = r; j > i; --j) v1[p1--] = vec[j];
		}
                vprint(v1, p1+1, r);
                                vprint(v2, p2+1, r);
                                		suc = true;
		for(int j = i - 1; j >= l; --j)
		{
			if(p < 0) { suc = false; break; }
			if((r - p1) > sf) { suc = false; break; }
			if(dbg[p] == '1') v1[p1--] = vec[j];
			else //if(dbg[ap] == '2')
				v2[p2--] = vec[j];
			--p;
		}
		if(!suc) continue;
		if((r - p1) > sf) continue; //really necessary?
		memcpy(&vec[l], &v1[p1+1], (r - p1) * sizeof(int));
		memcpy(&vec[l+sf], &v2[p2+1], (r - p2) * sizeof(int));
		cout << "conseguiu separar v1 e v2" << endl;
		vprint(v1, p1+1, r);
		vprint(v2, p2+1, r);
		cout << "juntando de novo no vetor original:"<< endl;
		vprint(vec, l, r);
		cout << "L = " << l << " SF = " << sf << " R = " << r << endl;
		cout << "chamando rec pra direita" << endl;
		if(!f(l + sf, r)) continue;
		cout << "deu certo" << endl;
		cout << "chamando rec pra esquerda" << endl;
		if(!f(l, l + sf - 1)) continue;
		cout << "deu certo" << endl;
		if(!f(0, l-1)) continue;
		return true;
	}
	p = ap;
	memcpy(&vec[l], &bvec[l], s * sizeof(int));
	return false;
}

int
main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &N);
		cin >> dbg;
		fori(N) vec[i] = i + 1;
		done = false;
		p = int(dbg.size()) - 1;
		f(0, N-1);
		fori(N) cout << vec[i] << ' ';
		cout << endl;
		printf("%d\n", checksum());
	}
	return 0;
}

