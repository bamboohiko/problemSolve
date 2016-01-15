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
int cou[30];
char fig(char ch)
{
	if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 'a';
	return ch;
}
int main()
{
	memset(cou,0,sizeof(cou));
	int n,ans = 0;
	char ch;
	scanf("%d%*c",&n);
	for (int i = 1;i < n; i++)
	{
		ch = fig(getchar());
		cou[ch]++;
		ch = fig(getchar());
		if (cou[ch]) cou[ch]--;
		else ans++;
	}
	printf("%d\n",ans);
	return 0;
}
