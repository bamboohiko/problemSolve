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
const int maxn = 500;
int s[maxn + 10];
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(s,0,sizeof(s));
        int a,b,n,ans = 0;
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) {
            scanf("%d%d",&a,&b);
            s[a] += b;
        }
        for (int i = 1;i <= maxn; i++)
            if (s[i] > 0) ans += (s[i]-1)/64 + 1;
        if (ans > 0) printf("%d\n",(ans-1)/36+1);
        else printf("%d\n",ans);
    }
	return 0;
}

