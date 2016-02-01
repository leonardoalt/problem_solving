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

#define MAXL 5
#define MAXP 1300

int pots[] = {1, 4, 16, 64, 256, 1024, 4096};

struct quad
{
	quad()
	{
		c[0] = c[1] = c[2] = c[3] = NULL;
		f = false;
		par = true;
	}
	struct quad* c[4];
	bool f;
	bool par;
};

string s;
int p;

bool ans0[MAXP];
bool ans1[MAXP];

struct quad*
parse()
{
	quad* root = new quad();
	if(s[p] == 'f')
	{
		root->f = true;
		root->par = false;
	}
	else if(s[p] == 'e')
	{
		root->f = false;
		root->par = false;
	}
	else
	{
		root->par = true;
		fori(4)
		{
			++p;
			root->c[i] = parse();
		}
	}
	return root;
}	

int
count(quad* root, int d)
{
	if(root->par == false)
		return root->f * pots[MAXL - d];
	int acc = 0;
	fori(4)
	{
		acc += count(root->c[i], d + 1);
	}
	return acc;
}

int lcount;
bool ans;

void
complete(quad* root, int d)
{
	if(d == MAXL)
	{
		if(root->par)
			root->par = false;
		if(!ans) ans0[lcount++] = root->f;
		else ans1[lcount++] = root->f;
		return;
	}

	if(root->par)
	{
		fori(4)
			complete(root->c[i], d + 1);
	}
	else
	{
		root->par = true;
		fori(4)
		{
			root->c[i] = new quad();
			root->c[i]->par = false;
			root->c[i]->f = root->f;
			complete(root->c[i], d + 1);
		}
	}
}

quad*
merge(quad* root0, quad* root1)
{
	if(!root0->par && !root1->par) //both are leaves
	{
		if(root0->f) return root0;
		return root1;
	}
	else if(!root1->par)
	{
		if(root1->f) return root1;
		return root0;
	}
	else if(!root0->par)
	{
		if(root0->f) return root0;
		return root1;
	}
	else
	{
		fori(4)
		{
			root0->c[i] = merge(root0->c[i], root1->c[i]);
		}
		return root0;	
	}
}

int
main()
{
	int n, sum;
	string s0, s1;
	quad *r0, *r1;

	cin >> n;
	while(n--)
	{
		cin >> s0 >> s1;

		s = s0;
		p = 0;
		r0 = parse();
		s = s1;
		p = 0;
		r1 = parse();
		//memset(ans0, false, sizeof(ans0));
		//memset(ans1, false, sizeof(ans1));
		//lcount = 0;
		//ans = 0;
		//complete(r0, 0);
		//lcount = 0;
		//ans = 1;
		//complete(r1, 0);
		
		//sum = 0;
		//fori(lcount)
			//if(ans0[i] || ans1[i]) ++sum;
		
		r0 = merge(r0, r1);
		sum = count(r0, 0);
		cout << "There are " << sum << " black pixels." <<  endl;

	}
}

