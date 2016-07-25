#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
vector<int> v[1010];
int n;
void find_blocks(int t,int& x,int& y)
{
	for (int i = 0;i < n; i++)
		for (int j = 0;j < v[i].size(); j++)
			if (v[i][j] == t)
				{x = i;y = j;
				return;
				}
}
void clear_above(int x,int y)
{int t;
	for (int i = y+1;i < v[x].size(); i++)
		{t = v[x][i];
		v[t].push_back(t);
		}
	v[x].resize(y+1);	
}
void pile(int x,int y,int b)
{
	for (int j = y;j < v[x].size(); j++)
		v[b].push_back(v[x][j]);
	v[x].resize(y);
}
int main()
{freopen("test.in","r",stdin);
 freopen("test.out","w",stdout);
 int a,b;
 string s1,s2;
	cin >> n;
	for (int i = 0;i < n; i++) v[i].push_back(i);
	while (cin >> s1 >> a >> s2 >> b)
		{int xa,ya,xb,yb;
		 find_blocks(a,xa,ya);
		 find_blocks(b,xb,yb);
		if ( s1 == "move" ) clear_above(xa,ya);
		if ( s2 == "onto" ) clear_above(xb,yb);
		pile(xa,ya,xb);
		}	
	for (int i = 0;i < n; i++)
		{cout << i << ":";
		for (int j = 0;j < v[i].size(); j++)
			cout << " " << v[i][j];
		cout << endl;
		}
	return 0;
}

