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
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,maxv,k,ans = 0;
        scanf("%d%d",&n,&k);
        maxv = k-1;
        for (int i = 2;i <= n; i++) {
            scanf("%d",&k);
            ans = max(ans,k+i+maxv);
            maxv = max(maxv,k-i);
        }
        printf("%d\n",ans);
    }
	return 0;
}
