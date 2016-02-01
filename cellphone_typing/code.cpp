#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

struct node
{
	node(char _c)
	{
		c = _c;
		nc = 0;
		f = false;
		fori(30) { chil[i] = NULL; }
	}

	char c;
	int nc;
	bool f;
	struct node* chil[30];
};

node* roots[30];

void
add_to_tree(string s)
{
	int cd = s[0]-'a';
	node* root = roots[cd];
	if(roots[cd] == NULL)
	{
		root = roots[cd] = new node(s[0]);
	}
	for(int i = 1; i < int(s.size()); ++i)
	{
		cd = s[i]-'a';
		if(root->chil[cd] != NULL)
		{
			root = root->chil[cd];
			continue;
		}
		root->chil[cd] = new node(s[i]);
		++root->nc;
		root = root->chil[cd];
	}
	root->f = true;
}

int
count_dig(string s)
{
	int ans = 1;
	int cd = s[0]-'a';
	node* root = roots[cd];
	for(int i = 1; i < int(s.size()); ++i)
	{
		cd = s[i]-'a';
		if(root->nc > 1 || root->f) ++ans;
		root = root->chil[cd];
	}

	return ans;
}

void
clean_dfs(node* root)
{
	fori(30)
	{
		if(root->chil[i] != NULL)
		{
			clean_dfs(root->chil[i]);
		}
	}
	free(root);
}

void
clean_tcs()
{
	fori(30)
	{
		if(roots[i] != NULL)
		{
			clean_dfs(roots[i]);
			roots[i] = NULL;
		}
	}
}

int
main()
{
	vector<string> v;
	string s;
	int sum, n;
	double ans;

	fori(30) { roots[i] = NULL; }

	while(scanf("%d", &n) != EOF)
	{
		v.clear();
		clean_tcs();
		fori(n)
		{
			cin >> s;
			v.push_back(s);
			add_to_tree(s);
		}

		sum = 0;
		fori(int(v.size()))
			sum += count_dig(v[i]);
		ans = double(sum) / int(v.size());
		printf("%.2lf\n", round(ans * 100.) / 100.);
	}

	return 0;
}

