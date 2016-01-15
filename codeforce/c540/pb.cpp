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
vector<int> sav;
int a[1100];
int main()
{
	int n,k,p,x,y;
	scanf("%d%d%d%d%d",&n,&k,&p,&x,&y);
	n >>= 1;
	int sum = 0;
	for (int i = 1;i <= k; i++) {
		scanf("%d",&a[i]);
		sum += a[i];
	}
	sort(a+1,a+k+1);
	bool ans = true;
	int l,r;
	if (y < a[1]) {
		if (k > n) {
			l = n+n+1-k;r = 0;
		} else {
			l = n;r = 1 + n-k;
		}
	}
	if (y > a[k]) {
		if (k > n) {
			ans = false;
		} else {
			l = n-k;r = 1 + n;
		}
	}
	if (y >= a[1] && y <= a[k]) {
		for (int i = 1;i <= k; i++)
			if (y <= a[i]) {
				l = n - (i-1);
				r = n - (k-i+1) + 1;
				break;
			}
		if (l < 0) ans = false;
		if (r < 0) {l = n + n + 1-k; r = 0;}
	}
	if (sum + l + r*y > x) ans = false;
	if (!ans) printf("-1\n");
	else {
		for (int i = 1;i <= l; i++) sav.push_back(1);
		for (int i = 1;i <= r; i++) sav.push_back(y);
		for (int i = 0;i < sav.size()-1; i++) 
			printf("%d ",sav[i]);
		printf("%d\n",sav[sav.size()-1]);
	}
	return 0;
}
