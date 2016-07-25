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
int a[1010];
int main()
{
	int n,r;
	while (scanf("%d%d",&n,&r) != EOF) {
	for (int i = 0;i < n; i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int ans = 0,d = -1e9,find = 0;
	for (int i = 0;i < n; i++) {
		if (!find) {
			if (a[i] > d) {
				d = a[i] + r;
				find = 1;
			}
		}
		else {
			if (a[i] > d) {
				ans++;
				//cout << i-1 << " ";
				d = a[i-1] + r;
				find = 0;
				i--;
			} 
		} 
		//cout << a[i]  << " " << find << endl;
	}
	printf("%d\n",ans + find);
	}
	return 0;
}
