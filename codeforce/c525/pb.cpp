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
int a[100100];
int main()
{
	string st;
	cin >> st;st = " " + st;
	int m,cou = 1;
	scanf("%d",&m);
	for (int i = 0;i < m; i++) 
		scanf("%d",&a[i]);
	sort(a,a+m);
	swap(st[a[0]],st[st.size()-a[0]]);
	for (int i = 1;i < m; i++)
	{
		int t = a[i];
		cou++;
		if (cou%2 == 0 && a[i] == a[i-1]) swap(st[t],st[st.size()-t]);
		if (cou%2 == 1 && a[i] != a[i-1]) swap(st[t],st[st.size()-t]);
	}
	if (cou%2)
		for (int i = a[m-1]+1;i <= (st.size() >> 1); i++)
			swap(st[i],st[st.size()-i]);
	for (int i = 1;i < st.size(); i++)
		printf("%c",st[i]);
	printf("\n");
	return 0;
}
