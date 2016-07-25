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
	int n,k,ans = 0;
	scanf("%d",&n);
	for (int i = 0;i < n; i++) {
		scanf("%d",&k);
		ans ^= k;
	}
	if (!ans) printf("Bob\n");
	else printf("Alice\n");
	return 0;
}
