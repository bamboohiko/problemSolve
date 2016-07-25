#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;
bool a[1010][1010];
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        memset(a,false,sizeof(a));
        int from,to;
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&from,&to);
            a[from][to] = a[to][from] = true;
        }
        int ans = 0;
        for (int i = 1;i <= n; i++) {
            int k = 0;
            for (int j = 1;j <= n; j++)
                if (a[i][j]) k++;
            ans += k*(n-1-k);
        }
        ans = n*(n-1)*(n-2)/6 - ans/2;
        printf("%d\n",ans);
    }
	return 0;
}
