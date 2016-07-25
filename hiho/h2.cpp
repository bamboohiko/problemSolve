#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct word{
	int sum;
	int next[26];
};
vector<word> trie;
string st;
int area()
{
	word one;
	one.sum = 0;
	memset(one.next,0,sizeof(one.next));
	trie.push_back(one);
	return trie.size()-1;
}
void build(int loc,int k)
{
	trie[loc].sum++;	
	if (k == st.length()) return;
	int pch = st[k] - 'a';
	if (!trie[loc].next[pch]) 
		{
		int rec = area();
		trie[loc].next[pch] = rec;
		}
	build(trie[loc].next[pch],k+1);
}
int dfs(int loc,int k)
{
	if (k == st.length()) return trie[loc].sum;
	int pch = st[k] - 'a';
	if (!trie[loc].next[pch]) return 0;
	else return dfs(trie[loc].next[pch],k+1);
}
int main()
{int n,m;
	cin >> n;
	area();
	for (int i = 1;i <= n; i++)
		{cin >> st;
		build(0,0);
		}
	cin >> m;
	for (int i = 1;i <= m; i++)
		{cin >> st;
		cout << dfs(0,0) << endl;
		}
	return 0;
}
