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
	int n,t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		for (int i = 1;i < n; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			build(x,y);
			build(y,x);
		}
		scanf("%d",&q);
		for (int i = 1;i <= q; i++) {
			scanf("%d",&com[i][0]);
			fi (com[i][0]) {
				scanf("%d%d",&com[i][1],&com[i][2]);
				com[i][1] = com[i][2];
			}
		}
	}
	return 0;
}
