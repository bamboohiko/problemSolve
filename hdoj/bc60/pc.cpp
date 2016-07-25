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
int a[310];
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,m,l,k;
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&l);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&m);
            for (int i = 1;i <= m; i++) {
                scanf("%d",&k);
                a[k]++;
            }
        }
        bool ans = false;
        for (int i = 1;i <= 300; i++) {
            if (a[i] >= l) {
                ans = true;
                break;
            }
        }
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}

