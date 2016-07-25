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
int a[210],f[210][210][210];
int pow(int k) {
	return k*k;
}
int dfs(int l,int r,int k) {
	if (f[l][r][k]) return f[l][r][k];
	if (l > r) return 0;
	int p = l;
	for (int i = r;i > l; i--)
		if (a[i] != a[i-1]) {
			p = i;
			break;
		}
	f[l][r][k] = dfs(l,p-1,0) + pow(k + r-p+1);
	for (int i = p-1;i > l; i--)
		if (a[i] != a[i-1] && a[i-1] == a[r])
			f[l][r][k] = max(f[l][r][k],dfs(l,i-1,k+r-p+1) + dfs(i,p-1,0));
	//cout << l << " " << r << " " << k << " " << f[l][r][k] << endl;
	return f[l][r][k];
}
int main()
{
	int t,ca;
	scanf("%d",&t);
	for (int ca = 1;ca <= t; ca++) {
		int n;
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for (int i = 1;i <= n; i++) 
			scanf("%d",&a[i]);
		printf("Case %d: %d\n",ca,dfs(1,n,0));
	}
	return 0;
}
