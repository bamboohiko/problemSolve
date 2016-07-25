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
int a[110];
int main() {
    int n,b,c;
    while (scanf("%d",&n) != EOF) {
        scanf("%d%d",&b,&c);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        int ans = 0;
        for (int i = 1;i < n; i++)
            for (int j = i+1;j <= n; j++)
                if (abs(a[j]-a[i])%b == c) ans++;
        printf("%d\n",ans);
    }
	return 0;
}
