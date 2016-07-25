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
	int n,t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		int ans = 0,len = 0,k;
		for (int i = 1;i <= n; i++) {
			scanf("%d",&k);
			if (!k) len++;
			else {
				ans = max(ans,len);
				len = 0;
			}
		}
		printf("%d\n",max(ans,len));
	}
	return 0;
}
