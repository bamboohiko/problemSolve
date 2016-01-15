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
const int INF = 1e9;
int x[100100],h[100100],f[100100][3];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1;i <= n; i++) 
		scanf("%d%d",&x[i],&h[i]);
	f[1][0] = f[1][1] = f[1][2] = 1;
	for (int i = 2;i <= n; i++) {
		int k = x[i] - x[i-1];
		f[i][0] = max(max(f[i-1][0],f[i-1][1]),(k > h[i-1])?f[i-1][2]:0);
		f[i][1] = max((k > h[i])?(max(f[i-1][0],f[i-1][1])+1):0,(k > h[i]+h[i-1])?(f[i-1][2]+1):0);
		f[i][2] = max(max(f[i-1][0],f[i-1][1])+1,(k > h[i-1])?(f[i-1][2]+1):0);
	}
	printf("%d\n",f[n][2]);
	return 0;
}
