#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct point{
	int ed;
	int son[3];
};
point trie[3000100];
int sum = 0;
string st;
void build()
{
	int s = 0;
	for (int i = 0;i < st.size(); i++)
	{
		if (!trie[s].son[st[i] - 'a']) trie[s].son[st[i] - 'a'] = ++sum;
		s = trie[s].son[st[i] - 'a'];
	}
	trie[s].ed = 1;
}
bool find(int s,int k,int c)
{
	bool ans = false;
	if (k >= st.size())
		if  (trie[s].ed) return true;
		else return false;
	if (c > 0) 
	{
		for (int i = 0;i < 3; i++)
			if (trie[s].son[i]) 
			{				
 				if ('a' + i == st[k]) ans = find(trie[s].son[i],k+1,c);
				else ans = find(trie[s].son[i],k+1,c-1);
				if (ans) break;
			}
	}
	else
		if (trie[s].son[st[k] - 'a']) ans = find(trie[s].son[st[k] - 'a'],k+1,c);
		else ans = false; 
	return ans;
}
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		sum = 0;
		memset(trie,0,sizeof(trie));
		for (int i = 1;i <= n; i++)
		{
			cin >> st;
			build();	
  		}
		for (int i = 1;i <= m; i++)
		{
			cin >> st;
			if (find(0,0,1)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
