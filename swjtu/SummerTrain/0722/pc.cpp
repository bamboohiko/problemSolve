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
int a[10100],f[10100];
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        int ans = 0;
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            if (!a[i]) f[i] = f[i-1] + 1;
            else f[i] = 0;
            ans = max(ans,f[i]);
        }
        printf("%d\n",ans);
    }
	return 0;
}
