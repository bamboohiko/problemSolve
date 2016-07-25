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
typedef long long LL;
set<LL> dic;
int main()
{
	int t,n;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		dic.clear();
		LL k;
		for (int i = 1;i <= n; i++) {
			scanf("%lld",&k);
			dic.insert(k);
		}
		printf("%d\n",dic.size());
	}
	return 0;
}
