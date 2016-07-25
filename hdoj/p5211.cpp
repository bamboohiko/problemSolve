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
const int INF = 10010;
int a[10100],loc[10100];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(loc,0,sizeof(loc));
		int maxn = INF;
		for (int i = 1;i <= n; i++) {
			scanf("%d",&a[i]);
			maxn = max(a[i],maxn);
		}
		int ans = 0;
		for (int i = n;i >= 1; i--) {
			int rec = INF;
			for (int j = 1;a[i]*j <= maxn; j++)
				if (loc[a[i]*j])
					rec = min(rec,loc[a[i]*j]);
			if (INF-rec) ans += rec;
			loc[a[i]] = i; 
		}
		//for (int i = 1;i <= n; i++) cout << loc[i] << " ";cout << endl;
		printf("%d\n",ans);
	}
	return 0;
}
