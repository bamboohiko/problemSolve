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
	int t,n;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		int d = sqrt(n);
		while (n%d) d--;
		printf("%d\n",2*(d + n/d));
	}
	return 0;
} 
