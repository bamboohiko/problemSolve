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
	double n,k = log(10);
	int ans;
	while (scanf("%d",&ans) != EOF) {
		n = ans;
		while (n*k > 10) {
			n /= 10;
			ans--;
		}	
		printf("%d\n",ans);
	}
	return 0;
}
