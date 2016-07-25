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
const int n = 1e6;
int f[100*n+10],tree[4*n+10];
int dfs(int k) {
	if (k > 100*n) 
		if (k%2) return dfs(3*k + 1) + 1;
		else return dfs(k/2) + 1;
	if (f[k]) return f[k];
	if (k%2) f[k] = dfs((3*k+1)/2) + 2;
	else f[k] = dfs(k/2) + 1;
	return f[k];
}
void build(int l,int r,int k) {
	if (l == r) {
		tree[k] = f[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l,mid,k+k);
	build(mid+1,r,k+k+1);
	f[k] = max(f[k+k],f[k+k+1]);
}
int query(int l,int r,int k,int x,int y) {
	if (x <= l && r <= y) {
		return tree[k];
	}
	int mid = (l + r) >> 1,t1 = 0,t2 = 0;
	if (x <= mid) t1 = query(x,mid,k+k,x,y);
	if (y > mid) t2 = query(mid+1,y,k+k+1,x,y);
	return max(t1,t2);
}
int main()
{
	f[1] = 1;
	for (int i = 2;i <= n; i++) {
		cout << i << endl;
		f[i] = dfs(i);
	}
	build(1,n,1);
	int l,r;
	while (scanf("%d%d",&l,&r) != EOF) 
		printf("%d %d %d\n",l,r,query(1,n,1,l,r));
	return 0;
}
