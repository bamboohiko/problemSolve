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
int a[110][110];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int sum = n*(n/2);
	if (n%2 == 1) sum += (n >> 1)+1;
	if (sum < m) printf("NO\n");
	else {
		printf("YES\n");
		int k = 0;
		for (int i = 1;i <= n; i++) 
			for (int j = (i%2)?1:2;j <= n; j+=2)
				{
					if (k++ >= m) goto lambel;
					a[i][j] = 1;
				}
				lambel: ;
	for (int i = 1;i <= n; i++) {
		for (int j = 1;j <= n; j++) 
			if (a[i][j]) printf("L");
			else printf("S");
		printf("\n");
	}
	}
	return 0;
}
