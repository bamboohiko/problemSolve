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
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,m;
        scanf("%d%d",&n,&m);
        int x,ans = 0;
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= m; j++) {
                scanf("%d",&x);
                if (x) ans++;
            }
        printf("%d\n",ans);
    }
	return 0;
}


