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
int a[210];
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(a,0,sizeof(a));
        int n;
        scanf("%d",&n);
        int x,y;
        for (int i = 1;i <= n; i++) {
            scanf("%d%d",&x,&y);
            if (x > y) swap(x,y);
            x = (x+1) >> 1;y = (y + 1) >> 1;
            for (int j = x;j <= y; j++) a[j]++;
        }
        int ans = 0;
        for (int i = 1;i <= 200; i++)
            ans = max(ans,a[i]);
        printf("%d\n",ans*10);
    }
	return 0;
}
