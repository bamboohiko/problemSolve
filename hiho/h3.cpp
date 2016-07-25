//×Ö·û´®Æ¥Åä£ºKMPËã·¨ 
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
char a[1000000 + 10],b[10000 + 10];
int next[10000 + 10];
int main()
{
	int n;
	scanf("%d",&n);
	a[0] = b[0] = '0';
	while (n--)
	{
		scanf("%s",b+1);
		scanf("%s",a+1);
		int l1 = strlen(a),l2 = strlen(b);
		next[0] = -1;next[1] = 0;
		for (int i = 2;i < l2; i++)
		{
			int j = next[i-1];
			while (j >= 0 && b[j+1] != b[i]) j = next[j];
			next[i] = j+1;
		}
		int j = 0,ans = 0;
		for (int i = 1;i < l1; i++)
		{
			while (j >= 0 && b[j+1] != a[i]) j = next[j];
			++j;
			if (j+1 == l2) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
