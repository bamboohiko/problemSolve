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
set<int> dic;
int main()
{
	int n;
	while (scanf("%d",&n) != EOF) {
		dic.clear();
		int k,sum = 0;
		for (int i = 1;i <= n; i++) {
			scanf("%d",&k);
			if (!dic.count(k)) dic.insert(k);
			else sum++;
		}
		scanf("%d",&k);
		printf("%d\n",dic.size() - max(k-sum,0));
	}
	return 0;
}
