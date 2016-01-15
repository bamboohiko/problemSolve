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
	int n,k,sum = 0;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int ans = n;
	for (int i = 0; i < n; i++) {
		if (sum > a[i]) ans--;
		else sum += a[i];
	}
	printf("%d\n",ans);
	return 0;
}
