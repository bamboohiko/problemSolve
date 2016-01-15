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
int a[110][110];
int main()
{
    int n,x1,y1,x2,y2;
    scanf("%d",&n);
    for (int k = 1;k <= n; k++) {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for (int i = x1;i <= x2; i++)
            for (int j = y1;j <= y2; j++)
                a[i][j]++;
    }
    int ans = 0;
    for (int i = 1;i <= 100; i++)
        for (int j = 1;j <= 100; j++)
            ans += a[i][j];
    printf("%d\n",ans);
	return 0;
}
