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
int cmp(int a,int b) {
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}
int main()
{
	int t,n,m;
	scanf("%d",&t);
	for (int ca = 1; ca <= t; ca++) {
		scanf("%d%d",&n,&m);
		long long ans = n;
		int len = 1,sta = 0,p = 0;   
		for (int i = 1;i <= n; i++) {
			scanf("%d",&a[i]);
			if (cmp(a[i],a[i-1]) == sta) len++;
			else {
				if (sta) ans += len*(len-1)/2;
				len = 1;
				sta = cmp(a[i],a[i-1]);
			}
			cout << len << " ";
		}
		cout << endl;
		if (sta) ans += len*(len-1)/2;
		printf("Case #%d: %lld\n",ca,ans*m);
	}
	return 0;
}
