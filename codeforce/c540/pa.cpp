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
int fig(char a,char b) {
	if (a < b) swap(a,b);
	return min(a - b,b + 10 - a);
}
int main()
{
	int n;
	string s1,s2;
	scanf("%d",&n);
	cin >> s1 >> s2;
	int ans = 0;
	for (int i = 0;i < n; i++)
		ans += fig(s1[i],s2[i]);
	printf("%d\n",ans);
	return 0;
}
