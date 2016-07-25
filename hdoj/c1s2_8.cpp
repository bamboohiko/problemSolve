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
int main()
{
	string st;
	int cou[30];
	while (getline(cin,st))
	{
		memset(cou,0,sizeof(cou));
		for (int i = 0;i < st.size(); i++)
		{
			if (st[i] >= 'a' && st[i] <= 'z')
				cou[st[i] - 'a']++;
		}
		for (int i = 'a';i <= 'z'; i++)
			printf("%c:%d\n",i,cou[i - 'a']);
		printf("\n");
	}
	return 0;
}
